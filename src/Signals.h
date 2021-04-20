//
// Created by bogdan on 14/03/2021.
//

#ifndef MUNDANE_JAM_SIGNALS_H
#define MUNDANE_JAM_SIGNALS_H

// Application Signals
#define FLAT_SELECTED "flat_selected"
#define NEW_CYCLE "new_cycle"
#define ACTIONS_COST "actions_cost"
#define SIGNAL_MOVE_IN_TENANT "move_in_tenant"
#define SIGNAL_FIRE_TENANT "fire_tenant"
#define SIGNAL_REPAIR_FLAT "repair_flat"
#define NEW_TENANT_SELECTED "new_tenant_selected"
#define TENANT_SELECTOR_PRESSED "tenant_selector_pressed"
#define EXIT_TENANT_SELECTOR "exit_tenant_selector"
#define START_OPEN_FLAT_DETAIL "start_open_flat_detail"
#define END_OPEN_FLAT_DETAIL "end_open_flat_detail"
// Sent when an action is effectively added to the action stack
#define ADD_ACTION "add_action"
// Sent when an action is effectively removed to the action stack
#define REMOVE_ACTION "remove_action"
// Sent each time the action count effectively changes
#define ACTION_COUNT "action_count"

// Godot Signals

#define BTN_PRESSED "pressed"
#define POPUP_ABOUT_TO_SHOW "about_to_show"

#endif //MUNDANE_JAM_SIGNALS_H
