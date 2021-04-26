//
// Created by acroquelois on 18/03/2021.
//

#include "ActionFireTenant.h"

using namespace godot;

const std::string ActionFireTenant::iconPath = "res://asset/FlatFrame/fire_action_button.png";
const std::string ActionFireTenant::iconPathSelected = "res://asset/FlatFrame/fire_action_button_selected.png";

void ActionFireTenant::apply() {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(target);
	flat->fire_tenant();
}

real_t ActionFireTenant::get_cost() {
	return 0.f;
}

godot::String ActionFireTenant::get_name() {
	return godot::String("ActionFireTenant");
}

ActionType ActionFireTenant::get_actionType() {
	return ACTION_FIRE_TENANT;
}
