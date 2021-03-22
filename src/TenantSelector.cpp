//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelector.h"

using namespace godot;

void TenantSelector::_init() {}

void TenantSelector::_ready() {}

void TenantSelector::_register_methods() {
	register_method("_init", &TenantSelector::_init);
	register_method("_ready", &TenantSelector::_ready);
}
