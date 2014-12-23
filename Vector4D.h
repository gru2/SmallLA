#ifndef __VECTOR4D_H
#define __VECTOR4D_H
#include <math.h>

class Vector4D {
public:
	double x;
	double y;
	double z;
	double w;
	Vector4D() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector4D(double a) {
		x = a;
		y = a;
		z = a;
		w = a;
	}
	Vector4D(double ax, double ay, double az, double aw) {
		x = ax;
		y = ay;
		z = az;
		w = aw;
	}
	Vector4D(const Vector4D &a) {
		x = a.x;
		y = a.y;
		z = a.z;
		w = a.w;
	}
	Vector4D uminus() {
		return Vector4D(-x, -y, -z, -w);
	}
	Vector4D plus(const Vector4D &v) {
		return Vector4D(x + v.x, y + v.y, z + v.z, w + v.w);
	}
	void plusEquals(const Vector4D &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
	}
	Vector4D minus(const Vector4D &v) {
		return Vector4D(x - v.x, y - v.y, z - v.z, w - v.w);
	}
	void minusEquals(const Vector4D &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
	}
	Vector4D times(double ax) {
		return Vector4D(x * ax, y * ax, z * ax, w * ax);
	}
	void timesEquals(double ax) {
		x *= ax;
		y *= ax;
		z *= ax;
		w *= ax;
	}
	Vector4D divide(double ax) {
		return times(1.0/ax);
	}
	void divideEquals(double ax) {
		timesEquals(1.0/ax);
	}
	double dot(const Vector4D &v) {
		double s = x * v.x + y * v.y + z * v.z + w * v.w;
		return s;
	}
	Vector4D normalize() {
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
		s += z * z;
		s += w * w;
		return s;
	}
	double distance(const Vector4D &v) {
		return sqrt(squaredDistance(v));
	}
	double squaredDistance(const Vector4D &v) {
		double s =
			(x - v.x) * (x - v.x) +
			(y - v.y) * (y - v.y) +
			(z - v.z) * (z - v.z) +
			(w - v.w) * (w - v.w);
		return s;
	}
};
#endif
