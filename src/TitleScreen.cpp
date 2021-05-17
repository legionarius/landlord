//
// Created by bogdan on 24/02/2021.
//

#include "TitleScreen.h"

using namespace godot;

void TitleScreen::_init() {
}

void TitleScreen::_ready() {
	String osName = OS::get_singleton()->get_name();
	TextureButton *exitBtn = Object::cast_to<TextureButton>(get_node("MainMenu/Exit"));
	TextureButton *startBtn = Object::cast_to<TextureButton>(get_node("MainMenu/Start"));
	GameState *gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	sound = cast_to<AudioStreamPlayer>(get_node("Sound"));
	exitBtn->connect(BTN_PRESSED, this, "_exit");
	startBtn->connect(BTN_PRESSED, this, "_start");
	gameState->connect(UPDATE_VOLUME, this, "_update_sound_volume");
	if(osName == "HTML5"){
		exitBtn->set_visible(false);
	}
}

void TitleScreen::_exit() {
	get_tree()->quit();
}

void TitleScreen::_start() {
	get_tree()->change_scene("entity/MainScene/MainScene.tscn");
}

void TitleScreen::_input(const Ref<InputEvent> event) {
	Ref<InputEventKey> event_key = event;
	// Escape code taken from keyboard.h in Godot
	// TODO : include file in project
	if (event_key.is_valid() && event_key->is_pressed() && event_key->get_scancode() == ((1 << 24) | 0x01)) {
		_exit();
	}
}

void TitleScreen::_update_sound_volume(float_t volume) {
	sound->set_volume_db(volume);
}

void TitleScreen::_register_methods() {
	register_method("_init", &TitleScreen::_init);
	register_method("_ready", &TitleScreen::_ready);
	register_method("_exit", &TitleScreen::_exit);
	register_method("_start", &TitleScreen::_start);
	register_method("_input", &TitleScreen::_input);
	register_method("_update_sound_volume", &TitleScreen::_update_sound_volume);
}
