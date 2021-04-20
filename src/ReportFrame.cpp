//
// Created by nahalu on 01/04/2021.
//

#include "ReportFrame.h"

using namespace godot;

void ReportFrame::_init() {}

void ReportFrame::_ready() {
	itemList = Object::cast_to<BoxContainer>(get_node("MarginContainer/Background/CenterContainer/ItemList"));
	closeButton = Object::cast_to<Button>(get_node("Button"));
	// font = DynamicFont::_new();
	// Ref<DynamicFontData> data = ResourceLoader::get_singleton()->load("res://asset/font/CharlotteSouthern.otf");
	// font->set_font_data(data);
	closeButton->connect("pressed", this, "_hide");
	connect(POPUP_ABOUT_TO_SHOW, this, "_on_pre_show");
}

void ReportFrame::_on_pre_show() {
}

void ReportFrame::_hide() {
	Array childrens = itemList->get_children();
	for (size_t i = 0; i < childrens.size(); i++) {
		Object::cast_to<Node>(childrens[i])->queue_free();
	}
	this->hide();
}

void ReportFrame::add_entry(Flat *flat, bool hasPayed) {
	Label *label = Label::_new();
	// label->add_font_override("test", font);

	std::stringstream string;

	if (hasPayed) {
		string << "Flat N° " << flat->id << " has payed.";
	} else {
		string << "Flat N° " << flat->id << " hasn't payed.";
	}

	label->set_text(string.str().c_str());
	itemList->add_child(label);
}

void ReportFrame::_register_methods() {
	register_method("_init", &ReportFrame::_init);
	register_method("_ready", &ReportFrame::_ready);
	register_method("_on_pre_show", &ReportFrame::_on_pre_show);
	register_method("_hide", &ReportFrame::_hide);
}
