#ifndef DYNAMICOBJECTS_H
#define DYNAMICOBJECTS_H

#include "../../Vector2/Vector2.h"
#include "../PhysicsObject.h"

class DynamicObjects : public PhysicsObject {
	public:
		Vector2 velocity;
		Vector2 acceleration;
		Vector2 force;
		float mass;
		const float COR; // Coefficient of restitution
		const float COD; // Coefficient of drag
		DynamicObjects(float x, float y, float mass, float COR, float COD);
};

#endif
