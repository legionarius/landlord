//
// Created by nahalu on 01/04/2021.
//

#include "ReportFrame.h"

using namespace godot;

void ReportFrame::_init() {}

void ReportFrame::_ready() {
	itemList = cast_to<ItemList>(get_node("ReportFrame/MarginContainer/Background/CenterContainer/ItemList"));
	connect(POPUP_ABOUT_TO_SHOW, this, "_on_pre_show");
}

void ReportFrame::_on_pre_show() {
}

void ReportFrame::_hide() {
	itemList->clear();
	this->hide();
}

void ReportFrame::add_entry(String entry) {
	label = Label::_new();
	label->set_text(entry);
}

void ReportFrame::_register_methods() {
	register_method("_init", &ReportFrame::_init);
	register_method("_ready", &ReportFrame::_ready);
	register_method("_on_pre_show", &ReportFrame::_on_pre_show);
	register_method("_hide", &ReportFrame::_hide);
	register_method("add_entry", &ReportFrame::add_entry);
}
