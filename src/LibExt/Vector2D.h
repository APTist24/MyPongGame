#ifndef __UserVector__
#define __UserVector__

#include <math.h>

class Vector2D
{
public:
	Vector2D(float x_, float y_) : x(x_), y(y_) {}

	float getX() { return x; }
	float getY() { return y; }

	void setX(float x_) { x = x_; }
	void setY(float y_) { y = y_; }

	float length() { return sqrt(x * x + y * y); }

	void normalize()
	{
		float l = length();
		if (l > 0) // we never want to attempt to divide by 0
		{
			(*this) *= 1 / l;
		}
	}
//+
	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(x + v2.x, y + v2.y);
	}
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}
//*
	Vector2D operator*(float scalar)
	{
		return Vector2D(x * scalar, y * scalar);
	}
	Vector2D& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}
//-
	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(x - v2.x, y - v2.y);
	}
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}
// divide
	Vector2D operator/(float scalar)
	{
		return Vector2D(x / scalar, y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

private:
	float x;
	float y;
};
#endif
