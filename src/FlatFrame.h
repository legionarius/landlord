//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <TextureButton.hpp>
#include <Label.hpp>
#include <iomanip>
#include <PopupDialog.hpp>

namespace godot {
class FlatFrame: public PopupDialog {
	GODOT_CLASS(FlatFrame, PopupDialog);

	String appartmentNameLabel;
	String healthLabel;


public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_ExitButton_pressed();

	void _set_appartment_label(int64_t id);
	void _set_health(int64_t health);

};
}


#endif //MUNDANE_JAM_FLATFRAME_H
