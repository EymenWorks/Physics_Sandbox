#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../Vector2/Vector2.h"
#include "../PhysicsObject/DynamicObjects/Ball/Ball.h"
#include "../PhysicsObject/StaticObjects/Ground/Ground.h"

class Ball;

class CollisionSystem {
	public:
		void detectCollision(Ball& ball, Ground& ground);
};

#endif
