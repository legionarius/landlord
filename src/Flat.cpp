//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_init() {
}

void Flat::_ready() {
	connect("pressed", this, "_on_pressed");
	id = get_name().right(2).to_int();
	health = 50; // TODO: Randomize health
	rent = 350; // TODO: Randomize rent
}

void Flat::sign_lease(TenantIdentityCard::Tenant *tenant) {
	this->tenant = tenant;
	end_lease = 12; // TODO: Randomize the length of the lease.
}

void Flat::_on_pressed() {
	if (tenant != nullptr) {
		Godot::print(String(tenant->first_name) + " " + String(tenant->last_name) + " lives here.");
	}
	Ref<PackedScene> flatFrameScene = ResourceLoader::get_singleton()->load("entity/FlatFrame/FlatFrame.tscn");
	FlatFrame *flatFrame = cast_to<FlatFrame>(flatFrameScene->instance());
	flatFrame->_set_apartment_label(id);
	flatFrame->_set_health(health);
	flatFrame->_set_rent(rent);
	add_child(flatFrame);
	flatFrame->popup();
}

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_on_pressed", &Flat::_on_pressed);
}