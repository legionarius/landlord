//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_on_pressed", &Flat::_on_pressed);
	register_method("queue_move_in_tenant", &Flat::queue_move_in_tenant);
	register_method("queue_repair_flat", &Flat::queue_repair_flat);
	register_method("queue_fire_tenant", &Flat::queue_fire_tenant);
	register_method("reset_action_icon", &Flat::reset_action_icon);
	register_method("show_indicators", &Flat::show_indicators);
}

void Flat::_init() {
	rng = RandomNumberGenerator()._new();
	rng->randomize();
	health = rng->randi_range(0, 100);
	rent = rng->randf_range(100, 500);
	update_charge();
}

// Should be run after each cycle when
// the flat health changes.
void Flat::update_charge() {
	// Charge :
	// - 50% of the rent
	// - Bonus of 25% of the health (remove the bonus from the charge)
	charge = (rent * 50.f) / 100.f - (health * 0.25);
}

void Flat::_ready() {
	connect("pressed", this, "_on_pressed");
	id = get_name().right(4).to_int();
	flatIndicators = cast_to<FlatIndicators>(get_node("FlatIndicators"));
	lightBulbTenant = cast_to<Light2D>(get_node("LightBulb/Light2D"));
	lightBulb = cast_to<Sprite>(get_node("LightBulb"));
	lightBulb->set_modulate(Color(0.5, 0.5, 0.5));
}

void Flat::sign_lease(TenantIdentityCard::Tenant *tenant) {
	GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	if(gameState->get_cycle_number() == 0){
		tenant->leasing_end_cycle = gameState->get_cycle_number() + tenant->leasing_duration-1;
	} else {
		tenant->leasing_end_cycle = gameState->get_cycle_number() + tenant->leasing_duration;
	}
	this->tenant = tenant;
}

void Flat::_on_pressed() {
	Ref<PackedScene> flatFrameScene = ResourceLoader::get_singleton()->load("entity/FlatFrame/FlatFrame.tscn");
	FlatFrame *flatFrame = cast_to<FlatFrame>(flatFrameScene->instance());
	flatFrame->_set_flat(this);
	flatFrame->_set_flat_label(id);
	flatFrame->_set_health(health);
	flatFrame->_set_rent(rent);
	flatFrame->_set_tenant(tenant);
	// TODO: Voir pour faire une methode queue action en passant un param dans la méthode connect
	flatFrame->connect(SIGNAL_REPAIR_FLAT, this, "queue_repair_flat");
	flatFrame->connect(SIGNAL_FIRE_TENANT, this, "queue_fire_tenant");
	flatFrame->connect(SIGNAL_MOVE_IN_TENANT, this, "queue_move_in_tenant");
	add_child(flatFrame);
	flatFrame->popup();
}

real_t Flat::break_legs_and_collect_money() {
	if (tenant != nullptr) {
		rng->randomize();
		real_t n = rng->randf_range(0, 1);
		if (n < (tenant->confidence / 100.f)) {
			Godot::print("[RENT]: payed for flat " + String(std::to_string(id).c_str()));
			flatIndicators->isPayedVisible = true;
			flatIndicators->isNotPayedVisible = false;
			return rent - charge;
		} else {
			Godot::print("[RENT]: NOT payed for flat " + String(std::to_string(id).c_str()));
			flatIndicators->isNotPayedVisible = true;
			flatIndicators->isPayedVisible = false;
			return 0.f;
		}
	} else {
		return 0.f;
	}
}

void Flat::queue_move_in_tenant(const bool isPressed, const uint64_t tenantId) {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	if (isPressed) {
		TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(tenantId-1);
		ActionMoveInTenant *actionMoveInTenant = new ActionMoveInTenant(this, tenant);
		flatsManager->add_action(actionMoveInTenant);
		_add_action_icon_on_flat(actionMoveInTenant);

	} else {
		flatsManager->remove_action(this, ACTION_MOVE_IN_TENANT);
		_remove_action_icon_on_flat(ACTION_MOVE_IN_TENANT);
	}
}

void Flat::queue_fire_tenant(const bool isPressed) {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	if (isPressed) {
		ActionFireTenant *actionFireTenant = new ActionFireTenant(this);
		flatsManager->add_action(actionFireTenant);
		_add_action_icon_on_flat(actionFireTenant);
		flatIndicators->isLeaveVisible = true;
	} else {
		flatsManager->remove_action(this, ACTION_FIRE_TENANT);
		_remove_action_icon_on_flat(ACTION_FIRE_TENANT);
		flatIndicators->isLeaveVisible = false;
	}
}

void Flat::queue_repair_flat(const bool isPressed) {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	if (isPressed) {
		ActionRepairFlat *actionRepairFlat = new ActionRepairFlat(this);
		if (!flatsManager->action_will_be_executed_in_flat(this, ACTION_REPAIR_FLAT)) {
			flatsManager->add_action(actionRepairFlat);
			_add_action_icon_on_flat(actionRepairFlat);
			flatIndicators->isRepairVisible = true;
		}
	} else {
		flatsManager->remove_action(this, ACTION_REPAIR_FLAT);
		_remove_action_icon_on_flat(ACTION_REPAIR_FLAT);
		flatIndicators->isRepairVisible = false;
	}
}

void Flat::reset_action_icon() {
	Array icons = get_children();
	for (size_t i = 0; i < icons.size(); i++) {
		Node *icon = cast_to<Node>(icons[i]);
		if (icon->get_class() == "TextureRect") {
			icon->queue_free();
		}
	}
}

void Flat::show_indicators() {
	flatIndicators->_show_indicators();
}

void Flat::_add_action_icon_on_flat(Action *action) {
	TextureRect *textureRect = TextureRect::_new();
	Ref<Texture> action_icon = ResourceLoader::get_singleton()->load(action->get_texture_path());
	textureRect->set_name(action->type_to_string(action->actionType));
	textureRect->set_texture(action_icon);
	textureRect->set_position(Vector2(0, 35));
	textureRect->set_scale(Vector2(0.2, 0.2));
	textureRect->set_margin(0, 20 * (get_child_count() - 1));
	add_child(textureRect);
}

void Flat::_remove_action_icon_on_flat(ActionType actionType) {
	std::stringstream actionNodeName;
	Node *node = get_node(Action::type_to_string(actionType).operator NodePath());
	node->queue_free();
}

void Flat::repair() {
	health = 100;
}

void Flat::fire_tenant() {
	tenant = nullptr;
}

void Flat::fire_tenant_if_end_leasing() {
	if (tenant != nullptr) {
		GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
		if (tenant->leasing_end_cycle <= gameState->get_cycle_number()) {
			fire_tenant();
		}
	}
}

void Flat::update_health() {
	int64_t decay = 0;
	int64_t min_health = 0;
	if (tenant != nullptr) {
		decay = static_cast<int64_t>(FLAT_DECAY_RATE - (tenant->cleanliness * FLAT_DECAY_RATE_NO_TENANT) / 100);
	} else {
		decay = FLAT_DECAY_RATE_NO_TENANT;
	}
	health -= std::max(min_health, decay);
}

void Flat::update_tenant_presence() {
	if (tenant != nullptr) {
		lightBulbTenant->set_enabled(true);
	} else {
		lightBulbTenant->set_enabled(false);
	}
}
