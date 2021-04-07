//
// Created by nahalu on 01/04/2021.
//

#include "ReportFrame.h"

using namespace godot;

void ReportFrame::_init() {}

void ReportFrame::_ready() {
	connect(POPUP_ABOUT_TO_SHOW, this, "_on_pre_show");
}

void ReportFrame::_on_pre_show() {}

void ReportFrame::_register_methods() {}
