//
// Created by bogdan on 21/03/2021.
//

#ifndef MUNDANE_JAM_MONTHREPORT_H
#define MUNDANE_JAM_MONTHREPORT_H

#include <Godot.hpp>
#include <Control.hpp>
#include <RichTextLabel.hpp>
#include <Label.hpp>


namespace godot {
class MonthReport : public Control {
	GODOT_CLASS(MonthReport, Control);

	RichTextLabel * richTextLabel;

public:
	void _add_entry(String entry);
	void _flush();
	static void  _register_methods();
	void _init();
	void _ready();
};
}

#endif //MUNDANE_JAM_MONTHREPORT_H
