//
// Created by acroquelois on 12/04/2021.
//

#ifndef MUNDANE_JAM_MAINSCENE_H
#define MUNDANE_JAM_MAINSCENE_H

#include <Godot.hpp>
#include <Node2D.hpp>

#include "GameState.h"

namespace godot {
class MainScene : public Node2D {
GODOT_CLASS(GameState, Node2D);

public:
	static void _register_methods();
	void _init();
	void _ready();
};
}

#endif //MUNDANE_JAM_MAINSCENE_H
