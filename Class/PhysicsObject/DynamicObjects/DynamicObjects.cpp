#include "DynamicObjects.h"

DynamicObjects::DynamicObjects(float x, float y) : PhysicsObject(x,y), velocity(0,0), acceleration(0,0), force(0,0), COR(0.75f), COD(0.95f) {
	mass = 10;
}
