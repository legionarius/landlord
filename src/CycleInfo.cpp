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
	month = cast_to<Label>(get_node("Month"));
	year = cast_to<Label>(get_node("Year"));
	balance = cast_to<Label>(get_node("Balance"));
	gameState->connect(NEW_CYCLE, this, "_display_cycle");
}

void CycleInfo::_display_cycle(const int month, const int year, const real_t balance) {
	Godot::print("Received new cycle info" + String(std::to_string(month).c_str()));
	std::stringstream balance_str;
	this->month->set_text(months[month]);
	this->year->set_text("year " + String(std::to_string(year).c_str()));

	balance_str << std::fixed << std::setprecision(2) << balance;
	this->balance->set_text(String(balance_str.str().c_str()) + String(" $"));
}

void CycleInfo::_register_methods() {
	register_method("_init", &CycleInfo::_init);
	register_method("_ready", &CycleInfo::_ready);
	register_method("_display_cycle", &CycleInfo::_display_cycle);
}
