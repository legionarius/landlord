//
// Created by acroquelois on 20/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONMOVEINTENANT_H
#define MUNDANE_JAM_ACTIONMOVEINTENANT_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include "Action.h"
#include "Flat.h"

class ActionMoveInTenant : public Action {

public:
	static godot::String iconPath = "res://asset/FlatFrame/move_in_action_button.png";
	static godot::String iconPathSelected = "res://asset/FlatFrame/move_in_action_button_selected.png";

	ActionMoveInTenant(int64_t id, ActionType actionType = ACTION_MOVE_IN_TENANT): Action{ actionType, id } {};
	void apply(godot::Node * item) override;
	godot::String get_texture_path() override {return iconPath};
};
#endif //MUNDANE_JAM_ACTIONMOVEINTENANT_H
