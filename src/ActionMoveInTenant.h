//
// Created by acroquelois on 20/03/2021.
//

#ifndef MUNDANE_JAM_ACTIONMOVEINTENANT_H
#define MUNDANE_JAM_ACTIONMOVEINTENANT_H

#include <Godot.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

#include "Action.h"
#include "Flat.h"
#include "TenantIdentityCard.h"

class ActionMoveInTenant : public Action {

public:
	static std::string iconPath;
	static std::string iconPathSelected;

	ActionMoveInTenant(godot::Node *item, godot::TenantIdentityCard::Tenant *m_tenant, ActionType actionType = ACTION_MOVE_IN_TENANT): Action{ actionType, item }, tenant {m_tenant} {};
    godot::TenantIdentityCard::Tenant *tenant;

	void apply() override;
	godot::String get_texture_path() override {return godot::String(iconPath.c_str());};
};
#endif //MUNDANE_JAM_ACTIONMOVEINTENANT_H
