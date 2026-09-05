#ifndef BALL_H
#define BALL_H

#include "../Vector2/Vector2.h"
#include "../CollisionSystem/CollisionSystem.h"

class Ball {
	Vector2 position;
	Vector2 velocity;
	Vector2 force;
	Vector2 acceleration;
	float mass = 0;
	const float COR = 0.75; // Coefficient of restitution
	public:
		Ball(float x, float y);
		void calculateAcceleration(Vector2 force2, float mass2);
		void updateVelocity(Vector2 acceleration2, float dt);
		void updatePosition(Vector2 velocity2, float dt);
		void applyForce(Vector2 force2, float dt);
		Vector2 getPosition() const;
		Vector2 getVelocity() const;
		void setMass(float mass);
		float getMass() const;
		float getCOR() const;
		void setVelocity(Vector2 velocity2);
		void setPosition(float x, float y);
		
};

#endif
