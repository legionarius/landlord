//
// Created by bogdan on 30/03/2021.
//

#include "Utils.h"

using namespace godot;

GameState *godot::get_gameState(Node *node) {
	auto gameState = Object::cast_to<GameState>(node->get_tree()->get_root()->get_node("GameState"));
	return gameState;
}

void godot::remove_children(Node *node) {
	while (node->get_child_count() > 0) {
		auto child = node->get_child(0);
		node->remove_child(child);
		child->free();
	}
}
