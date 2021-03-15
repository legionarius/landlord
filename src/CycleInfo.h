//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_CYCLEINFO_H
#define MUNDANE_JAM_CYCLEINFO_H

#include <Godot.hpp>
#include <Control.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Label.hpp>
#include "GameState.h"
#include "Signals.h"
#include <vector>

namespace godot {
class CycleInfo : public Control {
	GODOT_CLASS(CycleInfo, Control);

private:
	std::vector<String> months;
	Label * month;
	Label * year;


public:
	void _display_cycle(int month, int year);

	static void _register_methods();
	void _init();
	void _ready();
};
}

#endif //MUNDANE_JAM_CYCLEINFO_H
