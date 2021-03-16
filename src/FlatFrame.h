//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <TextureButton.hpp>
#include "Flat.h"
#include <Label.hpp>
#include <iomanip>
#include <PopupDialog.hpp>

namespace godot {
class FlatFrame: public PopupDialog {
	GODOT_CLASS(FlatFrame, PopupDialog);

	Label *appartmentNameLabel;
	Label *healthLabel;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _set_characteristics(Flat *flat);
	void _on_ExitButton_pressed();
};
}


#endif //MUNDANE_JAM_FLATFRAME_H
