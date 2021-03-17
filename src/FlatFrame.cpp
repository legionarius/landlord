//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {
}

void FlatFrame::_ready() {
	Label *appartmentName = cast_to<Label>(get_node("AppartmentName"));
	Label *health = cast_to<Label>(get_node("Health"));
	if (appartmentName == nullptr && health == nullptr) {
		Godot::print("Pointer null");
	} else {
		appartmentName->set_text(appartmentNameLabel);
		health->set_text(healthLabel);
	}
}

void FlatFrame::_set_appartment_label(int64_t id) {
	std::stringstream nameString;
	nameString << "APPARTMENT N " << id;
	appartmentNameLabel = nameString.str().c_str();
}

void FlatFrame::_set_health(int64_t health) {
	std::stringstream healthString;
	healthString << health;
	healthLabel = healthString.str().c_str();
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