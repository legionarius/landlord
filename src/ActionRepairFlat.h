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
	ActionRepairFlat(godot::String name, int64_t id): Action { name, id } {};
	void apply(godot::Node * item) override;
};

#endif //MUNDANE_JAM_ACTIONREPAIRFLAT_H
