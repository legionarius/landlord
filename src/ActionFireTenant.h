//
// Created by acroquelois on 18/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONFIRETENANT_H
#define MUNDANE_JAM_ACTIONFIRETENANT_H

#include "Action.h"
#include "Flat.h"
#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>

class ActionFireTenant : public Action {
public:
	static const std::string iconPath;
	static const std::string iconPathSelected;
	static const ActionType actionType = ACTION_FIRE_TENANT;

	ActionFireTenant(godot::Node *item) :
			Action{ item } {};
	void apply() override;
	virtual real_t get_cost() override;
	godot::String get_name() override;
	ActionType get_actionType() override;
	godot::String get_texture_path() override { return godot::String(iconPath.c_str()); };
};

#endif //MUNDANE_JAM_ACTIONFIRETENANT_H
