//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATSTATUS_H
#define MUNDANE_JAM_FLATSTATUS_H

namespace godot {
class FlatStatus : public TextureButton {
	GODOT_CLASS(FlatAction, TextureButton);

public:
	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATSTATUS_H
