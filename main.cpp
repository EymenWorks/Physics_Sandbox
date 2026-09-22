#include "Class/PhysicsObject/DynamicObjects/Ball/Ball.h"
#include "Class/PhysicsWorld/PhysicsWorld.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <string>

int main (){
	
	float fVariable;
	float ballPosition;
	float ballMass;
	float cor;
	float cod;
	float groundPosition;
	float windForceX;
	float windForceY;
	float gravityY;
	bool doesDragExist;
	bool doesWindExist;
	bool doesGravityExist;
	const std::chrono::milliseconds sleep_time = std::chrono::milliseconds(1000/30); // 30FPS
	
	std::cout << "Enter the position y for ball:";
	std::cin >> ballPosition;
	
	std::cout << "Enter the position y for ground:";
	std::cin >> groundPosition;
	Ground ground(0, groundPosition);
	
	std::cout << "Enter the mass value of ball:";
	std::cin >> ballMass;
	
	std::cout << "Enter the value of coefficient of restitution:";
	std::cin >> cor;
	
	do {
		std::string decision;
		std::cout << "Gravity ON/OFF (1:ON, 2:OFF):";
		std::cin >> decision;
		if (decision == "1" || decision == "2"){
			if (decision == "1"){
				doesGravityExist = true;
				break;
			} else {
				doesGravityExist = false;
				break;
			}
		} else {
			std::cout << "Enter only 1 or 2 please!" << "\n";
			continue;
		}
	} while(true);
	
	if (doesGravityExist){
		gravityY = -9.8f;
	} else {
		gravityY = 0;
	}
	
	do {
		std::string decision;
		std::cout << "Drag ON/OFF (1:ON, 2:OFF):";
		std::cin >> decision;
		if (decision == "1" || decision == "2"){
			if (decision == "1"){
				doesDragExist = true;
				break;
			} else {
				doesDragExist = false;
				break;
			}
		} else {
			std::cout << "Enter only 1 or 2 please!" << "\n";
			continue;
		}
	} while(true);
	
	if (doesDragExist){
		std::cout << "Enter the value of coefficient of drag:";
		std::cin >> cod;
	} else {
		cod = 0;
	}
	
	do {
		std::string decision;
		std::cout << "Wind ON/OFF (1:ON, 2:OFF):";
		std::cin >> decision;
		if (decision == "1" || decision == "2"){
			if (decision == "1"){
				doesWindExist = true;
				break;
			} else {
				doesWindExist = false;
				break;
			}
		} else {
			std::cout << "Enter only 1 or 2 please!" << "\n";
			continue;
		}
	} while(true);
	
	if (doesWindExist){
		std::cout << "Enter the  x value of wind force:";
		std::cin >> windForceX;
		std::cout << "Enter the y value of wind force:";
		std::cin >> windForceY;
	} else {
		windForceX = 0;
		windForceY = 0;
	}
	
	Ball ball(0, ballPosition, ballMass, cor, cod);
	
	PhysicsWorld pw(ball, ground, windForceX, windForceY, gravityY);
	
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
			std::cout << "COR: " << ball.getCOR() << "\n";
			std::cout << "Mass: " << ball.getMass() << "\n";
			std::cout << "Velocity: (" << ball.getVelocity().getX() << ", " << ball.getVelocity().getY() << ")" << "\n";
			std::cout << "Position: (" << ball.getPosition().getX() << ", " << ball.getPosition().getY() << ")" << "\n";
			std::cout << "Net Force: (" << pw.getNetForce().getX() << ", " << pw.getNetForce().getY() << ")" << "\n";	
			std::cout << "Drag Force: (" << pw.getDragForce().getX() << ", " << pw.getDragForce().getY() << ")" << "\n";
			std::cout << "Wind Force: (" << pw.getWindForce().getX() << ", " << pw.getWindForce().getY() << ")" << "\n";
			std::cout << "Gravity Force: (" << pw.getGravityForce().getX() << ", " << pw.getGravityForce().getY() << ")" << "\n";
			std::cout << "\n\n";
		}
	}
	
	return 0;
}
