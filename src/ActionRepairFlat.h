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
	ActionRepairFlat(godot::Node * item, ActionType actionType = ACTION_REPAIR_FLAT): Action{ actionType, item } {};
	void apply() override;
	virtual real_t get_cost() override;
};

#endif //MUNDANE_JAM_ACTIONREPAIRFLAT_H
