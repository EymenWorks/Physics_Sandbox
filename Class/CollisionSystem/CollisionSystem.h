#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../Vector2/Vector2.h"
#include "../Ball/Ball.h"

class Ball;

class CollisionSystem {
	public:
		void detectCollision(Ball& ball);
};

#endif
