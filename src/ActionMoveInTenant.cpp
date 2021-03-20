//
// Created by acroquelois on 20/03/2021.
//

#include "ActionMoveInTenant.h"

void ActionMoveInTenant::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Move in tenant in flat : " + flat->get_name());
}