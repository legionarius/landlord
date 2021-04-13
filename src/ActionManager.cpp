//
// Created by bogdan on 07/04/2021.
//

#include "ActionManager.h"

using namespace godot;

void ActionManager::_init() {
}

void ActionManager::_ready() {
	auto flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	auto gameState = get_gameState(this);
	gameState->connect(NEW_CYCLE, this, "_on_new_cycle");
	flatsManager->connect(ADD_ACTION, this, "_on_action_added");
	flatsManager->connect(REMOVE_ACTION, this, "_on_action_removed");
}

void ActionManager::_on_action_added(int flatId, int actionTypeOrdinal) {
	Ref<PackedScene> action = ResourceLoader::get_singleton()->load("entity/ActionContainer/Action.tscn");
	auto actionItem = cast_to<ActionItem>(action->instance());
	actionItem->set_flat_number(flatId);
	actionItem->set_action_type(actionTypeOrdinal);
	add_child(actionItem);
}

void ActionManager::_on_action_removed(int flatId, int actionTypeOrdinal) {
	auto actionType = static_cast<ActionType>(actionTypeOrdinal);
	for (size_t i = 0; i < get_child_count(); i++) {
		auto actionItem = cast_to<ActionItem>(get_child(i));
		if (actionItem->get_flat_number() == flatId && actionItem->get_action_type() == actionType) {
			remove_child(actionItem);
		}
	}
}

void ActionManager::_on_new_cycle() {
	remove_children(this);
}

void ActionManager::_register_methods() {
	register_method("_init", &ActionManager::_init);
	register_method("_ready", &ActionManager::_ready);
	register_method("_on_action_added", &ActionManager::_on_action_added);
	register_method("_on_action_removed", &ActionManager::_on_action_removed);
	register_method("_on_new_cycle", &ActionManager::_on_new_cycle);
}
