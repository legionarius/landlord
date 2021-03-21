//
// Created by bogdan on 15/03/2021.
//

#include "FlatsManager.h"

using namespace godot;

void FlatsManager::_init() {
}

void FlatsManager::_ready() {
	add_tenants();
}

void FlatsManager::add_tenants() {
	Array flats = get_children();
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	for (size_t i = 0; i < flats.size(); i++) {
		Flat *flat = cast_to<Flat>(flats[i]);
		flat->sign_lease(tenantManager->get_tenant(i));
	}
}

real_t FlatsManager::_collect_rent() {
	real_t money = 0.f;
	Array flats = get_children();
	for (size_t i = 0; i < flats.size(); i++) {
		Flat *flat = cast_to<Flat>(flats[i]);
		money += flat->break_legs_and_collect_money();
	}
	return money;
}

void FlatsManager::run_cycle() {
	while (!actions.empty()) {
		Action *action = actions.back();
		action->apply();
		actions.pop_back();
	}
	update_flats();
}

// After actions are run we update
// the flat charges
void FlatsManager::update_flats() {
	Array flats = get_children();
	for (size_t i = 0; i < flats.size(); i++) {
		Flat *flat = cast_to<Flat>(flats[i]);
		flat->update_charge();
	}
}

void FlatsManager::add_action(Action *m_action) {
	for (Action *action : actions) {
		if ((action->actionType == m_action->actionType) && (action->target == m_action->target)) {
			// Action already registered
			return;
		}
	}
	actions.push_back(m_action);
	get_actions_cost();
}

void FlatsManager::remove_action(Node * flat, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->actionType == actionType) && (action->target == flat)) {
			std::erase(actions, action);
		}
	}
}

bool FlatsManager::action_will_be_executed_in_flat(Node *  flat, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->actionType == actionType) && (action->target == flat)) {
			return true;
		}
	}
	return false;
}

real_t FlatsManager::get_actions_cost() {
	real_t cost = 0;
	for (Action *action: actions) {
		cost += action->get_cost();
	}
	emit_signal(ACTIONS_COST, cost);
	return cost;
}

void FlatsManager::_register_methods() {
	register_method("_init", &FlatsManager::_init);
	register_method("_ready", &FlatsManager::_ready);
	register_signal<FlatsManager>(ACTIONS_COST, "cost", GODOT_VARIANT_TYPE_REAL);
}
