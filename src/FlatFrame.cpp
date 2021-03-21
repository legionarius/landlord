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
	TextureButton *repairButton = cast_to<TextureButton>(get_node("Frame/RepairButton"));
	TextureButton *fireButton = cast_to<TextureButton>(get_node("Frame/FireButton"));
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));

	if(tenant != nullptr) {
		Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		tenantIdentityCard->set_tenant(tenant);
		tenantIdentityCard->set_position(Vector2(-112, -95));
		mainContainer->add_child(tenantIdentityCard);
	}

	repairButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_REPAIR_FLAT));
	fireButton->set_pressed(flatsManager->action_will_be_executed_in_flat(this->flat, ACTION_FIRE_TENANT));
	exitButton->connect("pressed", this, "_on_ExitButton_pressed");
	repairButton->connect("pressed", this, "_on_repair_pressed");
	fireButton->connect("pressed", this, "_on_fire_pressed");

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

void FlatFrame::_on_ExitButton_pressed() {
	queue_free();
}

void FlatFrame::_on_fire_pressed() {
	TextureButton *fireButton = cast_to<TextureButton>(get_node("Frame/FireButton"));
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	if (fireButton->is_pressed()){
		ActionFireTenant *actionFireTenant = new ActionFireTenant(this->flat);
		flatsManager->add_action(actionFireTenant);
	} else {
		flatsManager->remove_action(this->flat, ACTION_FIRE_TENANT);
	}
}

void FlatFrame::_on_repair_pressed() {
	TextureButton *repairButton = cast_to<TextureButton>(get_node("Frame/RepairButton"));
	FlatsManager *flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	if (repairButton->is_pressed()){
		ActionRepairFlat *actionRepairFlat = new ActionRepairFlat(this->flat);
		flatsManager->add_action(actionRepairFlat);
	} else {
		flatsManager->remove_action(this->flat, ACTION_REPAIR_FLAT);
	}
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_flat_label", &FlatFrame::_set_flat_label);
	register_method("_set_health", &FlatFrame::_set_health);
	register_method("_on_ExitButton_pressed", &FlatFrame::_on_ExitButton_pressed);
	register_method("_on_repair_pressed", &FlatFrame::_on_repair_pressed);
	register_method("_on_fire_pressed", &FlatFrame::_on_fire_pressed);
}