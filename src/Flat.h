//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include "ActionFireTenant.h"
#include "ActionMoveInTenant.h"
#include "ActionRepairFlat.h"
#include "GameState.h"
#include "FlatFrame.h"
#include "FlatsManager.h"
#include "Signals.h"
#include "TenantIdentityCard.h"
#include "Constants.h"

#include <ColorRect.hpp>
#include <Godot.hpp>
#include <Light2D.hpp>
#include <PackedScene.hpp>
#include <PopupDialog.hpp>
#include <RandomNumberGenerator.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Sprite.hpp>
#include <Texture.hpp>
#include <TextureButton.hpp>
#include <TextureRect.hpp>
#include <Viewport.hpp>
#include <algorithm>

namespace godot {
class Flat : public TextureButton {
	GODOT_CLASS(Flat, TextureButton);

	TenantIdentityCard::Tenant *tenant;
	RandomNumberGenerator *rng;
	TextureRect *flatMask;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();
	void sign_lease(TenantIdentityCard::Tenant *tenant);
	void update_charge();
	real_t break_legs_and_collect_money();
	void queue_move_in_tenant(const bool isPressed, const uint64_t tenantId);
	void queue_fire_tenant(const bool isPressed);
	void queue_repair_flat(const bool isPressed);
	// void reset_action_icon();
	void _add_action_icon_on_flat(Action *action);
	void _remove_action_icon_on_flat(ActionType actionType);
	void repair();
	void update_health();
	void update_tenant_presence();
	void fire_tenant();
	void fire_tenant_if_end_leasing();

	int64_t id;
	real_t rent;
	int64_t health;
	real_t charge;
};
} // namespace godot

#endif //MUNDANE_JAM_FLAT_H
