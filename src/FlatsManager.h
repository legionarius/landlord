//
// Created by bogdan on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATSMANAGER_H
#define MUNDANE_JAM_FLATSMANAGER_H

#include "Action.h"
#include "Flat.h"
#include "GameState.h"
#include "MonthReport.h"
#include "TenantManager.h"

#include <Array.hpp>
#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <vector>

namespace godot {
class FlatsManager : public Node2D {
	GODOT_CLASS(FlatsManager, Node2D);

private:
	std::vector<Action *> actions;
	static const int8_t MAX_ACTIONS = 6;

public:
	void run_cycle();
	void add_action(Action *action);
	void add_tenants();
	void remove_action(Node *flat, ActionType actionType);
	bool action_will_be_executed_in_flat(Node *flat, ActionType actionType);
	real_t _collect_rent();
	void update_flats();
	real_t get_actions_cost();

	static void _register_methods();
	void _init();
	void _ready();
	void _add_action(int flatId, int actionTypeOrdinal);
	void queue_move_in_tenant(const bool isPressed, const int flatId, const uint64_t tenantId);
	void queue_fire_tenant(const bool isPressed, const int flatId);
	void queue_repair_flat(const bool isPressed, const int flatId);
	Node *get_flat(int flatId);
	bool can_add_action();
};
} // namespace godot

#endif //MUNDANE_JAM_FLATSMANAGER_H
