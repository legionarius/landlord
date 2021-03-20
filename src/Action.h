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
	Action(ActionType actionType, int64_t id): actionType{ actionType }, target_id{ id } {}
	~Action() = default;
	int64_t target_id;
	ActionType actionType;
	virtual void apply(godot::Node *item);
	virtual godot::String get_texture_path();
	static godot::String type_to_string(ActionType type);
};

#endif //MUNDANE_JAM_ACTION_H
