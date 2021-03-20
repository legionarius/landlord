//
// Created by acroquelois on 18/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONFIRETENANT_H
#define MUNDANE_JAM_ACTIONFIRETENANT_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include "Action.h"
#include "Flat.h"

class ActionFireTenant : public Action {

public:
	ActionFireTenant(int64_t id, ActionType actionType = ACTION_FIRE_TENANT): Action{ actionType, id } {};
	void apply(godot::Node * item) override;
};

#endif //MUNDANE_JAM_ACTIONFIRETENANT_H
