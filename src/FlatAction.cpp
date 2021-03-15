//
// Created by nahalu on 15/03/2021.
//

#include "FlatAction.h"

using namespace godot;

void FlatAction::_init() {}

void FlatAction::_ready() {}

void FlatAction::_register_methods() {
	register_method("_init", &FlatAction::_init);
	register_method("_ready", &FlatAction::_ready);
}