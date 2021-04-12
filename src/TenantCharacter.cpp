//
// Created by acroquelois on 07/04/2021.
//

#include "TenantCharacter.h"

using namespace godot;

void TenantCharacter::_init() {
	rng = RandomNumberGenerator()._new();
	rng->randomize();
}

void TenantCharacter::_ready() {
	characterShape = cast_to<Node2D>(get_node("CharacterShape"));
	characterAnimation = cast_to<AnimationPlayer>(get_node("PlayerComportement"));
	characterTimer = cast_to<Timer>(get_node("Timer"));
	characterTimer->connect("timeout", this, "launch_tenant_animation");
	launch_tenant_animation();
}

void TenantCharacter::_process(float delta) {
	if(!tenantIsIdle){
		const float slideX = tenantSlideLeft ? -tenantSpeed : tenantSpeed;
		move_and_slide(Vector2(slideX*(1+delta), 0));
		if(is_on_wall()){
			_reverse_shape();
			tenantSlideLeft = !tenantSlideLeft;
		}
	}
}

void TenantCharacter::_reverse_shape() {
	characterShape->apply_scale(Vector2(-1, 1));
}

void TenantCharacter::launch_tenant_animation() {
	const int64_t rngInitIdle = rng->randi_range(0, 100);
	tenantIsIdle = false;
	characterAnimation->play("Arrival");
	if(rngInitIdle <= pourcentageOfChanceToIdle) {
		characterAnimation->play("Idle");
		tenantIsIdle = true;
	}
	characterTimer->start(rngInitIdle/3);
}


void TenantCharacter::_register_methods() {
	register_method("_init", &TenantCharacter::_init);
	register_method("_ready", &TenantCharacter::_ready);
	register_method("_process", &TenantCharacter::_process);
	register_method("launch_tenant_animation", &TenantCharacter::launch_tenant_animation);
}