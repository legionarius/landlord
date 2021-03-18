//
// Created by bogdan on 25/02/2021.
//

#ifndef MUNDANE_JAM_GAMESTATE_H
#define MUNDANE_JAM_GAMESTATE_H

#include "ActionRepairFlat.h"
#include "FlatsManager.h"
#include "Signals.h"
#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

namespace godot {
class GameState : public Node {
	GODOT_CLASS(GameState, Node);

private:
	int64_t year;
	int64_t month;
	real_t balance;
	real_t monthly_charge;

	void next_month();
	void calculate_balance();
	void run_actions();

public:
	void _next_turn();
	void _add_action();

	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
};
} // namespace godot

#endif //MUNDANE_JAM_GAMESTATE_H
