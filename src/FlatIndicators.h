//
// Created by nahalu on 21/03/2021.
//

#ifndef MUNDANE_JAM_FLATINDICATORS_H
#define MUNDANE_JAM_FLATINDICATORS_H

#include <AnimationPlayer.hpp>
#include <Godot.hpp>
#include <GridContainer.hpp>
#include <TextureRect.hpp>

namespace godot {
class FlatIndicators : public GridContainer {
	GODOT_CLASS(FlatIndicators, GridContainer);

	AnimationPlayer *indicatorsAnimation;
	TextureRect *repairIndicator;
	TextureRect *leaveIndicator;
	TextureRect *payedIndicator;
	TextureRect *notPayedIndicator;

public:
	static void _register_methods();
	void _init();
	void _ready();

	bool isRepairVisible = false;
	bool isLeaveVisible = false;
	bool isPayedVisible = false;
	bool isNotPayedVisible = false;

	void _show_indicators();
	void _hide_indicators();
	void _on_FlatIndicatorsAnimationPlayer_animation_finished();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATINDICATORS_H
