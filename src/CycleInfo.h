//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_CYCLEINFO_H
#define MUNDANE_JAM_CYCLEINFO_H

#include "FlatsManager.h"
#include "GameState.h"
#include "Signals.h"
#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <iomanip>
#include <sstream>
#include <vector>

namespace godot {
class CycleInfo : public Control {
	GODOT_CLASS(CycleInfo, Control);

private:
	std::vector<String> months;
	Label *month;
	Label *year;
	Label *balance;
	Label *actions_cost;

public:
	String _balance_to_string(real_t balance);
	void _display_cycle(int month, int year, real_t balance);
	void _display_actions_cost(real_t cost);

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_CYCLEINFO_H
