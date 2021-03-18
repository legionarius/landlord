//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_FLAT_H
#define MUNDANE_JAM_FLAT_H

#include "FlatFrame.h"
#include "Signals.h"
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <PopupDialog.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <TextureButton.hpp>
#include <Viewport.hpp>
#include "TenantIdentityCard.h"

namespace godot {
class Flat : public TextureButton {
	GODOT_CLASS(Flat, TextureButton);

	TenantIdentityCard::Tenant * tenant;
	int64_t end_lease; // cycle at which the

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();
	void sign_lease(TenantIdentityCard::Tenant * tenant);

	real_t id;
	real_t rent;
	real_t health;
};
} // namespace godot

#endif //MUNDANE_JAM_FLAT_H
