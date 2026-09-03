#ifndef BALL_H
#define BALL_H

#include "../Vector2/Vector2.h"

class Ball {
	Vector2 position;
	Vector2 velocity;
	Vector2 force;
	Vector2 acceleration;
	float mass;
	public:
		Ball(float mass2);
		void calculateAcceleration(Vector2 force2, float mass2);
		void updateVelocity(Vector2 acceleration2, float dt);
		void updatePosition(Vector2 velocity2, float dt);
		void applyForce(Vector2 force2, float dt);
		Vector2 getPosition() const;
		Vector2 getVelocity() const;
		float getMass() const;
};

#endif
