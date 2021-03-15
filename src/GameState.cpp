//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {
	month = 0; // Starts at 0 -> JANUARY
	year = 1;
	balance = 1000;
	monthly_charge = 100;
}

void GameState::_ready() {
}

void GameState::_input(const Ref<InputEvent> event) {
}

void GameState::_next_turn() {
	// Apply actions
	// Update current state
	next_month();
	calculate_balance();
	// Update UI
	emit_signal(NEW_CYCLE, month, year, balance);
}

void GameState::next_month() {
	int incr_month = month + 1;
	if (incr_month >= 12) {
		year += 1;
	}
	month = (incr_month % 12);
}

void GameState::calculate_balance() {
	balance -= monthly_charge;
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_method("_next_turn", &GameState::_next_turn);
	register_signal<GameState>(NEW_CYCLE, "month", GODOT_VARIANT_TYPE_INT, "year", GODOT_VARIANT_TYPE_INT, "balance", GODOT_VARIANT_TYPE_REAL);
}