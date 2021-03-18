//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include <AnimationPlayer.hpp>
#include <AudioStreamPlayer.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Node2D.hpp>
#include <PopupDialog.hpp>
#include <ProgressBar.hpp>
#include <TextureButton.hpp>
#include <iomanip>

namespace godot {
class FlatFrame : public PopupDialog {
	GODOT_CLASS(FlatFrame, PopupDialog);

	String apartmentNameLabel;
	real_t healthLabel;
	String rentLabel;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_ExitButton_pressed();

	void _set_apartment_label(real_t id);
	void _set_health(real_t health);
	void _set_rent(real_t rent);
};
} // namespace godot

#endif //MUNDANE_JAM_FLATFRAME_H
