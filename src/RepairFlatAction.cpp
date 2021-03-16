//
// Created by bogdan on 16/03/2021.
//

#include "RepairFlatAction.h"

void RepairFlatAction::apply(godot::Node *item) {
	godot::Flat * flat = godot::Object::cast_to<godot::Flat>(item);
	godot::Godot::print("Repairing flat : " + flat->get_name());
}