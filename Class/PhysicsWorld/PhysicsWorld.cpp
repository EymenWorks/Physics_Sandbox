#include "PhysicsWorld.h"

Vector2 PhysicsWorld::calculateGravityForce(Vector2 gravity, Ball& ball){
	return gravity * ball.getMass();
}

PhysicsWorld::PhysicsWorld(Ball& ball, Ground& ground, float x, float y, float gravityY) : ball(ball), ground(ground), gravity(0,gravityY), dragForce(0,0), netForce(0,0), windForce(x,y) {}

void PhysicsWorld::update(float dt){
	ball.addForce(gravityForce);
	dragForce = ds.calculateDragForce(ball);
	ball.addForce(dragForce);
	ball.addForce(windForce);
	netForce = ball.getForce();
	ball.applyForce(dt);
	cs.detectCollision(ball, ground);
	ball.setForce(0,0);
}

Vector2 PhysicsWorld::getDragForce() const {
	return dragForce;
}

Vector2 PhysicsWorld::getNetForce() const {
	return netForce;
}

Vector2 PhysicsWorld::getWindForce() const {
	return windForce;
}

Vector2 PhysicsWorld::getGravityForce() const {
	return gravityForce;
}
