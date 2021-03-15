//
// Created by nahalu on 15/03/2021.
//

#ifndef MUNDANE_JAM_FLATFRAME_H
#define MUNDANE_JAM_FLATFRAME_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class FlatFrame: public Node2D {
	GODOT_CLASS(FlatFrame, Node2D);

	int rent;
	int health;
	bool visible;

public:
	static void _register_methods();
	void _init();
	void _ready();

	FlatFrame();
	~FlatFrame()
};
}


#endif //MUNDANE_JAM_FLATFRAME_H
