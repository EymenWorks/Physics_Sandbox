#include "CollisionSystem.h"

void CollisionSystem::detectCollision(Ball& ball){
	if (ball.getPosition().getY() <= 0 && ball.getVelocity().getY() < 0){
		ball.setPosition(0, -ball.getPosition().getY());
		Vector2 afterVelocity(0,0);
		float totalY = -ball.getCOR() * ball.getVelocity().getY();
		afterVelocity.setY(totalY);
		ball.setVelocity(afterVelocity);
	}
}
