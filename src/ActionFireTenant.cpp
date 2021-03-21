//
// Created by acroquelois on 18/03/2021.
//

#include "ActionFireTenant.h"

std::string ActionFireTenant::iconPath = "res://asset/FlatFrame/fire_action_button.png";
std::string ActionFireTenant::iconPathSelected = "res://asset/FlatFrame/fire_action_button_selected.png";

void ActionFireTenant::apply() {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(target);
	godot::Godot::print("[ACTION]: Fire tenant in flat : " + flat->get_name());
}

real_t ActionFireTenant::get_cost() {
	return 0.f;
}
