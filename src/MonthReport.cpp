//
// Created by bogdan on 21/03/2021.
//

#include "MonthReport.h"

using namespace godot;

void MonthReport::_init() {}

void MonthReport::_ready() {
	richTextLabel = cast_to<RichTextLabel>(get_node("Logs"));
}

void MonthReport::_add_entry(String entry) {
	richTextLabel->add_text(entry);
}

void MonthReport::_flush() {
	richTextLabel->clear();
}

void MonthReport::_register_methods() {
	register_method("_init", &MonthReport::_init);
	register_method("_ready", &MonthReport::_ready);
}