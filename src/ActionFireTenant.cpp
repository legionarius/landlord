//
// Created by acroquelois on 18/03/2021.
//

#include "ActionFireTenant.h"

void ActionFireTenant::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Fire tenant in flat : " + flat->get_name());
}