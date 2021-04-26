//
// Created by bogdan on 07/04/2021.
//

#ifndef MUNDANE_JAM_ACTIONMANAGER_H
#define MUNDANE_JAM_ACTIONMANAGER_H

#include <Godot.hpp>
#include <GridContainer.hpp>
#include <Label.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <TextureButton.hpp>
#include <Viewport.hpp>

#include "ActionItem.h"
#include "FlatsManager.h"
#include "Signals.h"
#include "Utils.h"

namespace godot {
class ActionManager : public GridContainer {
	GODOT_CLASS(ActionManager, Node);

public:
	void _on_action_added(int flatId, int actionTypeOrdinal);
	void _on_action_removed(int flatId, int actionTypeOrdinal);
	void _on_new_cycle();

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //MUNDANE_JAM_ACTIONMANAGER_H
