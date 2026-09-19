#include "CollisionSystem.h"

void CollisionSystem::detectCollision(Ball& ball, Ground& ground){
	if (ball.getPosition().getY() <= ground.position.getY() && ball.getVelocity().getY() < 0){
		float newPosition = ground.position.getY() - ball.getPosition().getY();
		newPosition += ground.position.getY();
		ball.setPosition(0, newPosition);
		Vector2 afterVelocity(0,0);
		float totalY = -ball.getCOR() * ball.getVelocity().getY();
		afterVelocity.setY(totalY);
		ball.setVelocity(afterVelocity);
	}
}
