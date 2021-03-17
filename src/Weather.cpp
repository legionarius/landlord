//
// Created by bogdan on 17/03/2021.
//

#include "Weather.h"

using namespace godot;

void Weather::_on_animation_started() {
	Godot::print("Animation started");
}

void Weather::_register_methods() {
	register_method("_init", &Weather::_init);
	register_method("_ready", &Weather::_ready);
	register_method("_process", &Weather::_process);
	register_method("_on_animation_started", &Weather::_on_animation_started);
}
void Weather::_init() {

}
void Weather::_ready() {
	player = cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	birds = cast_to<AnimatedSprite>(get_node("FlyingBirds"));
	clouds = cast_to<Sprite>(get_node("Cloud"));
	player->connect("animation_started", this, "_on_animation_started");
}
void Weather::_process(float delta) {
	if (!player->is_playing() && min_time > 15.f) {
		auto rnd = RandomNumberGenerator()._new();
		rnd->set_seed(1894720573047910);
		real_t n = rnd->randf_range(0, 20);
		auto rnd2 = RandomNumberGenerator()._new();
		real_t show_birds = rnd2->randf_range(0, 50);
		real_t show_cloud = rnd2->randf_range(0, 10);
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
