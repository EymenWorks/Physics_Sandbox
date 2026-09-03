#include "Class/Vector2/Vector2.h"
#include "Class/Ball/Ball.h"
#include <chrono>
#include <thread>
#include <iostream>

int main (){
	
	Ball ball(10);
	Vector2 gravity(0.0f, -9.8f);
	Vector2 gravityForce = gravity * ball.getMass();
	const std::chrono::milliseconds sleep_time = std::chrono::milliseconds(1000/30); // 30FPS
	for (int i = 0; i < 60; i++){
		auto start = std::chrono::steady_clock::now();
		std::this_thread::sleep_for(sleep_time);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsed = end - start;
		ball.applyForce(gravityForce, elapsed.count());
		if (i % 10 == 0 || i == 0){
			std::cout << "Dt: " << elapsed.count() << "\n";
			std::cout << "Velocity: (" << ball.getVelocity().getX() << ", " << ball.getVelocity().getY() << ")" << "\n";
			std::cout << "Position: (" << ball.getPosition().getX() << ", " << ball.getPosition().getY() << ")" << "\n";	
			std::cout << "\n\n";
		}
	}
	
	return 0;
}
