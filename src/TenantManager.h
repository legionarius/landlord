//
// Created by acroquelois on 15/03/2021.
//

#ifndef MUNDANE_JAM_TENANTMANAGER_H
#define MUNDANE_JAM_TENANTMANAGER_H

#include <File.hpp>
#include <InputMap.hpp>
#include <JSON.hpp>
#include <JSONParseResult.hpp>
#include <Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <map>
#include <vector>

#include "TenantIdentityCard.h"

namespace godot {
class TenantManager: public Node {
	GODOT_CLASS(TenantManager, Node);

private:
	std::vector<TenantIdentityCard::Tenant*> tenant_array;
	void load_inputs();

public:
	static void _register_methods();
	void _init();
	void _ready();
	~TenantManager();
};
}

#endif //MUNDANE_JAM_TENANTMANAGER_H
