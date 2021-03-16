//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include "Signals.h"
#include <PopupDialog.hpp>
#include "Viewport.hpp"
#include "SceneTree.hpp"
#include "FlatFrame.h"
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

namespace godot {
class Flat: public TextureButton {
	GODOT_CLASS(Flat, TextureButton);

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();

	int64_t id;
	int64_t rent;
	int64_t health;
};
}

#endif //MUNDANE_JAM_FLAT_H
