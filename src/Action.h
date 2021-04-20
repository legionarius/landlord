//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_ACTION_H
#define MUNDANE_JAM_ACTION_H

#include <Godot.hpp>
#include <Node.hpp>
#include <string>

enum ActionType {
	ACTION,
	ACTION_REPAIR_FLAT,
	ACTION_FIRE_TENANT,
	ACTION_MOVE_IN_TENANT
};

class Action {
public:
	Action(godot::Node *item) :
			target{ item } {}
	~Action() = default;
	godot::Node *target;
	static const ActionType actionType = ACTION;
	virtual ActionType get_actionType();
	virtual godot::String get_name();
	virtual void apply();
	virtual real_t get_cost();
	virtual godot::String get_texture_path();
};

#endif //MUNDANE_JAM_ACTION_H
