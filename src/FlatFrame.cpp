//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	Label *apartmentName = cast_to<Label>(get_node("Frame/ApartmentNameBackground/AppartmentName"));
	ProgressBar *healthGauge = cast_to<ProgressBar>(get_node("Frame/HealthBackground/HealthProgressBar"));
	Label *rent = cast_to<Label>(get_node("Frame/RentBackground/Rent"));
	AnimationPlayer *animation = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	AudioStreamPlayer *audio = cast_to<AudioStreamPlayer>(get_node("AudioStreamPlayer"));
	audio->play();
	animation->play("open");

	apartmentName->set_text(apartmentNameLabel);
	rent->set_text(rentLabel);
	healthGauge->set_value(healthLabel);
}

void FlatFrame::_set_apartment_label(real_t id) {
	std::stringstream nameString;
	nameString << "APARTMENT N " << id;
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

void FlatFrame::_on_ExitButton_pressed() {
	queue_free();
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_apartment_label", &FlatFrame::_set_apartment_label);
	register_method("_set_health", &FlatFrame::_set_health);
	register_method("_on_ExitButton_pressed", &FlatFrame::_on_ExitButton_pressed);
}