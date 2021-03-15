//
// Created by bogdan on 11/02/2021.
//

#include "TitleScreen.h"
#include "Flat.h"
#include "GameState.h"
#include "SignalButton.h"
#include "CycleInfo.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT
godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);
	godot::register_class<godot::TitleScreen>();
	godot::register_class<godot::Flat>();
	godot::register_class<godot::GameState>();
	godot::register_class<godot::SignalButton>();
	godot::register_class<godot::CycleInfo>();
}