//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {
	init_properties();
}

void GameState::init_properties() {
	month = 0; // Starts at 0 -> JANUARY
	year = 1;
	balance = 1000;
}

void GameState::_ready() {}

void GameState::_input(const Ref<InputEvent> event) {
}

void GameState::_next_turn() {
	// Clean-up logs
	if (get_cycle_number() == 0) {
		monthReport = cast_to<MonthReport>(get_tree()->get_root()->get_node("MainScene/UILayer/MonthReport"));
	}

	monthReport->_flush();

	calculate_balance();
	calculate_actions_cost();

	if (balance < 0) {
		end_game();
	} else {
		// Apply actions
		run_actions();
		// Update current state
		next_month();
		// Update UI
		emit_signal(NEW_CYCLE, month, year, balance);
	}
}

void GameState::next_month() {
	int incr_month = month + 1;
	if (incr_month >= 12) {
		year += 1;
	}
	month = (incr_month % 12);
}

real_t GameState::get_cycle_number() {
	return (year - 1) * 12 + month;
}

void GameState::run_actions() {
	FlatsManager *flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	flatManager->run_cycle();
}

void GameState::calculate_balance() {
	FlatsManager *flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	balance += flatManager->_collect_rent();
}

void GameState::calculate_actions_cost() {
	FlatsManager *flatManager =
			cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	balance -= flatManager->get_actions_cost();
}

void GameState::start_game() {}

void GameState::main_scene_loaded() {
	Godot::print("Main scene loaded");
	mainScene = get_tree()->get_root()->get_node("MainScene");
	Ref<PackedScene> onBoardingScene = ResourceLoader::get_singleton()->load("entity/OnBoarding/OnBoarding.tscn");
	OnBoarding *onBoarding = cast_to<OnBoarding>(onBoardingScene->instance());
	mainScene->add_child(onBoarding);
	onBoarding->next_step();
}

void GameState::end_game() {
	mainScene->queue_free();
	get_tree()->change_scene("entity/EndScreen/EndScreen.tscn");
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_method("_next_turn", &GameState::_next_turn);
	register_method("init_properties", &GameState::init_properties);
	register_method("start_game", &GameState::start_game);
	register_method("main_scene_loaded", &GameState::main_scene_loaded);
	register_signal<GameState>(NEW_CYCLE, "month", GODOT_VARIANT_TYPE_INT, "year", GODOT_VARIANT_TYPE_INT, "balance", GODOT_VARIANT_TYPE_REAL);
}
