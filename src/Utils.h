//
// Created by bogdan on 30/03/2021.
//

#ifndef MUNDANE_JAM_UTILS_H
#define MUNDANE_JAM_UTILS_H

#include "GameState.h"

namespace godot {
GameState *get_gameState(Node *node);
void remove_children(Node *node);
}; // namespace godot
#endif //MUNDANE_JAM_UTILS_H
