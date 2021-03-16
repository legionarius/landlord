//
// Created by acroquelois on 15/03/2021.
//

#ifndef MUNDANE_JAM_TENANTIDENTITYCARD_H
#define MUNDANE_JAM_TENANTIDENTITYCARD_H

#include <Label.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <RichTextLabel.hpp>
#include <Texture.hpp>
#include <TextureRect.hpp>

namespace godot {
class TenantIdentityCard : public TextureRect{
	GODOT_CLASS(TenantIdentityCard, TextureRect);

public:
	struct Tenant {
		uint64_t id;
		String first_name;
		String last_name;
		String description;
		String picture_path;
		uint16_t age;
		uint16_t confidence;
		uint16_t cleanliness;
	};

	Tenant *tenant;

	static void _register_methods();
	void _init();
	void _ready();

	// Getter
	uint64_t get_id(){return tenant->id;}
	String get_first_name(){return tenant->first_name;}
	String get_last_name(){return tenant->last_name;}
	uint16_t get_age(){return tenant->age;}
	String get_description(){return tenant->description;}
	String get_picture_path(){return tenant->picture_path;}
	uint16_t get_confidence(){return tenant->confidence;}
	uint16_t get_cleanliness(){return tenant->cleanliness;}

	// Setter
	void set_tenant(TenantIdentityCard::Tenant *m_tenant){ tenant = m_tenant;};
};
}

#endif //MUNDANE_JAM_TENANTIDENTITYCARD_H
