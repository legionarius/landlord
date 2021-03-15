//
// Created by nahalu on 15/03/2021.
//

#include "FlatFrame.h"

using namespace godot;

void FlatFrame::_init() {}

void FlatFrame::_ready() {}

void FlatFrame::_show_frame() {
	visible = true
}

void FlatFrame::_exit_frame() {
	visible = false
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_exit_frame", &FlatFrame::_exit_frame);
	register_signal<FlatFrame>("_show_frame");
}