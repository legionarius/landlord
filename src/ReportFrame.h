//
// Created by nahalu on 01/04/2021.
//

#ifndef MUNDANE_JAM_REPORTFRAME_H
#define MUNDANE_JAM_REPORTFRAME_H

#include "Signals.h"

#include "Label.hpp"
#include <Control.hpp>
#include <Godot.hpp>
#include <ItemList.hpp>
#include <Label.hpp>
#include <PopupDialog.hpp>

namespace godot {
class ReportFrame : public PopupDialog {
	GODOT_CLASS(ReportFrame, PopupDialog);

private:
	ItemList *itemList;
	Label *label;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pre_show();
	void _hide();
	void add_entry(String entry);
};
} // namespace godot

#endif //MUNDANE_JAM_REPORTFRAME_H
