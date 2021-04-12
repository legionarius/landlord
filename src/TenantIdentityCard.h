//
// Created by acroquelois on 15/03/2021.
//

#ifndef MUNDANE_JAM_TENANTIDENTITYCARD_H
#define MUNDANE_JAM_TENANTIDENTITYCARD_H

#include <Godot.hpp>
#include <Label.hpp>
#include <ResourceLoader.hpp>
#include <RichTextLabel.hpp>
#include <Texture.hpp>
#include <TextureRect.hpp>
#include <sstream>

namespace godot {
class TenantIdentityCard : public TextureRect {
	GODOT_CLASS(TenantIdentityCard, TextureRect);

public:
	struct Tenant {
		int64_t id;
		String first_name;
		String last_name;
		String description;
		String picture_path;
		uint16_t age;
		uint16_t confidence;
		uint16_t cleanliness;
		real_t leasing_duration;
		real_t leasing_end_cycle;
	};

	Tenant *tenant;

	static void _register_methods();
	void _init();
	void _ready();

	// Setter
	void set_tenant(TenantIdentityCard::Tenant *m_tenant);
	void update_display();

private:
	Label *first_name_label;
	Label *last_name_label;
	Label *age_label;
	Label *confidence_label;
	Label *cleanliness_label;
	Label *leasing_duration_label;
	RichTextLabel *description_label;
	TextureRect *picture;
};
} // namespace godot

#endif //MUNDANE_JAM_TENANTIDENTITYCARD_H
