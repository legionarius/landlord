//
// Created by acroquelois on 02/04/2021.
//

#ifndef MUNDANE_JAM_ENDSCREEN_H
#define MUNDANE_JAM_ENDSCREEN_H

#include "GameState.h"

#include <Button.hpp>
#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <sstream>

namespace godot {
class EndScreen : public Control {
	GODOT_CLASS(EndScreen, Control);

	GameState *gameState;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _restartGame();
	void _exitGame();
};
} // namespace godot

#endif //MUNDANE_JAM_ENDSCREEN_H
