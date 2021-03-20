//
// Created by bogdan on 15/03/2021.
//

#include "Action.h"

void Action::apply(godot::Node *item) {
	godot::Godot::print("Running default Action implementation !");
}

godot::String Action::get_texture_path() {
	return "";
}

godot::String Action::type_to_string(ActionType type) {
	switch(type) {
		case ACTION_REPAIR_FLAT:
			return "ActionRepairFlat";
		case ACTION_FIRE_TENANT:
			return "ActionFireTenant";
		case ACTION_MOVE_IN_TENANT:
			return "ActionMoveInTenant";
		default:
			return "InvalidAction";
	}
}