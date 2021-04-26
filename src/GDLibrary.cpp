//
// Created by bogdan on 11/02/2021.
//

#include "ActionItem.h"
#include "ActionManager.h"
#include "CycleInfo.h"
#include "EndScreen.h"
#include "Flat.h"
#include "FlatFrame.h"
#include "FlatsManager.h"
#include "GameState.h"
#include "MainScene.h"
#include "OnBoarding.h"
#include "ReportFrame.h"
#include "SignalButton.h"
#include "TenantCharacter.h"
#include "TenantIdentityCard.h"
#include "TenantManager.h"
#include "TenantSelector.h"
#include "TenantSelectorButton.h"
#include "TitleScreen.h"
#include "Weather.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT
godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);
	godot::register_class<godot::EndScreen>();
	godot::register_class<godot::Flat>();
	godot::register_class<godot::GameState>();
	godot::register_class<godot::TenantCharacter>();
	godot::register_class<godot::TenantIdentityCard>();
	godot::register_class<godot::TenantManager>();
	godot::register_class<godot::TenantSelector>();
	godot::register_class<godot::TenantSelectorButton>();
	godot::register_class<godot::TitleScreen>();
	godot::register_class<godot::SignalButton>();
	godot::register_class<godot::CycleInfo>();
	godot::register_class<godot::FlatFrame>();
	godot::register_class<godot::FlatsManager>();
	godot::register_class<godot::Weather>();
	godot::register_class<godot::ActionManager>();
	godot::register_class<godot::ActionItem>();
	godot::register_class<godot::ReportFrame>();
	godot::register_class<godot::OnBoarding>();
	godot::register_class<godot::MainScene>();
}