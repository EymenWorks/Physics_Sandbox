#include <cmath>
#include <stdexcept>

class Vector2 {
	float x;
	float y;
	public:
		Vector2 (float x, float y);
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(float scalar) const;
		Vector2 operator/(float scalar) const;
		void setX(float x);
		void setY(float y);
		float getX() const;
		float getY() const;
		float length() const;
		Vector2 normalize() const;
};
