//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATSMANAGER_H
#define MUNDANE_JAM_FLATSMANAGER_H

#include "Action.h"
#include "ActionRepairFlat.h"
#include "Flat.h"
#include <Array.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <stack>

namespace godot {
class FlatsManager : public Node2D {
	GODOT_CLASS(FlatsManager, Node2D);

private:
	std::stack<Action*> actions;

public:
	void run_cycle();
	void add_action(Action * action);

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATSMANAGER_H
