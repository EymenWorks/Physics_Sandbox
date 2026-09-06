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
	const float COD = 0.95; // Coefficient of drag
	public:
		Ball(float x, float y);
		void calculateAcceleration(Vector2 force2, float mass2);
		void updateVelocity(Vector2 acceleration2, float dt);
		void updatePosition(Vector2 velocity2, float dt);
		void addForce(Vector2 force_type);
		void applyForce(float dt);
		Vector2 getPosition() const;
		Vector2 getVelocity() const;
		Vector2 getForce() const;
		float getMass() const;
		float getCOR() const;
		float getCOD() const;
		void setMass(float mass);
		void setVelocity(Vector2 velocity2);
		void setPosition(float x, float y);
		void setForce(float x, float y);
		
};

#endif
