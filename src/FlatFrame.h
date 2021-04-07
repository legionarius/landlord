//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include "ActionFireTenant.h"
#include "ActionRepairFlat.h"
#include "Signals.h"
#include "TenantIdentityCard.h"
#include "TenantSelector.h"

#include <AnimationPlayer.hpp>
#include <AudioStreamPlayer.hpp>
#include <Godot.hpp>
#include <GridContainer.hpp>
#include <Label.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <PopupDialog.hpp>
#include <ProgressBar.hpp>
#include <ResourceLoader.hpp>
#include <Sprite.hpp>
#include <TextureButton.hpp>
#include <iomanip>

namespace godot {
class FlatsManager;

class FlatFrame : public PopupDialog {
	GODOT_CLASS(FlatFrame, PopupDialog);

	Sprite *mainContainer;
	Label *flatName;
	ProgressBar *healthGauge;
	Label *rent;
	AnimationPlayer *animation;
	AudioStreamPlayer *audio;
	TextureButton *exitButton;
	TenantIdentityCard *tenantIdentityCard;
	FlatsManager *flatsManager;
	GridContainer *actionContainer;

	Node *flat;
	real_t flatId;
	String flatNameLabel;
	real_t healthLabel;
	String rentLabel;
	TenantIdentityCard::Tenant *tenant;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_exitButton_pressed();
	void _on_move_in_pressed();
	void _on_repair_pressed();
	void _on_fire_pressed();
	void _on_tenant_selected(uint64_t tenantId);
	void _exit_tenant_selector();
	void _on_pre_show();

	void _set_flat(Node *item);
	void _set_flat_label(real_t id);
	void _set_health(real_t health);
	void _set_rent(real_t rent);
	void _set_tenant(TenantIdentityCard::Tenant *tenant);
	void _toggle_fire_tenant_button(bool enabled) const;
	void _toggle_move_in_tenant_button(bool enabled) const;
	void _toggle_repair_flat_button(bool enabled) const;
};
} // namespace godot

#endif //MUNDANE_JAM_FLATFRAME_H
