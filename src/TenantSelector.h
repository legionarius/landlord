//
// Created by acroquelois on 22/03/2021.
//

#ifndef MUNDANE_JAM_TENANTSELECTOR_H
#define MUNDANE_JAM_TENANTSELECTOR_H

#include <Godot.hpp>
#include <HBoxContainer.hpp>
#include <RandomNumberGenerator.hpp>
#include <TextureButton.hpp>
#include <TextureRect.hpp>

#include "Signals.h"
#include "TenantIdentityCard.h"
#include "TenantManager.h"
#include "TenantSelectorButton.h"

namespace godot {
class TenantSelector : public TextureRect {
	GODOT_CLASS(TenantSelector, TextureRect);

	size_t maxItems;
	RandomNumberGenerator *rng;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void tenant_selected(int64_t tenantId);
	void exit_selector();
};
} // namespace godot

#endif //MUNDANE_JAM_TENANTSELECTOR_H
