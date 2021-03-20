//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_init() {
	rng = RandomNumberGenerator()._new();
	rng->randomize();
	health = rng->randi_range(0, 100);
	rent = rng->randf_range(100, 500);
	update_charge();
}

// Should be run after each cycle when
// the flat health changes.
void Flat::update_charge() {
	// Charge :
	// - 50% of the rent
	// - Bonus of 25% of the health (remove the bonus from the charge)
	charge = (rent * 50.f) / 100.f - (health * 0.25);
}

void Flat::_ready() {
	connect("pressed", this, "_on_pressed");
	id = get_name().right(2).to_int();
}

void Flat::sign_lease(TenantIdentityCard::Tenant *tenant) {
	this->tenant = tenant;
	end_lease = 12; // TODO: Randomize the length of the lease.
}

void Flat::_on_pressed() {
	Ref<PackedScene> flatFrameScene = ResourceLoader::get_singleton()->load("entity/FlatFrame/FlatFrame.tscn");
	FlatFrame *flatFrame = cast_to<FlatFrame>(flatFrameScene->instance());
	flatFrame->_set_apartment_label(id);
	flatFrame->_set_health(health);
	flatFrame->_set_rent(rent);
	flatFrame->_set_tenant(tenant);
	add_child(flatFrame);
	flatFrame->popup();
}

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_on_pressed", &Flat::_on_pressed);
}
real_t Flat::break_legs_and_collect_money() {
	if (tenant != nullptr) {
		rng->randomize();
		real_t n = rng->randf_range(0, 1);
		if (n < (tenant->confidence / 100.f)) {
			Godot::print("[RENT]: payed for flat " + String(std::to_string(id).c_str()));
			return rent - charge;
		} else {
			Godot::print("[RENT]: NOT payed for flat " + String(std::to_string(id).c_str()));
			return 0.f;
		}
	} else {
		return 0.f;
	}
}
