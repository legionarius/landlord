//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {}

void FlatFrame::_ready() {
	appartmentNameLabel = cast_to<Label>(get_node("AppartmentName"));
	healthLabel = cast_to<Label>(get_node("Health"));
}

void FlatFrame::_set_characteristics(Flat *flat){
	Godot::print(flat->id);
	std::stringstream healthString;
	std::stringstream nameString;
	healthString << flat->health;
	nameString << "APPARTMENT N " << flat->id;
	appartmentNameLabel->set_text(nameString.str().c_str());
	healthLabel->set_text(healthString.str().c_str());
}

void FlatFrame::_on_ExitButton_pressed() {
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_set_characteristics", &FlatFrame::_set_characteristics);
	register_method("_on_ExitButton_pressed", &FlatFrame::_on_ExitButton_pressed);
}