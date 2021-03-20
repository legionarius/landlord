//
// Created by acroquelois on 18/03/2021.
//

#include "ActionFireTenant.h"

godot::String ActionFireTenant::iconPath = "res://asset/FlatFrame/fire_action_button.png";
godot::String ActionFireTenant::iconPathSelected = "res://asset/FlatFrame/fire_action_button_selected.png";

void ActionFireTenant::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Fire tenant in flat : " + flat->get_name());
}