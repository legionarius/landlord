//
// Created by bogdan on 16/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONREPAIRFLAT_H
#define MUNDANE_JAM_ACTIONREPAIRFLAT_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include "Action.h"
#include "Flat.h"

class ActionRepairFlat : public Action {

public:
	static std::string iconPath;
	static std::string iconPathSelected;

	ActionRepairFlat(int64_t id, ActionType actionType = ACTION_REPAIR_FLAT): Action{ actionType, id } {};
	void apply(godot::Node * item) override;
	godot::String get_texture_path() override {return godot::String(iconPath.c_str());};
};

#endif //MUNDANE_JAM_ACTIONREPAIRFLAT_H
