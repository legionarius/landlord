//
// Created by acroquelois on 15/03/2021.
//

#include "TenantIdentityCard.h"

using namespace godot;

void TenantIdentityCard::_ready() {
	Label *first_name_label = Object::cast_to<Label>(get_node("FirstName"));
	Label *last_name_label = Object::cast_to<Label>(get_node("LastName"));
	Label *age_label = Object::cast_to<Label>(get_node("Age"));
	Label *confidence_label = Object::cast_to<Label>(get_node("Confidence"));
	Label *cleanliness_label = Object::cast_to<Label>(get_node("Cleanliness"));
	RichTextLabel *description_label = Object::cast_to<RichTextLabel>(get_node("Description"));
	TextureRect *picture = Object::cast_to<TextureRect>(get_node("Picture"));

	if (first_name_label != nullptr && last_name_label != nullptr && age_label != nullptr && confidence_label != nullptr && cleanliness_label != nullptr && description_label != nullptr && picture != nullptr){
		first_name_label->set_text(get_first_name());
		last_name_label->set_text(get_last_name());
		age_label->set_text(String::num_int64(get_age()));
		confidence_label->set_text(String::num_int64(get_confidence()));
		cleanliness_label->set_text(String::num_int64(get_cleanliness()));
		description_label->set_text(get_description());

		Ref<Texture> picture_png = ResourceLoader::get_singleton()->load(get_picture_path());
		if(!picture_png.is_null()){
			picture->set_texture(picture_png);
		}
		else{
			Godot::print("Path doesn't exist");
		}
	} 
	else{
		Godot::print("Can't get all node of scene");
	}
}

void TenantIdentityCard::_init() {
}

void TenantIdentityCard::_register_methods() {
	register_method("_init", &TenantIdentityCard::_init);
	register_method("_ready", &TenantIdentityCard::_ready);
}
