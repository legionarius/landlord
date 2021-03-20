//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	Sprite *mainContainer = cast_to<Sprite>(get_node("Frame"));
	Label *apartmentName = cast_to<Label>(get_node("Frame/ApartmentNameBackground/AppartmentName"));
	ProgressBar *healthGauge = cast_to<ProgressBar>(get_node("Frame/HealthBackground/HealthProgressBar"));
	Label *rent = cast_to<Label>(get_node("Frame/RentBackground/Rent"));
	AnimationPlayer *animation = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	AudioStreamPlayer *audio = cast_to<AudioStreamPlayer>(get_node("AudioStreamPlayer"));
	TextureButton *exitButton = cast_to<TextureButton>(get_node("Frame/ExitButton"));
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));

//	TextureButton *repairButton = cast_to<TextureButton>(get_node("Frame/RepairButton"));
//	TextureButton *fireButton = cast_to<TextureButton>(get_node("Frame/FireButton"));
//	TextureButton *moveInButton = cast_to<TextureButton>(get_node("Frame/MoveInButton"));
//	repairButton->connect("pressed", this, "_on_repair_pressed");
//	fireButton->connect("pressed", this, "_on_fire_pressed");
//	moveInButton->connect("pressed", this, "_on_move_in_pressed");
//	repairButton->set_pressed(flatsManager->action_will_be_executed_in_apartment(this->apartmentId, ACTION_REPAIR_FLAT));
//	fireButton->set_pressed(flatsManager->action_will_be_executed_in_apartment(this->apartmentId, ACTION_FIRE_TENANT));
//	moveInButton->set_pressed(flatsManager->action_will_be_executed_in_apartment(this->apartmentId, ACTION_MOVE_IN_TENANT));

	if(tenant != nullptr) {
		Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		tenantIdentityCard->set_tenant(tenant);
		tenantIdentityCard->set_position(Vector2(-112, -95));
		mainContainer->add_child(tenantIdentityCard);
		_add_fire_tenant_button();

	} else {
		Godot::print("no Tenant");
	}

	exitButton->connect("pressed", this, "_on_exitButton_pressed");

	audio->play();
	animation->play("open");

	apartmentName->set_text(apartmentNameLabel);
	rent->set_text(rentLabel);
	healthGauge->set_value(healthLabel);
}

void FlatFrame::_set_apartment_label(real_t id) {
	std::stringstream nameString;
	nameString << "APARTMENT N " << id;
	apartmentId = id;
	apartmentNameLabel = nameString.str().c_str();
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

void::FlatFrame::_on_move_in_pressed() {
	TextureButton *moveInButton = cast_to<TextureButton>(get_node("Frame/MoveInButton"));
	emit_signal(SIGNAL_MOVE_IN_TENANT, moveInButton->is_pressed());
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
	Ref<Texture> actionIcon = ResourceLoader::get_singleton()->load(ActionFireTenant::iconPath);
	Ref<Texture> actionIconSelected = ResourceLoader::get_singleton()->load(ActionFireTenant::iconPathSelected);
	TextureButton *fireButton = TextureButton::_new();
	fireButton->set_position(Vector2(-276, 130));
	fireButton->set_scale(Vector2(0.4, 0.4));
	fireButton->set_normal_texture(actionIcon);
	fireButton->set_pressed_texture(actionIconSelected);
	Node *parentNode = get_node("Frame");
	parentNode->add_child(fireButton);
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_apartment_label", &FlatFrame::_set_apartment_label);
	register_method("_set_health", &FlatFrame::_set_health);
	register_method("_on_exitButton_pressed", &FlatFrame::_on_exitButton_pressed);
	register_method("_on_move_in_pressed", &FlatFrame::_on_move_in_pressed);
	register_method("_on_repair_pressed", &FlatFrame::_on_repair_pressed);
	register_method("_on_fire_pressed", &FlatFrame::_on_fire_pressed);
	register_signal<FlatFrame>(SIGNAL_MOVE_IN_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL);
	register_signal<FlatFrame>(SIGNAL_FIRE_TENANT, "isPressed", GODOT_VARIANT_TYPE_BOOL);
	register_signal<FlatFrame>(SIGNAL_REPAIR_FLAT, "isPressed", GODOT_VARIANT_TYPE_BOOL);
}