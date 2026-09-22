#include "../Vector2/Vector2.h"
#include "../PhysicsObject/DynamicObjects/Ball/Ball.h"
#include "../CollisionSystem/CollisionSystem.h"
#include "../DragSystem/DragSystem.h"
#include "../PhysicsObject/StaticObjects/Ground/Ground.h"


class PhysicsWorld {
	Ball& ball;
	Ground& ground;
	Vector2 gravity;
	Vector2 windForce;
	Vector2 calculateGravityForce(Vector2 gravity, Ball& ball);
	Vector2 gravityForce = calculateGravityForce(gravity, ball);
	DragSystem ds;
	CollisionSystem cs;
	Vector2 dragForce;
	Vector2 netForce;
	public:
		PhysicsWorld(Ball& ball, Ground& ground, float x, float y, float gravityY);
		void update(float dt);
		Vector2 getDragForce() const;
		Vector2 getNetForce() const;
		Vector2 getWindForce() const;
		Vector2 getGravityForce() const;
};
