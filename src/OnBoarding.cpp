//
// Created by acroquelois on 12/04/2021.
//

#include "OnBoarding.h"

using namespace godot;

void OnBoarding::_init() {}

void OnBoarding::_ready() {
	next_step();
}

void OnBoarding::next_step() {
	update_current_step_node();
	switch (currentStep) {
		case 1:
			Godot::print("[ONBOARDING]: Game presentation");
			_text_button_presentation();
			break;
		case 2:
			Godot::print("[ONBOARDING]: Flat detail presentation");
			_flat_detail_presentation();
			break;
		case 3:
			Godot::print("[ONBOARDING]: Flat characteristic presentation");
			_text_button_presentation();
			break;
		case 4:
			Godot::print("[ONBOARDING]: Flat tenant presentation");
			_text_button_presentation();
			break;
		case 5:
			Godot::print("[ONBOARDING]: Flat action presentation");
			_text_button_presentation();
			break;
		case 6:
			Godot::print("[ONBOARDING]: Flat detail exit presentation");
			_flat_detail_exit_presentation();
			break;
		case 7:
			Godot::print("[ONBOARDING]: cycle presentation");
			_text_button_presentation();
			break;
		case 8:
			Godot::print("[ONBOARDING]: next cycle presentation");
			_next_cycle_presentation();
		default:
			Godot::print("[ONBORDING]: Step doesn't exist");
			break;
	}
}

void OnBoarding::update_current_step_node() {
	currentStep += 1;
	if(currentStepNode != nullptr) {
		currentStepNode->queue_free();
	}
	std::stringstream nodePath;
	nodePath << "Container/Step" << currentStep;
	currentStepNode = cast_to<Control>(get_node(nodePath.str().c_str()));
	currentStepNode->set_visible(true);
}

void OnBoarding::_text_button_presentation() {
	Button *stepButton = cast_to<Button>(currentStepNode->get_node("Next"));
	stepButton->connect("pressed", this, "next_step");
}

void OnBoarding::_flat_detail_presentation() {

}

void OnBoarding::_flat_detail_exit_presentation() {

}

void OnBoarding::_next_cycle_presentation() {
	
}

void OnBoarding::_register_methods() {
	register_method("_init", &OnBoarding::_init);
	register_method("_ready", &OnBoarding::_ready);
	register_method("next_step", &OnBoarding::next_step);
}