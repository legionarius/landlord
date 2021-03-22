//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	Sprite *mainContainer = cast_to<Sprite>(get_node("Frame"));
	Label *flatName = cast_to<Label>(get_node("Frame/FlatNameBackground/FlatName"));
	ProgressBar *healthGauge = cast_to<ProgressBar>(get_node("Frame/HealthBackground/HealthProgressBar"));
	Label *rent = cast_to<Label>(get_node("Frame/RentBackground/Rent"));
	AnimationPlayer *animation = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	AudioStreamPlayer *audio = cast_to<AudioStreamPlayer>(get_node("AudioStreamPlayer"));
	TextureButton *exitButton = cast_to<TextureButton>(get_node("Frame/ExitButton"));

	if(tenant != nullptr) {
		Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		tenantIdentityCard->set_tenant(tenant);
		tenantIdentityCard->set_position(Vector2(-112, -95));
		mainContainer->add_child(tenantIdentityCard);
		_add_fire_tenant_button();
	} else {
		_add_move_in_tenant_button();
		_add_repair_flat_button();
	}

	exitButton->connect("pressed", this, "_on_exitButton_pressed");

	audio->play();
	animation->play("open");

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
	rentString << "$" << rent;
	rentLabel = rentString.str().c_str();
}

void FlatFrame::_set_tenant(TenantIdentityCard::Tenant* m_tenant) {
	this->tenant = m_tenant;
}

void FlatFrame::_on_exitButton_pressed() {
	queue_free();
}

void FlatFrame::_on_move_in_pressed() {
	TextureButton *moveInButton = cast_to<TextureButton>(get_node("Frame/MoveInButton"));
	if(!moveInButton->is_pressed()){
		emit_signal(SIGNAL_MOVE_IN_TENANT, moveInButton->is_pressed(), 0);
	} else {
		Ref<PackedScene> tenantSelectorScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantSelector.tscn");
		TenantSelector *tenantSelector = Object::cast_to<TenantSelector>(tenantSelectorScene->instance());
		tenantSelector->set_name("TenantSelector");
		tenantSelector->connect(NEW_TENANT_SELECTED, this, "_on_tenant_selected");
		add_child(tenantSelector);
	}
}

void FlatFrame::_on_tenant_selected(uint64_t tenantId) {
	Node *tenantSelector = get_node("TenantSelector");
	tenantSelector->queue_free();
	TextureButton *moveInButton = cast_to<TextureButton>(get_node("Frame/MoveInButton"));
	emit_signal(SIGNAL_MOVE_IN_TENANT, moveInButton->is_pressed(), tenantId);
}

void FlatFrame::_on_fire_pressed() {
	TextureButton *fireButton = cast_to<TextureButton>(get_node("Frame/FireButton"));
	emit_signal(SIGNAL_FIRE_TENANT, fireButton->is_pressed());
}

void FlatFrame::_on_repair_pressed() {
	TextureButton *repairButton = cast_to<TextureButton>(get_node("Frame/RepairButton"));
	emit_signal(SIGNAL_REPAIR_FLAT, repairButton->is_pressed());
}

void FlatFrame::_add_fire_tenant_button() const {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	Ref<Texture> actionIcon = ResourceLoader::get_singleton()->load(ActionFireTenant::iconPath.c_str());
	Ref<Texture> actionIconSelected = ResourceLoader::get_singleton()->load(ActionFireTenant::iconPathSelected.c_str());
	TextureButton *fireButton = TextureButton::_new();
	fireButton->set_name("FireButton");
	fireButton->set_position(Vector2(-276, 130));
	fireButton->set_scale(Vector2(0.4, 0.4));
	fireButton->set_normal_texture(actionIcon);
	fireButton->set_pressed_texture(actionIconSelected);
	fireButton->set_toggle_mode(true);
	fireButton->connect("pressed", this, "_on_fire_pressed");
	fireButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_FIRE_TENANT));

	Node *parentNode = get_node("Frame");
	parentNode->add_child(fireButton);
}

void FlatFrame::_add_move_in_tenant_button() const {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	Ref<Texture> actionIcon = ResourceLoader::get_singleton()->load(ActionMoveInTenant::iconPath.c_str());
	Ref<Texture> actionIconSelected = ResourceLoader::get_singleton()->load(ActionMoveInTenant::iconPathSelected.c_str());
	TextureButton *moveInButton = TextureButton::_new();
	moveInButton->set_name("MoveInButton");
	moveInButton->set_position(Vector2(-276, 130));
	moveInButton->set_scale(Vector2(0.4, 0.4));
	moveInButton->set_normal_texture(actionIcon);
	moveInButton->set_pressed_texture(actionIconSelected);
	moveInButton->set_toggle_mode(true);
	moveInButton->connect("pressed", this, "_on_move_in_pressed");
	moveInButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_MOVE_IN_TENANT));

	Node *parentNode = get_node("Frame");
	parentNode->add_child(moveInButton);
}

void FlatFrame::_add_repair_flat_button() const {
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	Ref<Texture> actionIcon = ResourceLoader::get_singleton()->load(ActionRepairFlat::iconPath.c_str());
	Ref<Texture> actionIconSelected = ResourceLoader::get_singleton()->load(ActionRepairFlat::iconPathSelected.c_str());
	TextureButton *repairFlatButton = TextureButton::_new();
	repairFlatButton->set_name("RepairButton");
	repairFlatButton->set_position(Vector2(-237, 130));
	repairFlatButton->set_scale(Vector2(0.4, 0.4));
	repairFlatButton->set_normal_texture(actionIcon);
	repairFlatButton->set_pressed_texture(actionIconSelected);
	repairFlatButton->set_toggle_mode(true);
	repairFlatButton->connect("pressed", this, "_on_repair_pressed");
	repairFlatButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_REPAIR_FLAT));

	Node *parentNode = get_node("Frame");
	parentNode->add_child(repairFlatButton);
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
	register_signal<FlatFrame>(SIGNAL_MOVE_IN_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL, "tenantId", GODOT_VARIANT_TYPE_INT);
	register_signal<FlatFrame>(SIGNAL_FIRE_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL);
	register_signal<FlatFrame>(SIGNAL_REPAIR_FLAT, "isPressed", GODOT_VARIANT_TYPE_BOOL);
}