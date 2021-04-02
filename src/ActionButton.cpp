//
// Created by bogdan on 31/03/2021.
//

#include "ActionButton.h"

using namespace godot;

void ActionButton::set_number(int64_t number) {
	auto values = Array::make(number);
	flat_number->set_text(String("{0}").format(values));
}

void ActionButton::_register_methods() {
	register_method("_init", &ActionButton::_init);
	register_method("_ready", &ActionButton::_ready);
}

void ActionButton::_init() {}

void ActionButton::_ready() {
	flat_number = cast_to<Label>(get_node("FlatNumber"));
	connect(BTN_PRESSED, this, "_on_pressed");
}
