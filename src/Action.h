//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_ACTION_H
#define MUNDANE_JAM_ACTION_H

#include <Godot.hpp>
#include <Node.hpp>
#include <string>

enum ActionType { ACTION_REPAIR_FLAT, ACTION_FIRE_TENANT, ACTION_MOVE_IN_TENANT};

class Action {
public:
	Action(ActionType actionType, godot::Node *item): actionType{ actionType }, target{ item } {}
	~Action() = default;
	godot::Node *target;
	ActionType actionType;
	virtual void apply();
	virtual real_t get_cost();
	virtual godot::String get_texture_path();
	static godot::String type_to_string(ActionType type);
};

#endif //MUNDANE_JAM_ACTION_H
