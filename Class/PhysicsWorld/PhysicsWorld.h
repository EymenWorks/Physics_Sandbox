#include "../Vector2/Vector2.h"
#include "../Ball/Ball.h"
#include "../CollisionSystem/CollisionSystem.h"
#include "../DragSystem/DragSystem.h"

class PhysicsWorld {
	Ball& ball;
	Vector2 gravity;
	Vector2 calculateGravityForce(Vector2 gravity, Ball& ball);
	Vector2 gravityForce = calculateGravityForce(gravity, ball);
	DragSystem ds;
	CollisionSystem cs;
	Vector2 dragForce;
	Vector2 netForce;
	public:
		PhysicsWorld(Ball& ball);
		void update(float dt);
		Vector2 getDragForce() const;
		Vector2 getNetForce() const;
};
