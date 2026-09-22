#include "DynamicObjects.h"

DynamicObjects::DynamicObjects(float x, float y, float mass, float COR, float COD) : PhysicsObject(x,y), mass(mass), velocity(0,0), acceleration(0,0), force(0,0), COR(COR), COD(COD) {
	
}
