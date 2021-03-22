//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelector.h"

using namespace godot;

real_t TenantSelector::maxTenantInSelector = 3;

void TenantSelector::_init() {}

void TenantSelector::_ready() {
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	Ref<Texture> hover_texture = ResourceLoader::get_singleton()->load("asset/Flat/hover_texture.png");
	Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
	for (size_t i = 0; i < maxTenantInSelector; i++) {
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(i);
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		TenantSelectorButton *tenantButtonSelector = TenantSelectorButton::_new();
		tenantButtonSelector->set_size(Vector2(190, 200));
		tenantButtonSelector->set_hover_texture(hover_texture);
		tenantButtonSelector->connect(TENANT_SELECTOR_PRESSED, this, "tenant_selected");
		tenantButtonSelector->set_tenant_id(tenant->id);
		tenantIdentityCard->set_tenant(tenant);
		tenantButtonSelector->set_position(Vector2(80,30));
		if(i != 0) {
			tenantButtonSelector->set_margin(0, 400 * i);
		}
		tenantButtonSelector->add_child(tenantIdentityCard);
		add_child(tenantButtonSelector);
	}
}

void TenantSelector::tenant_selected(uint64_t tenantId) {
	emit_signal(NEW_TENANT_SELECTED, tenantId);
}

void TenantSelector::_register_methods() {
	register_method("_init", &TenantSelector::_init);
	register_method("_ready", &TenantSelector::_ready);
	register_method("tenant_selected", &TenantSelector::tenant_selected);
	register_signal<TenantSelector>(NEW_TENANT_SELECTED, "isPressed", GODOT_VARIANT_TYPE_INT);
}
