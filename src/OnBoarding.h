//
// Created by acroquelois on 12/04/2021.
//

#ifndef MUNDANE_JAM_ONBOARDING_H
#define MUNDANE_JAM_ONBOARDING_H

#include <Button.hpp>
#include <CanvasLayer.hpp>
#include <Control.hpp>
#include <Popup.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <sstream>

#include "FlatFrame.h"
#include "GameState.h"
#include "Signals.h"

namespace godot {
class OnBoarding : public CanvasLayer {
	GODOT_CLASS(OnBoarding, CanvasLayer);

	int16_t currentStep = 0;
	Control *currentStepNode;

private:
	void _flat_detail_presentation();
	void _text_button_presentation();
	void _flat_detail_exit_presentation();
	void _next_cycle_presentation();

public:
	static void _register_methods();
	void _init();
	void _ready();
	void update_current_step_node();
	void last_step();
	void end_tour();

	void next_step();
};
} // namespace godot
#endif //MUNDANE_JAM_ONBOARDING_H
