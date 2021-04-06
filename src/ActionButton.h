//
// Created by bogdan on 31/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONBUTTON_H
#define MUNDANE_JAM_ACTIONBUTTON_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include <Label.hpp>
#include <Array.hpp>
#include "Signals.h"

namespace godot {

class ActionButton : public TextureButton {
	GODOT_CLASS(ActionButton, TextureButton);

private:
	Label * flat_number;

public:
	void set_number(int64_t number);
	static void _register_methods();
	void _init();
	void _ready();
};

}
#endif //MUNDANE_JAM_ACTIONBUTTON_H
