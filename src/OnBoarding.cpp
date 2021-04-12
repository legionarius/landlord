//
// Created by acroquelois on 12/04/2021.
//

#include "OnBoarding.h"

using namespace godot;

void OnBoarding::_init() {}

void OnBoarding::_ready() {}

void OnBoarding::next_step() {
	currentStep += 1;
	switch (currentStep) {
		case 1:
			_game_presentation();
			break;
		case 2:
			_flat_presentation();
			break;
		case 3:
			_tenant_presentation();
			break;
		case 4:
			_cycle_presentation();
			break;
		default:
			Godot::print("[ONBORDING]: Step doesn't exist");
			break;
	}
}

void OnBoarding::_game_presentation() {
	Godot::print("[ONBORDING]: game presentation");
}

void OnBoarding::_flat_presentation() {
	Godot::print("[ONBORDING]: flat presentation");
}

void OnBoarding::_tenant_presentation() {
	Godot::print("[ONBORDING]: tenant presentation");
}

void OnBoarding::_cycle_presentation() {
	Godot::print("[ONBORDING]: cycle presentation");
}

void OnBoarding::_register_methods() {
	register_method("_init", &OnBoarding::_init);
	register_method("_ready", &OnBoarding::_ready);
}