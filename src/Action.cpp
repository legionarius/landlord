//
// Created by bogdan on 15/03/2021.
//

#include "Action.h"

void Action::apply() {
	godot::Godot::print("Running default Action implementation !");
}

real_t Action::get_cost() {
	return 0.f;
}

godot::String Action::get_texture_path() {
	return "";
}

godot::String Action::get_name() {
	return godot::String("Action");
}

ActionType Action::get_actionType() {
	return actionType;
}
