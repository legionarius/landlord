//
// Created by bogdan on 31/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONBUTTON_H
#define MUNDANE_JAM_ACTIONBUTTON_H

#include "Action.h"
#include "Signals.h"
#include <Array.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <TextureButton.hpp>

namespace godot {

class ActionButton : public TextureButton {
	GODOT_CLASS(ActionButton, TextureButton);

private:
	Label *flat_number;
	Action *action;

public:
	void set_number(int64_t number);
	static void _register_methods();
	void _init();
	void _ready();
};

} // namespace godot
#endif //MUNDANE_JAM_ACTIONBUTTON_H
