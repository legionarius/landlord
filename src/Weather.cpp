//
// Created by bogdan on 17/03/2021.
//

#include "Weather.h"

using namespace godot;

void Weather::_on_animation_started() {
}

void Weather::_register_methods() {
	register_method("_init", &Weather::_init);
	register_method("_ready", &Weather::_ready);
	register_method("_process", &Weather::_process);
	register_method("_on_animation_started", &Weather::_on_animation_started);
}
void Weather::_init() {
	rng = RandomNumberGenerator()._new();
}
void Weather::_ready() {
	player = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	birds = cast_to<AnimatedSprite>(get_node("FlyingBirds"));
	clouds = cast_to<Sprite>(get_node("Cloud"));
	player->connect("animation_started", this, "_on_animation_started");
}
void Weather::_process(float delta) {
	if (!player->is_playing() && min_time > 15.f) {
		rng->randomize();
		real_t n = rng->randf_range(0, 20);
		real_t show_birds = rng->randf_range(0, 50);
		real_t show_cloud = rng->randf_range(0, 10);
		if (show_birds > 25.f) {
			birds->set_visible(true);
		} else {
			birds->set_visible(false);
		}
		if (show_cloud > 5.f) {
			clouds->set_visible(true);
		} else {
			clouds->set_visible(false);
		}
		if (n > 10.f) {
			player->play("flying_birds");
			min_time = 0.f;
		}
	}
	min_time += delta;
}
