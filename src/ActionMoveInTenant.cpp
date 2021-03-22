//
// Created by acroquelois on 20/03/2021.
//

#include "ActionMoveInTenant.h"

using namespace godot;

std::string ActionMoveInTenant::iconPath = "res://asset/FlatFrame/move_in_action_button.png";
std::string ActionMoveInTenant::iconPathSelected = "res://asset/FlatFrame/move_in_action_button_selected.png";

void ActionMoveInTenant::apply() {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(target);
	flat->sign_lease(tenant);
}