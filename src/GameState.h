//
// Created by bogdan on 25/02/2021.
//

#ifndef MUNDANE_JAM_GAMESTATE_H
#define MUNDANE_JAM_GAMESTATE_H

#include "ActionRepairFlat.h"
#include "FlatsManager.h"
#include "OnBoarding.h"
#include "ReportFrame.h"
#include "Signals.h"

#include <Control.hpp>
#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <Ref.hpp>
#include <Resource.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

namespace godot {
class ReportFrame;

class GameState : public Node {
	GODOT_CLASS(GameState, Node);

private:
	int64_t year;
	int64_t month;
	real_t balance;
	float_t sound_volume = 1.f;

	ReportFrame *reportFrame;
	Node *mainScene;
	// If the onBoarding piss you off, you can pass the following variable to "true"
	bool onBoardingLoaded = false;

	void next_month();
	void calculate_balance();
	void run_actions();
	void end_game();
	void calculate_actions_cost();

public:
	void _next_turn();
	real_t get_cycle_number();
	real_t get_balance() { return balance; }

	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
	void init_properties();
	void start_game();
	void main_scene_loaded();
	void _update_sound_volume(float_t volume);
	float_t _get_sound_volume();
};
} // namespace godot

#endif //MUNDANE_JAM_GAMESTATE_H
