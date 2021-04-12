//
// Created by acroquelois on 12/04/2021.
//

#ifndef MUNDANE_JAM_ONBOARDING_H
#define MUNDANE_JAM_ONBOARDING_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class OnBoarding : public Node2D {
	GODOT_CLASS(OnBoarding, Node2D);

	int16_t currentStep = 0;

private:
	void _game_presentation();
	void _flat_presentation();
	void _tenant_presentation();
	void _cycle_presentation();

public:
	static void _register_methods();
	void _init();
	void _ready();

	void next_step();
};
} // namespace godot
#endif //MUNDANE_JAM_ONBOARDING_H
