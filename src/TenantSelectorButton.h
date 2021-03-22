//
// Created by acroquelois on 22/03/2021.
//

#ifndef MUNDANE_JAM_TENANTSELECTORBUTTON_H
#define MUNDANE_JAM_TENANTSELECTORBUTTON_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include <TextureRect.hpp>

#include "TenantManager.h"
#include "TenantIdentityCard.h"
#include "Signals.h"

namespace godot {
class TenantSelectorButton: public TextureButton {
GODOT_CLASS(TenantSelectorButton, TextureButton);

	int64_t tenantId;
public:
	static void _register_methods();
	void _init();
	void _ready();
	void _on_pressed();

	void set_tenant_id(int64_t m_tenantId){tenantId = m_tenantId;}
};
}

#endif //MUNDANE_JAM_TENANTSELECTORBUTTON_H
