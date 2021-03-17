//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include "FlatFrame.h"
#include "SceneTree.hpp"
#include "Signals.h"
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <PopupDialog.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <TextureButton.hpp>
#include <Viewport.hpp>

namespace godot {
class Flat : public TextureButton {
	GODOT_CLASS(Flat, TextureButton);

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();

	real_t id;
	real_t rent;
	real_t health;
};
} // namespace godot

#endif //MUNDANE_JAM_FLAT_H
