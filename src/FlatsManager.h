//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATSMANAGER_H
#define MUNDANE_JAM_FLATSMANAGER_H

#include "Action.h"
#include "Flat.h"
#include "TenantManager.h"
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Array.hpp>
#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <vector>

namespace godot {
class FlatsManager : public Node2D {
	GODOT_CLASS(FlatsManager, Node2D);

private:
	std::vector<Action*> actions;

public:
	void run_cycle();
	void add_action(Action * action);
	void add_tenants();
	void remove_action(Node * flat, ActionType actionType);
	bool action_will_be_executed_in_flat(Node * flat, ActionType actionType);
	real_t _collect_rent();
	void update_flats();
	real_t get_actions_cost();

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATSMANAGER_H
