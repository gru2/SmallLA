#ifndef __VECTOR2D_H
#define __VECTOR2D_H
#include <math.h>

class Vector2D {
public:
	double x;
	double y;
	Vector2D() {
		x = 0;
		y = 0;
	}
	Vector2D(double a) {
		x = a;
		y = a;
	}
	Vector2D(double ax, double ay) {
		x = ax;
		y = ay;
	}
	Vector2D(const Vector2D &a) {
		x = a.x;
		y = a.y;
	}
	Vector2D uminus() {
		return Vector2D(-x, -y);
	}
	Vector2D plus(const Vector2D &v) {
		return Vector2D(x + v.x, y + v.y);
	}
	void plusEquals(const Vector2D &v) {
		x += v.x;
		y += v.y;
	}
	Vector2D minus(const Vector2D &v) {
		return Vector2D(x - v.x, y - v.y);
	}
	void minusEquals(const Vector2D &v) {
		x -= v.x;
		y -= v.y;
	}
	Vector2D times(double ax) {
		return Vector2D(x * ax, y * ax);
	}
	void timesEquals(double ax) {
		x *= ax;
		y *= ax;
	}
	Vector2D divide(double ax) {
		return times(1.0/ax);
	}
	void divideEquals(double ax) {
		timesEquals(1.0/ax);
	}
	double dot(const Vector2D &v) {
		double s = x * v.x + y * v.y;
		return s;
	}
	Vector2D normalize() {
		return divide(length());
	}
	void normalizeInPlace() {
		divideEquals(length());
	}
	double length() {
		return sqrt(squaredLength());
	}
	double squaredLength() {
		double s = 0;
		s += x * x;
		s += y * y;
		return s;
	}
	double distance(const Vector2D &v) {
		return sqrt(squaredDistance(v));
	}
	double squaredDistance(const Vector2D &v) {
		double s =
			(x - v.x) * (x - v.x) +
			(y - v.y) * (y - v.y);
		return s;
	}
};
#endif
