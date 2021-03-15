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
		auto action = actions.top();
		Array flats = get_children();
		action.apply(flats[action.target_id]);
		actions.pop();
	}
}

void FlatsManager::add_action(Action action) {
	actions.push(action);
}
