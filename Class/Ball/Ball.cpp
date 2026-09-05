#include "Ball.h"

Ball::Ball(float x, float y) : position(0,0), velocity(0,0), acceleration(0,0), force(0,0){
	position.setX(x);
	position.setY(y);
}

void Ball::calculateAcceleration(Vector2 force2, float mass2){
	acceleration = force2 / mass2;
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

void Ball::setMass(float mass){
	this->mass = mass;
}

float Ball::getMass() const {
	return mass;
}

float Ball::getCOR() const {
	return COR;
}

void Ball::setVelocity(Vector2 velocity2){
	velocity = velocity2;
}

void Ball::setPosition(float x, float y){
	position.setX(x);
	position.setY(y);
}

