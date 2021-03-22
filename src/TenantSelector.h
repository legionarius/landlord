//
// Created by acroquelois on 22/03/2021.
//

#ifndef MUNDANE_JAM_TENANTSELECTOR_H
#define MUNDANE_JAM_TENANTSELECTOR_H

#include <Godot.hpp>
#include <TextureRect.hpp>

namespace godot {
class TenantSelector: public TextureRect {
	GODOT_CLASS(TenantSelector, TextureRect);

public:
	static void _register_methods();
	void _init();
	void _ready();
};
}

#endif //MUNDANE_JAM_TENANTSELECTOR_H
