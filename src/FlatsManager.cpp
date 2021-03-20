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

void FlatsManager::_register_methods() {
	register_method("_init", &FlatsManager::_init);
	register_method("_ready", &FlatsManager::_ready);
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
		Array flats = get_children();
		action->apply(flats[action->target_id - 1]);
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
		if ((action->actionType == m_action->actionType) && (action->target_id == m_action->target_id)) {
			// Action already registered
			return;
		}
	}
	actions.push_back(m_action);
}

void FlatsManager::remove_action(real_t apartmentId, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->actionType == actionType) && (action->target_id == apartmentId)) {
			std::erase(actions, action);
		}
	}
}

bool FlatsManager::action_will_be_executed_in_apartment(real_t apartmentId, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->actionType == actionType) && (action->target_id == apartmentId)) {
			return true;
		}
	}
	return false;
}