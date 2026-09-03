#include "Ball.h"

Ball::Ball(float mass2) : position(0,0), velocity(0,0), acceleration(0,0), force(0,0){
	mass = mass2;
}

void Ball::calculateAcceleration(Vector2 force2, float mass2){
	acceleration = force / mass;
}

void Ball::updateVelocity(Vector2 acceleration2, float dt){
	velocity = velocity + (acceleration2 * dt);
}

void Ball::updatePosition(Vector2 velocity2, float dt){
	position = position + (velocity2 * dt);
}

void Ball::applyForce(Vector2 force2, float dt){
	force = force2;
	calculateAcceleration(force, mass);
	updateVelocity(acceleration, dt);
	updatePosition(velocity, dt);
}

Vector2 Ball::getPosition() const {
	return position;
}

Vector2 Ball::getVelocity() const {
	return velocity;
}

float Ball::getMass() const {
	return mass;
}


