//
// Created by bogdan on 16/03/2021.
//

#include "ActionRepairFlat.h"

void ActionRepairFlat::apply(godot::Node *item) {
	godot::Flat *flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("[ACTION]: Repairing flat : " + flat->get_name());
}