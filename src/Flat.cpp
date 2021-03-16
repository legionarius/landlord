//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_init() {
	connect("pressed", this, "_on_pressed");
}

void Flat::_ready() {
	id = get_name().right(2).to_int();
}

void Flat::_on_pressed() {
	Ref<PackedScene> flatFrameScene = ResourceLoader::get_singleton()->load("entity/FlatFrame/FlatFrame.tscn");
	FlatFrame *flatFrame = cast_to<FlatFrame>(flatFrameScene->instance());
	if ( flatFrame == nullptr) {
		Godot::print("Err");
	} else {
		flatFrame->_set_appartment_label(id);
		// flatFrame->_set_health(health);
		flatFrame->popup();
	}
}

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_on_pressed", &Flat::_on_pressed);
	register_signal<Flat>("pressed");
}