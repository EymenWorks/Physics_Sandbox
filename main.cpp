#include "Class/Vector2/Vector2.h"
#include "Class/Ball/Ball.h"
#include "Class/CollisionSystem/CollisionSystem.h"
#include "Class/DragSystem/DragSystem.h"

#include <chrono>
#include <thread>
#include <iostream>

int main (){
	
	DragSystem ds;
	CollisionSystem cs;
	Ball ball(0, 100000);
	ball.setMass(10.0f);
	Vector2 gravity(0.0f, -9.8f);
	Vector2 gravityForce = gravity * ball.getMass();
	int count = 0;
	const std::chrono::milliseconds sleep_time = std::chrono::milliseconds(1000/30); // 30FPS
	for (int i = 0; i < 6000; i++){
		auto start = std::chrono::steady_clock::now();
		std::this_thread::sleep_for(sleep_time);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsed = end - start;
		Vector2 dragForce = ds.calculateDragForce(ball);
		ball.addForce(gravityForce);
		ball.addForce(dragForce);
		ball.applyForce(elapsed.count());
		cs.detectCollision(ball);
		if (i % 10 == 0 || i == 0){
			std::cout << "Attempt: " << count << "\n";
			std::cout << "Dt: " << elapsed.count() << "\n";
			std::cout << "COD: " << ball.getCOD() << "\n";
			std::cout << "Velocity: (" << ball.getVelocity().getX() << ", " << ball.getVelocity().getY() << ")" << "\n";
			std::cout << "Position: (" << ball.getPosition().getX() << ", " << ball.getPosition().getY() << ")" << "\n";
			std::cout << "Net Force: (" << ball.getForce().getX() << ", " << ball.getForce().getY() << ")" << "\n";	
			std::cout << "Drag Force: (" << dragForce.getX() << ", " << dragForce.getY() << ")" << "\n";
			std::cout << "\n\n";
		}
		count++;
		ball.setForce(0,0);
	}
	
	return 0;
}
