//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_ACTION_H
#define MUNDANE_JAM_ACTION_H

#include <Godot.hpp>
#include <Node.hpp>
#include <string>

class Action {
public:
	Action(godot::String name, int64_t id): name{ name }, target_id{ id } {}
	~Action() = default;
	int64_t target_id;
	godot::String name;
	void apply(godot::Node *item);
};

#endif //MUNDANE_JAM_ACTION_H
