//
// Created by bogdan on 15/03/2021.
//


#include "FlatsManager.h"

using namespace godot;

void FlatsManager::_init() {
}

void FlatsManager::_ready() {

}

void FlatsManager::_register_methods() {
	register_method("_init", &FlatsManager::_init);
	register_method("_ready", &FlatsManager::_ready);
}

void FlatsManager::run_cycle() {
	while (!actions.empty()) {
		Action * action = actions.top();
		Godot::print("Run action " + action->name + " on flat " + std::to_string(action->target_id).c_str());
		Array flats = get_children();
		action->apply(flats[action->target_id - 1]);
		actions.pop();
	}
}

void FlatsManager::add_action(Action * action) {
	Godot::print("Adding action : " + action->name);
	actions.push(action);
}
