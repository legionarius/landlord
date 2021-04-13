//
// Created by acroquelois on 12/04/2021.
//

#include "MainScene.h"

using namespace godot;

void MainScene::_init() {}

void MainScene::_ready() {
	GameState *gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	gameState->main_scene_loaded();
}

void MainScene::_register_methods() {
	register_method("_init", &MainScene::_init);
	register_method("_ready", &MainScene::_ready);
}