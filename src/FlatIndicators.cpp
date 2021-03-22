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
	notPayedIndicator = cast_to<TextureRect>(get_node("NotPayedIndicator"));
	indicatorsAnimation = cast_to<AnimationPlayer>(get_node("FlatIndicatorsAnimationPlayer"));
	repairIndicator->set_visible(false);
	leaveIndicator->set_visible(false);
	payedIndicator->set_visible(false);
	notPayedIndicator->set_visible(false);
}

void FlatIndicators::_show_indicators() {
	repairIndicator->set_visible(isRepairVisible);
	leaveIndicator->set_visible(isLeaveVisible);
	payedIndicator->set_visible(isPayedVisible);
	notPayedIndicator->set_visible(isNotPayedVisible);
	indicatorsAnimation->play("active");
}

void FlatIndicators::_hide_indicators() {
	repairIndicator->set_visible(false);
	leaveIndicator->set_visible(false);
	payedIndicator->set_visible(false);
	notPayedIndicator->set_visible(false);
	isRepairVisible = false;
	isLeaveVisible = false;
	isPayedVisible = false;
	isNotPayedVisible = false;
}

void FlatIndicators::_on_FlatIndicatorsAnimationPlayer_animation_finished() {
	_hide_indicators();
}

void FlatIndicators::_register_methods() {
	register_method("_init", &FlatIndicators::_init);
	register_method("_ready", &FlatIndicators::_ready);
	register_method("_show_indicators", &FlatIndicators::_show_indicators);
	register_method("_hide_indicators", &FlatIndicators::_hide_indicators);
	register_method("_on_FlatIndicatorsAnimationPlayer_animation_finished", &FlatIndicators::_on_FlatIndicatorsAnimationPlayer_animation_finished);
}