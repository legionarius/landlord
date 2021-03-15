//
// Created by nahalu on 15/03/2021.
//

#include "FlatStatus.h"

using namespace godot;

void FlatStatus::_init() {}

void FlatStatus::_ready() {}

void FlatStatus::_register_methods() {
	register_method("_init", &FlatStatus::_init);
	register_method("_ready", &FlatStatus::_ready);
}