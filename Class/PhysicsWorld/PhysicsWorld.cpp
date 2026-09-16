#include "PhysicsWorld.h"

Vector2 PhysicsWorld::calculateGravityForce(Vector2 gravity, Ball& ball){
	return gravity * ball.getMass();
}

PhysicsWorld::PhysicsWorld(Ball& ball) : ball(ball), gravity(0.0f, -9.8f), dragForce(0,0), netForce(0,0){}

void PhysicsWorld::update(float dt){
	ball.addForce(gravityForce);
	dragForce = ds.calculateDragForce(ball);
	ball.addForce(dragForce);
	netForce = ball.getForce();
	ball.applyForce(dt);
	cs.detectCollision(ball);
	ball.setForce(0,0);
}

Vector2 PhysicsWorld::getDragForce() const {
	return dragForce;
}

Vector2 PhysicsWorld::getNetForce() const {
	return netForce;
}
