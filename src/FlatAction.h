//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATACTION_H
#define MUNDANE_JAM_FLATACTION_H

#include "Signals.h"
#include <Godot.hpp>
#include <TextureButton.hpp>

namespace godot {
class FlatAction : public TextureButton {
	GODOT_CLASS(FlatAction, TextureButton);

public:
	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATACTION_H
