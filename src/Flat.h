//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include "Signals.h"

namespace godot {
class Flat: public TextureButton {
	GODOT_CLASS(Flat, TextureButton);

	int64_t id;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_selection();
};
}

#endif //MUNDANE_JAM_FLAT_H
