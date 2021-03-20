//
// Created by bogdan on 16/03/2021.
//

#include "ActionRepairFlat.h"

godot::String ActionRepairFlat::iconPath = "res://asset/FlatFrame/repair_action_button.png";
godot::String ActionRepairFlat::iconPathSelected = "res://asset/FlatFrame/repair_action_button_selected.png";

void ActionRepairFlat::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Repairing flat : " + flat->get_name());
}