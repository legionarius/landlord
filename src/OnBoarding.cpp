//
// Created by acroquelois on 12/04/2021.
//

#include "OnBoarding.h"

using namespace godot;

void OnBoarding::_init() {}

void OnBoarding::_ready() {
	Timer *timer = cast_to<Timer>(get_node("StartTimer"));
	flatFrame = cast_to<FlatFrame>(get_tree()->get_root()->get_node("MainScene/FlatFrame"));
	timer->connect("timeout", this, "next_step");
}

void OnBoarding::next_step() {
	update_current_step_node();
	switch (currentStep) {
		case 1:
			Godot::print("[ONBOARDING]: Game presentation");
			_text_button_presentation();
			break;
		case 2:
			Godot::print("[ONBOARDING]: Over flat");
			_flat_detail_presentation();
			break;
		case 3:
			Godot::print("[ONBOARDING]: Flat detail presentation");
			_text_button_presentation();
			break;
		case 4:
			Godot::print("[ONBOARDING]: Flat characteristic presentation");
			_text_button_presentation();
			break;
		case 5:
			Godot::print("[ONBOARDING]: Flat characteristic presentation");
			_text_button_presentation();
			break;
		case 6:
			Godot::print("[ONBOARDING]: Flat tenant presentation");
			_text_button_presentation();
			break;
		case 7:
			Godot::print("[ONBOARDING]: Flat rent");
			_text_button_presentation();
			break;
		case 8:
			Godot::print("[ONBOARDING]: Flat detail exit presentation");
			_flat_detail_exit_presentation();
			break;
		case 9:
			Godot::print("[ONBOARDING]: Cycle presentation");
			_text_button_presentation();
			break;
		case 10:
			Godot::print("[ONBOARDING]: Next cycle presentation");
			_next_cycle_presentation();
			break;
		case 11:
			Godot::print("[ONBOARDING]: Cycle report presentation");
			_text_button_presentation();
			break;
		case 12:
			Godot::print("[ONBOARDING]: End tour presentation");
			last_step();
			break;
		default:
			Godot::print("[ONBORDING]: Step doesn't exist");
			break;
	}
}

void OnBoarding::update_current_step_node() {
	Godot::print("Update");
	currentStep += 1;
	if(currentStepNode != nullptr) {
		currentStepNode->queue_free();
	}
	disconnect_flat_frame_signals();
	std::stringstream nodePath;
	nodePath << "Container/Step" << currentStep;
	currentStepNode = cast_to<Popup>(get_node(nodePath.str().c_str()));
	currentStepNode->show();
}

void OnBoarding::last_step() {
	Button *stepButton = cast_to<Button>(currentStepNode->get_node("Next"));
	stepButton->connect("pressed", this, "end_tour");
}

void OnBoarding::end_tour() {
	queue_free();
}

void OnBoarding::_text_button_presentation() {
	Button *stepButton = cast_to<Button>(currentStepNode->get_node("Next"));
	stepButton->connect("pressed", this, "next_step");
}

void OnBoarding::_flat_detail_presentation() {
	flatFrame->connect(START_OPEN_FLAT_DETAIL, this, "hide_current_step");
	flatFrame->connect(END_OPEN_FLAT_DETAIL, this, "next_step");
}

void OnBoarding::disconnect_flat_frame_signals(){
	if(flatFrame->is_connected(START_OPEN_FLAT_DETAIL, this, "hide_current_step")){
		flatFrame->disconnect(START_OPEN_FLAT_DETAIL, this, "hide_current_step");
	}
	if(flatFrame->is_connected(END_OPEN_FLAT_DETAIL, this, "next_step")){
		flatFrame->disconnect(END_OPEN_FLAT_DETAIL, this, "next_step");
	}
	if(flatFrame->is_connected("popup_hide", this, "next_step")){
		flatFrame->disconnect("popup_hide", this, "next_step");
	}
}

void OnBoarding::hide_current_step() {
	currentStepNode->hide();
}

void OnBoarding::_flat_detail_exit_presentation() {
	flatFrame->connect("popup_hide", this, "next_step");
}

void OnBoarding::_next_cycle_presentation() {
	GameState *gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	gameState->connect(NEW_CYCLE,this, "next_step");
}

void OnBoarding::_register_methods() {
	register_method("_init", &OnBoarding::_init);
	register_method("_ready", &OnBoarding::_ready);
	register_method("next_step", &OnBoarding::next_step);
	register_method("hide_current_step", &OnBoarding::hide_current_step);
	register_method("end_tour", &OnBoarding::end_tour);
}