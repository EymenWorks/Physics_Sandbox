#include "Vector2.h"

Vector2::Vector2(float x, float y){
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
	if (scalar == 0) throw std::runtime_error("Division by zero error!");
	return Vector2(x / scalar, y / scalar);
}

void Vector2::setX(float x){
	this->x = x;
}

void Vector2::setY(float y){
	this->y = y;
}

float Vector2::getX() const {
	return x;
}

float Vector2::getY() const {
	return y;
}

float Vector2::length() const {
	return std::hypot(x, y);
}

Vector2 Vector2::normalize() const {
	if (x == 0 && y == 0) return Vector2(0, 0);
	return Vector2(x / length(), y / length());
}
