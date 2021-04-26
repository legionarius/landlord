//
// Created by bogdan on 07/04/2021.
//

#include "ActionItem.h"

using namespace godot;

void ActionItem::_register_methods() {
	register_method("_init", &ActionItem::_init);
	register_method("_ready", &ActionItem::_ready);
}

void ActionItem::_init() {
	flatId = 0;
}

void ActionItem::_ready() {
	flatNumber = cast_to<Label>(get_node("ActionButton/FlatNumber"));
	button = cast_to<TextureButton>(get_node("ActionButton"));
	flatNumber->set_text(std::to_string(flatId).c_str());
	switch (actionType) {
		case ACTION_MOVE_IN_TENANT:
			break;
		case ACTION_REPAIR_FLAT:
			break;
		case ACTION_FIRE_TENANT:
			break;
		default:
			Godot::print("DEFAULT");
	}
}

void ActionItem::set_flat_number(int flatId) {
	this->flatId = flatId;
}

void ActionItem::set_action_type(int actionTypeOrdinal) {
	this->actionType = static_cast<ActionType>(actionTypeOrdinal);
}

int ActionItem::get_flat_number() {
	return flatId;
}

ActionType ActionItem::get_action_type() {
	return actionType;
}
