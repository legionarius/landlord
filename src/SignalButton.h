//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_SIGNALBUTTON_H
#define MUNDANE_JAM_SIGNALBUTTON_H

#include <Godot.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <TextureButton.hpp>
#include "GameState.h"
#include "Signals.h"

namespace godot {
class SignalButton: public TextureButton {
	GODOT_CLASS(SignalButton, TextureButton);

	String _method_name;

public:
	static void _register_methods();
	void _init();
	void _ready();
};
}

#endif //MUNDANE_JAM_SIGNALBUTTON_H
