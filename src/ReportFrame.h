//
// Created by nahalu on 01/04/2021.
//

#ifndef MUNDANE_JAM_REPORTFRAME_H
#define MUNDANE_JAM_REPORTFRAME_H

#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <PopupDialog.hpp>

namespace godot {
class ReportFrame : public PopupDialog {
	GODOT_CLASS(ReportFrame, PopupDialog);

public:
private:
	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_REPORTFRAME_H
