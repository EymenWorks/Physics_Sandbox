#include "DragSystem.h"

Vector2 DragSystem::calculateDragForce(Ball& ball){
	Vector2 dragForce = ball.getVelocity() * -ball.getCOD();
	return dragForce;
}
