//
// Created by nahalu on 21/03/2021.
//

#include "FlatIndicators.h"

using namespace godot;

void FlatIndicators::_init() {
}

void FlatIndicators::_ready() {
	repairIndicator = cast_to<TextureRect>(get_node("RepairIndicator"));
	leaveIndicator = cast_to<TextureRect>(get_node("LeaveIndicator"));
	payedIndicator = cast_to<TextureRect>(get_node("PayedIndicator"));

	repairIndicator->set_visible(false);
	leaveIndicator->set_visible(false);
	payedIndicator->set_visible(false);
}

void FlatIndicators::_show_repair_indicator() {
	repairIndicator->set_visible(true);
}

void FlatIndicators::_show_leave_indicator() {
	leaveIndicator->set_visible(true);
}

void FlatIndicators::_show_payed_indicator() {
	payedIndicator->set_visible(true);
}

void FlatFrame::_register_methods() {
	register_method("_init", &FlatFrame::_init);
	register_method("_ready", &FlatFrame::_ready);
	register_method("_show_leave_indicator", &FlatFrame::_show_leave_indicator);
	register_method("_show_payed_indicator", &FlatFrame::_show_payed_indicator);
	register_method("_show_repair_indicator", &FlatFrame::_show_repair_indicator);
}