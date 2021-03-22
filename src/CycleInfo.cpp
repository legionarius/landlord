//
// Created by bogdan on 15/03/2021.
//

#include "CycleInfo.h"

using namespace godot;

void CycleInfo::_init() {
	months = {
		"JANUARY",
		"FEBRUARY",
		"MARCH",
		"APRIL",
		"MAY",
		"JUNE",
		"JULY",
		"AUGUST",
		"SEPTEMBER",
		"OCTOBER",
		"NOVEMBER",
		"DECEMBER"
	};
}

void CycleInfo::_ready() {
	GameState * gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	FlatsManager * flatsManager = cast_to<FlatsManager>(get_tree()->get_root()->get_node("MainScene/Map/Flats"));
	month = cast_to<Label>(get_node("Month"));
	year = cast_to<Label>(get_node("Year"));
	balance = cast_to<Label>(get_node("Balance"));
	actions_cost = cast_to<Label>(get_node("ActionsCost"));
	gameState->connect(NEW_CYCLE, this, "_display_cycle");
	flatsManager->connect(ACTIONS_COST, this, "_display_actions_cost");
}

void CycleInfo::_display_cycle(const int month, const int year, const real_t balance) {
	std::stringstream balance_str;
	this->month->set_text(months[month]);
	this->year->set_text("year " + String(std::to_string(year).c_str()));

	balance_str << std::fixed << std::setprecision(2) << balance;
	this->balance->set_text(String(balance_str.str().c_str()) + String(" $"));

	// Reset actions cost
	_display_actions_cost(0.f);
}

void CycleInfo::_display_actions_cost(real_t cost) {
	std::stringstream cost_str;
	cost_str << std::fixed << std::setprecision(2) << cost;
	actions_cost->set_text(String("Actions cost : ") + String(cost_str.str().c_str()) + String(" $"));
}

void CycleInfo::_register_methods() {
	register_method("_init", &CycleInfo::_init);
	register_method("_ready", &CycleInfo::_ready);
	register_method("_display_cycle", &CycleInfo::_display_cycle);
	register_method("_display_actions_cost", &CycleInfo::_display_actions_cost);
}

