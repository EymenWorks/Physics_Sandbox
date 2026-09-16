#include "Class/Ball/Ball.h"
#include "Class/PhysicsWorld/PhysicsWorld.h"

#include <chrono>
#include <thread>
#include <iostream>

int main (){
	
	Ball ball(0, 200);
	ball.setMass(10.0f);
	PhysicsWorld pw(ball);
	const std::chrono::milliseconds sleep_time = std::chrono::milliseconds(1000/30); // 30FPS
	for (int i = 0; i < 6000; i++){
		auto start = std::chrono::steady_clock::now();
		std::this_thread::sleep_for(sleep_time);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsed = end - start;
		pw.update(elapsed.count());
		if (i % 10 == 0 || i == 0){
			std::cout << "Attempt: " << i << "\n";
			std::cout << "Dt: " << elapsed.count() << "\n";
			std::cout << "COD: " << ball.getCOD() << "\n";
			std::cout << "Velocity: (" << ball.getVelocity().getX() << ", " << ball.getVelocity().getY() << ")" << "\n";
			std::cout << "Position: (" << ball.getPosition().getX() << ", " << ball.getPosition().getY() << ")" << "\n";
			std::cout << "Net Force: (" << pw.getNetForce().getX() << ", " << pw.getNetForce().getY() << ")" << "\n";	
			std::cout << "Drag Force: (" << pw.getDragForce().getX() << ", " << pw.getDragForce().getY() << ")" << "\n";
			std::cout << "\n\n";
		}
	}
	
	return 0;
}
