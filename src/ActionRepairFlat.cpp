//
// Created by bogdan on 16/03/2021.
//

#include "ActionRepairFlat.h"

using namespace godot;

std::string ActionRepairFlat::iconPath = "res://asset/FlatFrame/repair_action_button.png";
std::string ActionRepairFlat::iconPathSelected = "res://asset/FlatFrame/repair_action_button_selected.png";

void ActionRepairFlat::apply() {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(target);
	flat->repair();
	godot::Godot::print("[ACTION]: Repairing flat : " + flat->get_name());
}

real_t ActionRepairFlat::get_cost() {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(target);
	return (100 - flat->health) * 10.f;
}