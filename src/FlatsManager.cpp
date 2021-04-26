//
// Created by bogdan on 15/03/2021.
//

#include "FlatsManager.h"
#include <iostream>

using namespace godot;

void FlatsManager::_init() {
}

void FlatsManager::_ready() {
	add_tenants();
	reportFrame = cast_to<ReportFrame>(get_tree()->get_root()->get_node("MainScene/ReportFrame"));
}

void FlatsManager::add_tenants() {
	Array flats = get_children();
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	for (size_t i = 0; i < flats.size(); i++) {
		Flat *flat = cast_to<Flat>(flats[i]);
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(i + 1);
		flat->sign_lease(tenant);
		flat->update_tenant_presence();
	}
}

real_t FlatsManager::_collect_rent() {
	real_t money = 0.f;
	Array flats = get_children();
	for (size_t i = 0; i < flats.size(); i++) {
		// flats[i]
		std::cout << flats[i].get_type() << std::endl;
		Flat *flat = cast_to<Flat>(flats[i]);
		real_t rent = flat->break_legs_and_collect_money();
		if (rent == 0) {
			reportFrame->add_entry(flat, false);
		} else {
			reportFrame->add_entry(flat, true);
		}
		money += rent;
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
		flat->fire_tenant_if_end_leasing();
		flat->update_charge();
		flat->update_health();
		flat->update_tenant_presence();
	}
}

void FlatsManager::add_action(Action *m_action) {
	actions.push_back(m_action);
	get_actions_cost();
	emit_signal(ACTION_COUNT, static_cast<int64_t>(actions.size()), MAX_ACTIONS);
}

void FlatsManager::remove_action(Node *flat, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->get_actionType() == actionType) && (cast_to<Flat>(action->target) == cast_to<Flat>(flat))) {
			auto pos = std::find(actions.begin(), actions.end(), action);
			actions.erase(pos);
			get_actions_cost();
			emit_signal(ACTION_COUNT, static_cast<int64_t>(actions.size()), MAX_ACTIONS);
		}
	}
}

bool FlatsManager::action_will_be_executed_in_flat(Node *flat, ActionType actionType) {
	for (Action *action : actions) {
		if ((action->get_actionType() == actionType) && (cast_to<Flat>(action->target) == cast_to<Flat>(flat))) {
			return true;
		}
	}
	return false;
}

real_t FlatsManager::get_actions_cost() {
	real_t cost = 0;
	for (Action *action : actions) {
		cost += action->get_cost();
	}
	emit_signal(ACTIONS_COST, cost);
	return cost;
}

void FlatsManager::_add_action(int flatId, int actionTypeOrdinal) {
	auto actionType = static_cast<ActionType>(actionTypeOrdinal);
	switch (actionType) {
		case ACTION:
			break;
		case ACTION_REPAIR_FLAT:
			Godot::print("Repairing Flat");
			break;
		case ACTION_FIRE_TENANT:
			Godot::print("Fire Tenant");
			break;
		case ACTION_MOVE_IN_TENANT:
			Godot::print("Move In Tenant");
			break;
	}
}

void FlatsManager::queue_move_in_tenant(const bool isPressed, const int flatId, const uint64_t tenantId) {
	if (isPressed) {
		TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(tenantId - 1);
		ActionMoveInTenant *actionMoveInTenant = new ActionMoveInTenant(get_flat(flatId), tenant);
		add_action(actionMoveInTenant);
		emit_signal(ADD_ACTION, flatId, ActionMoveInTenant::actionType);
	} else {
		remove_action(get_flat(flatId), ACTION_MOVE_IN_TENANT);
		emit_signal(REMOVE_ACTION, flatId, ActionMoveInTenant::actionType);
	}
}

void FlatsManager::queue_fire_tenant(const bool isPressed, const int flatId) {
	if (isPressed) {
		ActionFireTenant *actionFireTenant = new ActionFireTenant(get_flat(flatId));
		add_action(actionFireTenant);
		emit_signal(ADD_ACTION, flatId, ActionFireTenant::actionType);
	} else {
		remove_action(get_flat(flatId), ACTION_FIRE_TENANT);
		emit_signal(REMOVE_ACTION, flatId, ActionFireTenant::actionType);
	}
}

void FlatsManager::queue_repair_flat(const bool isPressed, const int flatId) {
	if (isPressed) {
		ActionRepairFlat *actionRepairFlat = new ActionRepairFlat(get_flat(flatId));
		if (!action_will_be_executed_in_flat(get_flat(flatId), ACTION_REPAIR_FLAT)) {
			add_action(actionRepairFlat);
			emit_signal(ADD_ACTION, flatId, ActionRepairFlat::actionType);
		}
	} else {
		remove_action(get_flat(flatId), ACTION_REPAIR_FLAT);
		emit_signal(REMOVE_ACTION, flatId, ActionRepairFlat::actionType);
	}
}

Node *FlatsManager::get_flat(int flatId) {
	return get_children()[flatId - 1];
}

bool FlatsManager::can_add_action() {
	return actions.size() < MAX_ACTIONS;
}

void FlatsManager::_register_methods() {
	register_method("_init", &FlatsManager::_init);
	register_method("_ready", &FlatsManager::_ready);
	register_method("_add_action", &FlatsManager::_add_action);
	register_method("queue_move_in_tenant", &FlatsManager::queue_move_in_tenant);
	register_method("queue_repair_flat", &FlatsManager::queue_repair_flat);
	register_method("queue_fire_tenant", &FlatsManager::queue_fire_tenant);
	register_signal<FlatsManager>(ACTIONS_COST, "cost", GODOT_VARIANT_TYPE_REAL);
	register_signal<FlatsManager>(ADD_ACTION, GODOT_VARIANT_TYPE_INT, "flatId", GODOT_VARIANT_TYPE_INT, "actionType");
	register_signal<FlatsManager>(REMOVE_ACTION, GODOT_VARIANT_TYPE_INT, "flatId", GODOT_VARIANT_TYPE_INT, "actionType");
	register_signal<FlatsManager>(ACTION_COUNT, GODOT_VARIANT_TYPE_INT, "current", GODOT_VARIANT_TYPE_INT, "max");
}
