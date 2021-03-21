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
	static std::string iconPath;
	static std::string iconPathSelected;

	ActionFireTenant(godot::Node *item, ActionType actionType = ACTION_FIRE_TENANT): Action{ actionType, item } {};
	void apply() override;
	virtual real_t get_cost() override;
	godot::String get_texture_path() override {return godot::String(iconPath.c_str());};
};

#endif //MUNDANE_JAM_ACTIONFIRETENANT_H
