//
// Created by nahalu on 01/04/2021.
//

#ifndef MUNDANE_JAM_REPORTFRAME_H
#define MUNDANE_JAM_REPORTFRAME_H

#include "Flat.h"
#include "Signals.h"

#include <BoxContainer.hpp>
#include <Button.hpp>
#include <Control.hpp>
#include <Color.hpp>
#include <DynamicFont.hpp>
#include <DynamicFontData.hpp>
#include <Godot.hpp>
#include <GridContainer.hpp>
#include <Label.hpp>
#include <Node.hpp>
#include <PopupDialog.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <iostream>
#include <sstream>

namespace godot {
class Flat;

class ReportFrame : public PopupDialog {
	GODOT_CLASS(ReportFrame, PopupDialog);

private:
	GridContainer *itemList;
	Ref<DynamicFontData> dynamicFont;
	Button *closeButton;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _hide();
	void add_entry(Flat *flat, bool hasPayed);
};
} // namespace godot

#endif //MUNDANE_JAM_REPORTFRAME_H
