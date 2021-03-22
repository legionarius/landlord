//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelector.h"

using namespace godot;

real_t TenantSelector::maxTenantInSelector = 3;

void TenantSelector::_init() {}

void TenantSelector::_ready() {
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	for (size_t i = 0; i < maxTenantInSelector; i++) {
		TextureButton *textureButton = TextureButton::_new();
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(i);
		Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		tenantIdentityCard->set_tenant(tenant);
		tenantIdentityCard->set_position(Vector2(80,30));
		if(i != 0) {
			tenantIdentityCard->set_margin(0, 400 * i);
		}
		textureButton->add_child(tenantIdentityCard);
		add_child(textureButton);
		Godot::print("Child added");
	}
}

void TenantSelector::_register_methods() {
	register_method("_init", &TenantSelector::_init);
	register_method("_ready", &TenantSelector::_ready);
}
