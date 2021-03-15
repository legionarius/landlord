//
// Created by bogdan on 25/02/2021.
//

#ifndef MUNDANE_JAM_GAMESTATE_H
#define MUNDANE_JAM_GAMESTATE_H

#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Node.hpp>


namespace godot {
class GameState : public Node {
	GODOT_CLASS(GameState, Node);

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
};
} // namespace godot

#endif //MUNDANE_JAM_GAMESTATE_H
