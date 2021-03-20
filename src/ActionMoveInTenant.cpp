//
// Created by acroquelois on 20/03/2021.
//

#include "ActionMoveInTenant.h"

godot::String ActionMoveInTenant::iconPath = "res://asset/FlatFrame/move_in_action_button.png";
godot::String ActionMoveInTenant::iconPathSelected = "res://asset/FlatFrame/move_in_action_button_selected.png";

void ActionMoveInTenant::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Move in tenant in flat : " + flat->get_name());
}