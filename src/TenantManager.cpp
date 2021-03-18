//
// Created by acroquelois on 15/03/2021.
//

#include "TenantManager.h"

using namespace godot;

TenantManager::~TenantManager() {
	for(TenantIdentityCard::Tenant* tenant:tenant_array){
		delete tenant;
	}
	tenant_array.clear();
}

TenantIdentityCard::Tenant * TenantManager::get_tenant(int n) {
	return tenant_array[n];
}

void TenantManager::load_inputs() {
	Ref<File> file = File::_new();
	Error json_file = file->open("datasource/tenants.json", File::ModeFlags::READ);
	if (json_file == Error::ERR_FILE_CANT_OPEN) {
		Godot::print("Can't open file !");
	} else if (json_file == Error::ERR_FILE_CANT_READ) {
		Godot::print("Can't read file !");
	} else if (json_file == Error::ERR_FILE_NOT_FOUND) {
		Godot::print("File not found !");
	}
	Array json_results =
			JSON::get_singleton()->parse(file->get_as_text())->get_result();
	for (int i = 0; i < json_results.size(); i++) {
		Dictionary input = json_results[i];
		TenantIdentityCard::Tenant *tenant = new TenantIdentityCard::Tenant;
		tenant->first_name = input["firstname"];
		tenant->last_name = input["lastname"];
		tenant->age = input["age"];
		tenant->description = input["description"];
		tenant->picture_path = input["picture_path"];
		tenant->confidence = input["confidence"];
		tenant->cleanliness = input["cleanliness"];
		tenant_array.push_back(tenant);
	}

}

void TenantManager::_init() {
	Godot::print("Initialize tenants");
	load_inputs();
	Godot::print("All tenants loaded");
}

void TenantManager::_ready(){}

void TenantManager::_register_methods() {
	register_method("_init", &TenantManager::_init);
	register_method("_ready", &TenantManager::_ready);
}
