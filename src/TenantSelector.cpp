//
// Created by acroquelois on 22/03/2021.
//

#include "TenantSelector.h"

using namespace godot;

void TenantSelector::_init() {
	maxItems = 3;
	rng = RandomNumberGenerator()._new();
}

void TenantSelector::_ready() {
	TenantManager *tenantManager = cast_to<TenantManager>(get_tree()->get_root()->get_node("TenantManager"));
	Node *selectorBackground = get_node("TenantSelectorBackground");
	TextureButton *exitSelector = cast_to<TextureButton>(get_node("ExitSelector"));
	exitSelector->connect("pressed", this, "exit_selector");
	Ref<Texture> hover_texture = ResourceLoader::get_singleton()->load("asset/Flat/hover_texture.png");
	rng->randomize();
	Ref<PackedScene> tenantIdentityCardScene = ResourceLoader::get_singleton()->load("entity/Tenant/TenantIdentityCard.tscn");
	std::vector<size_t> selected;
	for (size_t i = 0; i < maxItems; i++) {
		size_t tenantIndex = rng->randi_range(0, 49);
		while (selected.end() != std::find(selected.begin(), selected.end(), tenantIndex)) {
			tenantIndex = rng->randi_range(0, 49);
		}
		TenantIdentityCard::Tenant *tenant = tenantManager->get_tenant(tenantIndex);
		TenantIdentityCard *tenantIdentityCard = cast_to<TenantIdentityCard>(tenantIdentityCardScene->instance());
		TenantSelectorButton *tenantButtonSelector = TenantSelectorButton::_new();
		tenantButtonSelector->set_size(Vector2(190, 200));
		tenantButtonSelector->set_hover_texture(hover_texture);
		tenantButtonSelector->connect(TENANT_SELECTOR_PRESSED, this, "tenant_selected");
		tenantButtonSelector->set_tenant_id(tenant->id);
		tenantIdentityCard->set_tenant(tenant);
		tenantButtonSelector->set_position(Vector2(0, 30));
		tenantButtonSelector->set_margin(0, 200 * (i + 1));
		tenantButtonSelector->add_child(tenantIdentityCard);
		selectorBackground->add_child(tenantButtonSelector);
	}
}

void TenantSelector::tenant_selected(int64_t tenantId) {
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
