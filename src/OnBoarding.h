//
// Created by acroquelois on 12/04/2021.
//

#ifndef MUNDANE_JAM_ONBOARDING_H
#define MUNDANE_JAM_ONBOARDING_H

#include <Button.hpp>
#include <Control.hpp>
#include <Godot.hpp>
#include <Node.hpp>

namespace godot {
class OnBoarding : public Node {
	GODOT_CLASS(OnBoarding, Node);

	int16_t currentStep = 0;
	Control *step1;
	Control *step2;
	Control *step3;

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
