//
// Created by nahalu on 21/03/2021.
//

#ifndef MUNDANE_JAM_FLATINDICATORS_H
#define MUNDANE_JAM_FLATINDICATORS_H

#include <AnimationPlayer.hpp>
#include <GridContainer.hpp>
#include <TextureRect.hpp>

namespace godot {
class FlatIndicators : public GriContainer {
	GODOT_CLASS(FlatIndicators, GriContainer);

	AnimationPlayer *indicatorsAnimation;
	TextureRect *repairIndicator;
	TextureRect *leaveIndicator;
	TextureRect *payedIndicator;

public:
	static void _register_methods();
	void _init();
	void _ready();

	void _show_repair_indicator();
	void _show_leave_indicator();
	void _show_payed_indicator();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATINDICATORS_H
