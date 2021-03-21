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
	// Clean-up logs
	if (monthReport == nullptr) {
		monthReport = cast_to<MonthReport>(get_tree()->get_root()->get_node("MainScene/UILayer/MonthReport"));
	}
	monthReport->_flush();

	calculate_balance();
	calculate_actions_cost();
	// Apply actions
	run_actions();
	// Update current state
	next_month();
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

void GameState::run_actions() {
	FlatsManager * flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	flatManager->run_cycle();
}

void GameState::calculate_balance() {
	FlatsManager * flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	balance += flatManager->_collect_rent();
}

void GameState::calculate_actions_cost() {
	FlatsManager * flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	balance -= flatManager->get_actions_cost();
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_method("_next_turn", &GameState::_next_turn);
	register_signal<GameState>(NEW_CYCLE, "month", GODOT_VARIANT_TYPE_INT, "year", GODOT_VARIANT_TYPE_INT, "balance", GODOT_VARIANT_TYPE_REAL);
}
