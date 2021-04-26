//
// Created by acroquelois on 07/04/2021.
//

#ifndef MUNDANE_JAM_TENANTCHARACTER_H
#define MUNDANE_JAM_TENANTCHARACTER_H

#include <AnimationPlayer.hpp>
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>
#include <Timer.hpp>
#include <sstream>

namespace godot {
class TenantCharacter : public KinematicBody2D {
	GODOT_CLASS(TenantCharacter, KinematicBody2D);

	Node2D *characterShape;
	AnimationPlayer *characterAnimation;
	RandomNumberGenerator *rng;
	Timer *characterTimer;
	bool tenantSlideLeft = false;
	bool tenantIsIdle = false;
	float tenantSpeed = 10.0f;
	real_t pourcentageOfChanceToIdle = 40;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	void _reverse_shape();
	void _init_idle_timer();
	void launch_tenant_animation();
};
}

#endif //MUNDANE_JAM_TENANTCHARACTER_H
