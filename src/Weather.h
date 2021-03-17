//
// Created by bogdan on 17/03/2021.
//

#ifndef MUNDANE_JAM_WEATHER_H
#define MUNDANE_JAM_WEATHER_H

#include <AnimatedSprite.hpp>
#include <AnimationPlayer.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>
#include <Sprite.hpp>

namespace godot {
class Weather : public Node2D {
	GODOT_CLASS(Weather, Node2D);

	AnimationPlayer *player;
	AnimatedSprite *birds;
	Sprite *clouds;
	real_t min_time;

public:
	void _on_animation_started();

	static void _register_methods();
	void _process(float delta);
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_WEATHER_H
