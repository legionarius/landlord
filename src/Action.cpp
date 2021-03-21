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
