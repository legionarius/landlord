//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelector.h"

using namespace godot;

int64_t TenantSelector::maxTenantInSelector = 3;

void TenantSelector::_init() {}

void TenantSelector::_ready() {
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	Node *selectorBackground = get_node("TenantSelectorBackground");
	TextureButton *exitSelector = cast_to<TextureButton>(get_node("ExitSelector"));
	exitSelector->connect("pressed", this, "exit_selector");
	Ref<Texture> hover_texture = ResourceLoader::get_singleton()->load("asset/Flat/hover_texture.png");
	Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
	for (int64_t i = 0; i < maxTenantInSelector; i++) {
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(i);
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		TenantSelectorButton *tenantButtonSelector = TenantSelectorButton::_new();
		tenantButtonSelector->set_size(Vector2(190, 200));
		tenantButtonSelector->set_hover_texture(hover_texture);
		tenantButtonSelector->connect(TENANT_SELECTOR_PRESSED, this, "tenant_selected");
		std::stringstream test;
		test << "SETTER id: " << std::to_string(tenant->id);
		Godot::print(test.str().c_str());
		tenantButtonSelector->set_tenant_id(tenant->id);
		tenantIdentityCard->set_tenant(tenant);
		tenantButtonSelector->set_position(Vector2(0,30));
		tenantButtonSelector->set_margin(0, 200 * (i+1));
		tenantButtonSelector->add_child(tenantIdentityCard);
		selectorBackground->add_child(tenantButtonSelector);
	}
}

void TenantSelector::tenant_selected(int64_t tenantId) {
	std::stringstream test;
	test << "SIGNAL OUT: " << std::to_string(tenantId);
	Godot::print(test.str().c_str());
	emit_signal(NEW_TENANT_SELECTED, tenantId);
}

void TenantSelector::exit_selector() {
	emit_signal(EXIT_TENANT_SELECTOR);
}

void TenantSelector::_register_methods() {
	register_method("_init", &TenantSelector::_init);
	register_method("_ready", &TenantSelector::_ready);
	register_method("tenant_selected", &TenantSelector::tenant_selected);
	register_method("exit_selector", &TenantSelector::exit_selector);
	register_signal<TenantSelector>(NEW_TENANT_SELECTED, "isPressed", GODOT_VARIANT_TYPE_INT);
	register_signal<TenantSelector>(EXIT_TENANT_SELECTOR);
}
