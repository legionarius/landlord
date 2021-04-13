//
// Created by bogdan on 14/03/2021.
//

#include "Flat.h"

using namespace godot;

void Flat::_register_methods() {
	register_method("_init", &Flat::_init);
	register_method("_ready", &Flat::_ready);
	register_method("_exit_tree", &Flat::_exit_tree);
	register_method("_on_pressed", &Flat::_on_pressed);
}

void Flat::_init() {
	rng = RandomNumberGenerator()._new();
	rng->randomize();
	health = rng->randi_range(20, 100);
	rent = rng->randf_range(100, 500);
	update_charge();
}

void Flat::_ready() {
	connect("pressed", this, "_on_pressed");
	id = get_name().right(4).to_int();
	flatMask = cast_to<TextureRect>(get_node("FlatMask"));
	set_tooltip("Click to open flat details");
	Ref<PackedScene> characterScene = ResourceLoader::get_singleton()->load("entity/Tenant/Character.tscn");
	tenantSpawnPosition = cast_to<Position2D>(get_node("TenantSpawn"));
	if (tenantSpawnPosition != nullptr) {
		tenantCharacter = cast_to<TenantCharacter>(characterScene->instance());
	}
}

void Flat::_exit_tree() {
	// In case of tenant character isn't in scene tree
	tenantCharacter->free();
}

// Should be run after each cycle when
// the flat health changes.
void Flat::update_charge() {
	// Charge
	// - 50% of the rent
	// - Bonus of 25% of the health (remove the bonus from the charge)
	charge = (rent * 25.f) / 100.f - (health * 0.25);
}

void Flat::sign_lease(TenantIdentityCard::Tenant *tenant) {
	GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	if (gameState->get_cycle_number() == 0) {
		tenant->leasing_end_cycle = gameState->get_cycle_number() + tenant->leasing_duration - 1;
	} else {
		tenant->leasing_end_cycle = gameState->get_cycle_number() + tenant->leasing_duration;
	}
	this->tenant = tenant;
	spawn_tenant();
}

void Flat::spawn_tenant() {
	tenantCharacter->set_position(tenantSpawnPosition->get_position());
	add_child(tenantCharacter);
}

void Flat::_on_pressed() {
	FlatFrame *flatFrame = cast_to<FlatFrame>(get_tree()->get_root()->get_node("MainScene/FlatFrame"));
	flatFrame->_set_flat(this);
	flatFrame->_set_flat_label(id);
	flatFrame->_set_health(health);
	flatFrame->_set_rent(rent);
	flatFrame->_set_tenant(tenant);
	// TODO: Voir pour faire une methode queue action en passant un param dans la méthode connect
	flatFrame->popup();
}

real_t Flat::break_legs_and_collect_money() {
	if (tenant != nullptr) {
		rng->randomize();
		real_t n = rng->randf_range(0, 1);
		if (n < (tenant->confidence / 100.f)) {
			return rent - charge;
		} else {
			return -charge;
		}
	} else {
		return -charge;
	}
}

void Flat::repair() {
	health = 100;
}

void Flat::fire_tenant() {
	tenant = nullptr;
	remove_child(tenantCharacter);
}

void Flat::fire_tenant_if_end_leasing() {
	if (tenant != nullptr) {
		GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
		if (tenant->leasing_end_cycle <= gameState->get_cycle_number()) {
			fire_tenant();
		}
	}
}

void Flat::update_health() {
	int64_t decay = 0;
	int64_t min_health = 0;
	if (tenant != nullptr) {
		decay = static_cast<int64_t>(FLAT_DECAY_RATE - (tenant->cleanliness * FLAT_DECAY_RATE_NO_TENANT) / 100);
	} else {
		decay = FLAT_DECAY_RATE_NO_TENANT;
	}
	health -= std::max(min_health, decay);
}

void Flat::update_tenant_presence() {
	if (tenant != nullptr) {
		flatMask->set_visible(false);
	} else {
		flatMask->set_visible(true);
	}
}

Flat::~Flat() {
	rng->free();
}
