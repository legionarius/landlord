//
// Created by nahalu on 01/04/2021.
//

#include "ReportFrame.h"

using namespace godot;

void ReportFrame::_init() {}

void ReportFrame::_ready() {
	itemList = cast_to<GridContainer>(get_node("MarginContainer/Background/CenterContainer/ItemList"));
	closeButton = cast_to<Button>(get_node("Button"));
	closeButton->connect(BTN_PRESSED, this, "_hide");
	dynamicFont = ResourceLoader::get_singleton()->load("asset/font/CharlotteSouthern.otf");
}

void ReportFrame::_hide() {
	Array children = itemList->get_children();
	for (size_t i = 0; i < itemList->get_child_count(); i++) {
		itemList->get_child(i)->queue_free();
	}
	this->hide();
}

void ReportFrame::add_entry(Flat *flat, bool hasPayed) {
	Label *label = Label::_new();
	std::stringstream string;

	if (hasPayed) {
		string << "Flat N° " << flat->id << " has payed.";
	} else {
		string << "Flat N° " << flat->id << " hasn't payed.";
	}

	Ref<DynamicFont> font = DynamicFont::_new();
	font->set_font_data(dynamicFont);
	font->set_size(24);
	font->set_use_filter(true);
	label->set_text(string.str().c_str());
	label->add_font_override("font", font);
	label->add_color_override("font_color", Color(0, 0 ,0));
	itemList->add_child(label);
}

void ReportFrame::_register_methods() {
	register_method("_init", &ReportFrame::_init);
	register_method("_ready", &ReportFrame::_ready);
	register_method("_hide", &ReportFrame::_hide);
}
