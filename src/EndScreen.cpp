//
// Created by acroquelois on 02/04/2021.
//

#include "EndScreen.h"

using namespace godot;

void EndScreen::_init() {}

void EndScreen::_ready() {
	gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	Label *nbCycleSurvived = cast_to<Label>(get_node("NbMonthSurvived"));
	Button *buttonRestart = cast_to<Button>(get_node("RestartButton"));
	Button *buttonExit = cast_to<Button>(get_node("ExitButton"));
	buttonRestart->connect("pressed", this, "_restartGame");
	buttonExit->connect("pressed", this, "_exitGame");
	std::stringstream nbCycle;
	nbCycle << gameState->get_cycle_number() << " months";
	nbCycleSurvived->set_text(nbCycle.str().c_str());
}

void EndScreen::_restartGame() {
	queue_free();
	gameState->init_properties();
	gameState->emit_signal(NEW_CYCLE);
	get_tree()->change_scene("entity/MainScene/MainScene.tscn");
}

void EndScreen::_exitGame() {
	get_tree()->quit();
}

void EndScreen::_register_methods() {
	register_method("_init", &EndScreen::_init);
	register_method("_ready", &EndScreen::_ready);
	register_method("_exitGame", &EndScreen::_exitGame);
	register_method("_restartGame", &EndScreen::_restartGame);
}
