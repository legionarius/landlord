//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include "ActionFireTenant.h"
#include "ActionRepairFlat.h"
#include "FlatsManager.h"
#include "Signals.h"
#include "TenantIdentityCard.h"

#include <AnimationPlayer.hpp>
#include <AudioStreamPlayer.hpp>
#include <Godot.hpp>
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
class FlatFrame : public PopupDialog {
	GODOT_CLASS(FlatFrame, PopupDialog);

	real_t apartmentId;
	String apartmentNameLabel;
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

	void _set_apartment_label(real_t id);
	void _set_health(real_t health);
	void _set_rent(real_t rent);
	void _set_tenant(TenantIdentityCard::Tenant* tenant);
	TextureButton _get_fire_tenant_button() const;
};
} // namespace godot

#endif //MUNDANE_JAM_FLATFRAME_H
