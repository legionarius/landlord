//
// Created by acroquelois on 15/03/2021.
//

#include "TenantIdentityCard.h"

using namespace godot;

void TenantIdentityCard::_ready() {
	first_name_label = Object::cast_to<Label>(get_node("FirstName"));
	last_name_label = Object::cast_to<Label>(get_node("LastName"));
	age_label = Object::cast_to<Label>(get_node("Age"));
	confidence_label = Object::cast_to<Label>(get_node("Confidence"));
	cleanliness_label = Object::cast_to<Label>(get_node("Cleanliness"));
	leasing_duration_label = Object::cast_to<Label>(get_node("LeasingDuration"));
	description_label = Object::cast_to<RichTextLabel>(get_node("Description"));
	picture = Object::cast_to<TextureRect>(get_node("Picture"));
	update_display();
}

void TenantIdentityCard::set_tenant(TenantIdentityCard::Tenant *m_tenant) {
	tenant = m_tenant;
}

void TenantIdentityCard::update_display() {
	if (tenant != nullptr) {
		first_name_label->set_text(tenant->first_name);
		last_name_label->set_text(tenant->last_name);
		age_label->set_text(String::num_int64(tenant->age));
		confidence_label->set_text(String::num_int64(tenant->confidence));
		cleanliness_label->set_text(String::num_int64(tenant->cleanliness));
		description_label->set_text(tenant->description);
		std::stringstream leasing_duration_stream;
		leasing_duration_stream << tenant->leasing_duration << " month(s)";
		leasing_duration_label->set_text(leasing_duration_stream.str().c_str());

		Ref<Texture> picture_png = ResourceLoader::get_singleton()->load(tenant->picture_path);
		if (!picture_png.is_null()) {
			picture->set_texture(picture_png);
		}
	}
}

void TenantIdentityCard::_init() {
}

void TenantIdentityCard::_register_methods() {
	register_method("_init", &TenantIdentityCard::_init);
	register_method("_ready", &TenantIdentityCard::_ready);
}
