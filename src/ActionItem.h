//
// Created by bogdan on 07/04/2021.
//

#ifndef MUNDANE_JAM_ACTIONITEM_H
#define MUNDANE_JAM_ACTIONITEM_H

#include "Action.h"
#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <TextureButton.hpp>

namespace godot {

class ActionItem : public Control {
	GODOT_CLASS(ActionItem, Control);

	int flatId;
	ActionType actionType;
	Label *flatNumber;
	TextureButton *button;

public:
	void set_flat_number(int flatId);
	int get_flat_number();
	void set_action_type(int actionTypeOrdinal);
	ActionType get_action_type();

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_ACTIONITEM_H
