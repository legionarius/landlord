//
// Created by bogdan on 15/03/2021.
//

#include "SignalButton.h"

using namespace godot;

void SignalButton::_init() {}

void SignalButton::_ready() {
	GameState *gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	connect(BTN_PRESSED, gameState, _method_name);
}

void SignalButton::_register_methods() {
	register_method("_init", &SignalButton::_init);
	register_method("_ready", &SignalButton::_ready);
	register_property<SignalButton, String>("on_pressed", &SignalButton::_method_name, String("gamestate_method"));
}