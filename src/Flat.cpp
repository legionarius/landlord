//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_init() {}

void Flat::_ready() {
	id = get_name().right(2).to_int();
	connect(BTN_PRESSED, this, "_on_selection");
}

void Flat::_on_selection() {
	Godot::print("Flat " + String(std::to_string(id).c_str()) + " selected");
	emit_signal(FLAT_SELECTED, id);
}

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_on_selection", &Flat::_on_selection);
	register_signal<Flat>(FLAT_SELECTED, "id", GODOT_VARIANT_TYPE_INT);
}