//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	Label *appartmentName = cast_to<Label>(get_node("Frame/AppartmentName"));
	Label *health = cast_to<Label>(get_node("Frame/Health"));
	Label *rent = cast_to<Label>(get_node("Frame/Rent"));
	AnimationPlayer *animation = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	appartmentName->set_text(appartmentNameLabel);
	health->set_text(healthLabel);
	rent->set_text(rentLabel);
	animation->play("open");
}

void FlatFrame::_set_appartment_label(real_t id) {
	std::stringstream nameString;
	nameString << "APPARTMENT N " << id;
	appartmentNameLabel = nameString.str().c_str();
}

void FlatFrame::_set_health(real_t health) {
	std::stringstream healthString;
	healthString << health;
	healthLabel = healthString.str().c_str();
}

void FlatFrame::_set_rent(real_t rent) {
	std::stringstream rentString;
	rentString << rent << " $";
	rentLabel = rentString.str().c_str();
}

void FlatFrame::_on_ExitButton_pressed() {
	queue_free();
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_appartment_label", &FlatFrame::_set_appartment_label);
	register_method("_set_health", &FlatFrame::_set_health);
	register_method("_on_ExitButton_pressed", &FlatFrame::_on_ExitButton_pressed);
}