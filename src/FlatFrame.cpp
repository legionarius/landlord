//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	mainContainer = cast_to<Sprite>(get_node("Container/Background"));
	flatName = cast_to<Label>(get_node("Container/Background/FlatNameBackground/FlatName"));
	healthGauge = cast_to<ProgressBar>(get_node("Container/Background/HealthBackground/HealthProgressBar"));
	rent = cast_to<Label>(get_node("Container/Background/RentBackground/Rent"));
	animation = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	audio = cast_to<AudioStreamPlayer>(get_node("AudioStreamPlayer"));
	actionContainer = cast_to<GridContainer>(get_node("Container/ActionsContainer"));
	exitButton = cast_to<TextureButton>(get_node("Container/ExitButton"));
	tenantIdentityCard = cast_to<TenantIdentityCard>(get_node("Container/TenantCard"));

	exitButton->connect("pressed", this, "_on_exitButton_pressed");
	connect(POPUP_ABOUT_TO_SHOW, this, "_on_pre_show");
	flatsManager->connect(ACTION_COUNT, this, "_on_action_count");
	animation->connect("animation_finished", this, "_flat_is_displayed");
}

void FlatFrame::_on_pre_show() {
	connect(SIGNAL_REPAIR_FLAT, flatsManager, "queue_repair_flat");
	connect(SIGNAL_FIRE_TENANT, flatsManager, "queue_fire_tenant");
	connect(SIGNAL_MOVE_IN_TENANT, flatsManager, "queue_move_in_tenant");

	if (tenant != nullptr) {
		tenantIdentityCard->set_tenant(tenant);
		tenantIdentityCard->update_display();
		tenantIdentityCard->show();
	} else {
		tenantIdentityCard->hide();
	}
	_toggle_fire_tenant_button(tenant != nullptr);
	_toggle_move_in_tenant_button(tenant == nullptr);
	_toggle_repair_flat_button(tenant == nullptr);
	if (!flatsManager->can_add_action()) {
		// Forcing action button disabling
		_on_action_count(0, 0);
	} else {
		_on_action_count(0, 1);
	}

	audio->play();
	animation->play("open");
	emit_signal(START_OPEN_FLAT_DETAIL);

	flatName->set_text(flatNameLabel);
	rent->set_text(rentLabel);
	healthGauge->set_value(healthLabel);
}

void FlatFrame::_set_flat(Node *item) {
	flat = item;
}

void FlatFrame::_set_flat_label(real_t id) {
	std::stringstream nameString;
	nameString << "flat N " << id;
	flatId = id;
	flatNameLabel = nameString.str().c_str();
}

void FlatFrame::_set_health(real_t health) {
	std::stringstream healthString;
	healthString << health;
	healthLabel = health;
}

void FlatFrame::_set_rent(real_t rent) {
	std::stringstream rentString;
	rentString << "$" << std::fixed << std::setprecision(2) << rent;
	rentLabel = rentString.str().c_str();
}

void FlatFrame::_set_tenant(TenantIdentityCard::Tenant *tenant) {
	this->tenant = tenant;
}

void FlatFrame::_on_exitButton_pressed() {
	hide();
	disconnect(SIGNAL_REPAIR_FLAT, flatsManager, "queue_repair_flat");
	disconnect(SIGNAL_FIRE_TENANT, flatsManager, "queue_fire_tenant");
	disconnect(SIGNAL_MOVE_IN_TENANT, flatsManager, "queue_move_in_tenant");
	flat = nullptr;
}

void FlatFrame::_on_move_in_pressed() {
	TextureButton *moveInButton = cast_to<TextureButton>(actionContainer->get_node("MoveInButton"));
	if (!moveInButton->is_pressed()) {
		emit_signal(SIGNAL_MOVE_IN_TENANT, moveInButton->is_pressed(), flatId, 0);
	} else {
		Ref<PackedScene> tenantSelectorScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantSelector.tscn");
		TenantSelector *tenantSelector = Object::cast_to<TenantSelector>(tenantSelectorScene->instance());
		tenantSelector->set_name("TenantSelector");
		tenantSelector->connect(NEW_TENANT_SELECTED, this, "_on_tenant_selected");
		tenantSelector->connect(EXIT_TENANT_SELECTOR, this, "_exit_tenant_selector");
		add_child(tenantSelector);
	}
}

void FlatFrame::_exit_tenant_selector() {
	TextureButton *moveInButton = cast_to<TextureButton>(actionContainer->get_node("MoveInButton"));
	moveInButton->set_pressed(false);
	Node *tenantSelector = get_node("TenantSelector");
	tenantSelector->queue_free();
}

void FlatFrame::_on_tenant_selected(uint64_t tenantId) {
	Node *tenantSelector = get_node("TenantSelector");
	tenantSelector->queue_free();
	TextureButton *moveInButton = cast_to<TextureButton>(actionContainer->get_node("MoveInButton"));
	emit_signal(SIGNAL_MOVE_IN_TENANT, moveInButton->is_pressed(), flatId, tenantId);
}

void FlatFrame::_on_fire_pressed() {
	TextureButton *fireButton = cast_to<TextureButton>(actionContainer->get_node("FireButton"));
	emit_signal(SIGNAL_FIRE_TENANT, fireButton->is_pressed(), flatId);
}

void FlatFrame::_on_repair_pressed() {
	TextureButton *repairButton = cast_to<TextureButton>(actionContainer->get_node("RepairButton"));
	emit_signal(SIGNAL_REPAIR_FLAT, repairButton->is_pressed(), flatId);
}

void FlatFrame::_toggle_fire_tenant_button(bool enabled) const {
	if (enabled) {
		if (!actionContainer->has_node("FireButton")) {
			auto resourceLoader = ResourceLoader::get_singleton();
			Ref<Texture> actionIcon = resourceLoader->load(ActionFireTenant::iconPath.c_str());
			Ref<Texture> actionIconSelected = resourceLoader->load(ActionFireTenant::iconPathSelected.c_str());
			Ref<PackedScene> actionButtonRes = resourceLoader->load("entity/FlatFrame/ActionButton.tscn");
			auto fireButton = cast_to<TextureButton>(actionButtonRes->instance());

			fireButton->set_tooltip("Click to fire tenant");
			fireButton->set_name("FireButton");
			fireButton->set_normal_texture(actionIcon);
			fireButton->set_pressed_texture(actionIconSelected);
			fireButton->connect(BTN_PRESSED, this, "_on_fire_pressed");
			fireButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_FIRE_TENANT));
			actionContainer->add_child(fireButton);
		} else {
			auto fireButton = cast_to<TextureButton>(actionContainer->get_node("FireButton"));
			fireButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_FIRE_TENANT));
		}
	} else {
		if (actionContainer->has_node("FireButton")) {
			auto fireButton = actionContainer->get_node("FireButton");
			actionContainer->remove_child(fireButton);
		}
	}
}

void FlatFrame::_toggle_move_in_tenant_button(bool enabled) const {
	if (enabled) {
		if (!actionContainer->has_node("MoveInButton")) {
			auto resourceLoader = ResourceLoader::get_singleton();
			Ref<Texture> actionIcon = resourceLoader->load(ActionMoveInTenant::iconPath.c_str());
			Ref<Texture> actionIconSelected = resourceLoader->load(ActionMoveInTenant::iconPathSelected.c_str());
			Ref<PackedScene> actionButtonRes = resourceLoader->load("entity/FlatFrame/ActionButton.tscn");
			auto moveInButton = cast_to<TextureButton>(actionButtonRes->instance());

			moveInButton->set_tooltip("Click to rent to a new tenant");
			moveInButton->set_name("MoveInButton");
			moveInButton->set_normal_texture(actionIcon);
			moveInButton->set_pressed_texture(actionIconSelected);
			moveInButton->connect(BTN_PRESSED, this, "_on_move_in_pressed");
			moveInButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_MOVE_IN_TENANT));
			actionContainer->add_child(moveInButton);
		} else {
			auto moveInButton = cast_to<TextureButton>(actionContainer->get_node("MoveInButton"));
			moveInButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_MOVE_IN_TENANT));
		}
	} else {
		if (actionContainer->has_node("MoveInButton")) {
			auto moveInButton = actionContainer->get_node("MoveInButton");
			actionContainer->remove_child(moveInButton);
		}
	}
}

void FlatFrame::_toggle_repair_flat_button(bool enabled) const {
	if (enabled) {
		if (!actionContainer->has_node("RepairButton")) {
			auto resourceLoader = ResourceLoader::get_singleton();
			Ref<Texture> actionIcon = resourceLoader->load(ActionRepairFlat::iconPath.c_str());
			Ref<Texture> actionIconSelected = resourceLoader->load(ActionRepairFlat::iconPathSelected.c_str());
			Ref<PackedScene> actionButtonRes = resourceLoader->load("entity/FlatFrame/ActionButton.tscn");
			auto repairButton = cast_to<TextureButton>(actionButtonRes->instance());

			repairButton->set_tooltip("Click to repair flat");
			repairButton->set_name("RepairButton");
			repairButton->set_normal_texture(actionIcon);
			repairButton->set_pressed_texture(actionIconSelected);
			repairButton->connect(BTN_PRESSED, this, "_on_repair_pressed");
			repairButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_REPAIR_FLAT));
			actionContainer->add_child(repairButton);
		} else {
			auto repairButton = cast_to<TextureButton>(actionContainer->get_node("RepairButton"));
			repairButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_REPAIR_FLAT));
		}
	} else {
		if (actionContainer->has_node("RepairButton")) {
			auto moveInButton = actionContainer->get_node("RepairButton");
			actionContainer->remove_child(moveInButton);
		}
	}
}

void FlatFrame::_on_action_count(int current, int max) {
	if (current == max) {
		Array children = actionContainer->get_children();
		for (size_t i = 0; i < children.size(); i++) {
			auto button = cast_to<TextureButton>(children[i]);
			if (button != nullptr && !button->is_pressed()) {
				button->set_disabled(true);
			}
		}
	} else {
		Array children = actionContainer->get_children();
		for (size_t i = 0; i < children.size(); i++) {
			auto button = cast_to<TextureButton>(children[i]);
			if (button != nullptr) {
				button->set_disabled(false);
			}
		}
	}
}

void FlatFrame::_flat_is_displayed() {
	emit_signal(END_OPEN_FLAT_DETAIL);
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_flat_label", &FlatFrame::_set_flat_label);
	register_method("_set_health", &FlatFrame::_set_health);
	register_method("_on_exitButton_pressed", &FlatFrame::_on_exitButton_pressed);
	register_method("_on_move_in_pressed", &FlatFrame::_on_move_in_pressed);
	register_method("_on_tenant_selected", &FlatFrame::_on_tenant_selected);
	register_method("_on_repair_pressed", &FlatFrame::_on_repair_pressed);
	register_method("_on_fire_pressed", &FlatFrame::_on_fire_pressed);
	register_method("_exit_tenant_selector", &FlatFrame::_exit_tenant_selector);
	register_method("_on_pre_show", &FlatFrame::_on_pre_show);
	register_method("_flat_is_displayed", &FlatFrame::_flat_is_displayed);
	register_method("_on_action_count", &FlatFrame::_on_action_count);
	register_signal<FlatFrame>(SIGNAL_MOVE_IN_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL, "flatId", GODOT_VARIANT_TYPE_INT, "tenantId", GODOT_VARIANT_TYPE_INT);
	register_signal<FlatFrame>(SIGNAL_FIRE_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL, "flatId", GODOT_VARIANT_TYPE_INT);
	register_signal<FlatFrame>(SIGNAL_REPAIR_FLAT, "isPressed", GODOT_VARIANT_TYPE_BOOL, "flatId", GODOT_VARIANT_TYPE_INT);
	register_signal<FlatFrame>(START_OPEN_FLAT_DETAIL);
	register_signal<FlatFrame>(END_OPEN_FLAT_DETAIL);
}