#ifndef DRAGSYSTEM_H
#define DRAGSYSTEM_H

#include "../Ball/Ball.h"
#include "../Vector2/Vector2.h"

class DragSystem{
	public:
		Vector2 calculateDragForce(Ball& ball);
};

#endif
