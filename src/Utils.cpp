//
// Created by bogdan on 30/03/2021.
//

#include "Utils.h"

using namespace godot;

GameState *godot::get_gameState(Node *node) {
	auto gameState = Object::cast_to<GameState>(node->get_tree()->get_root()->get_node("GameState"));
	return gameState;
}
