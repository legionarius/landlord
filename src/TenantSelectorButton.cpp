//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelectorButton.h"

using namespace godot;

void TenantSelectorButton::_init() {}

void TenantSelectorButton::_ready() {
	connect("pressed", this, "_on_pressed");
}

void TenantSelectorButton::_on_pressed(){
	emit_signal(TENANT_SELECTOR_PRESSED, tenantId);
}

void TenantSelectorButton::_register_methods() {
	register_method("_init", &TenantSelectorButton::_init);
	register_method("_ready", &TenantSelectorButton::_ready);
	register_method("_on_pressed", &TenantSelectorButton::_on_pressed);
	register_signal<TenantSelectorButton>(TENANT_SELECTOR_PRESSED, "tenantId", GODOT_VARIANT_TYPE_INT);
}