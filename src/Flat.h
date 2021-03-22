//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include "ActionFireTenant.h"
#include "ActionMoveInTenant.h"
#include "ActionRepairFlat.h"
#include "Constants.h"
#include "FlatFrame.h"
#include "FlatIndicators.h"
#include "FlatsManager.h"
#include "Signals.h"

#include "TenantIdentityCard.h"
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
	int64_t end_lease; // cycle at which the
	RandomNumberGenerator *rng;
	FlatIndicators *flatIndicators;
	Light2D *lightBulbTenant;
	Sprite *lightBulb;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();
	void sign_lease(TenantIdentityCard::Tenant *tenant);
	void update_charge();
	real_t break_legs_and_collect_money();
	void queue_move_in_tenant(const bool isPressed);
	void queue_fire_tenant(const bool isPressed);
	void queue_repair_flat(const bool isPressed);
	void reset_action_icon();
	void _add_action_icon_on_flat(Action *action);
	void _remove_action_icon_on_flat(ActionType actionType);
	void repair();
	void update_health();
	void show_indicators();
	void update_tenant_presence();

	int64_t id;
	real_t rent;
	int64_t health;
	real_t charge;
};
} // namespace godot

#endif //MUNDANE_JAM_FLAT_H
