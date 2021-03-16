//
// Created by bogdan on 16/03/2021.
//

#ifndef MUNDANE_JAM_REPAIRFLATACTION_H
#define MUNDANE_JAM_REPAIRFLATACTION_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include "Action.h"
#include "Flat.h"

class RepairFlatAction : public Action {

public:
	RepairFlatAction(godot::String name, int64_t id): Action { name, id } {};
	void apply(godot::Node * item) override;
};

#endif //MUNDANE_JAM_REPAIRFLATACTION_H
