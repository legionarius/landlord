//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_ACTION_H
#define MUNDANE_JAM_ACTION_H

#include <Godot.hpp>
#include <Node.hpp>
#include <string>

enum ActionType { ACTION_REPAIR_FLAT, ACTION_FIRE_TENANT };

class Action {
public:
	Action(ActionType actionType, godot::Node * item): actionType{ actionType }, target{ item } {}
	~Action() = default;
	godot::Node * target;
	ActionType actionType;
	virtual void apply();
	virtual real_t get_cost();
};

#endif //MUNDANE_JAM_ACTION_H
