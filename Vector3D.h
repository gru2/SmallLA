#ifndef __VECTOR3D_H
#define __VECTOR3D_H
#include <math.h>

class Vector3D {
public:
	double x;
	double y;
	double z;
	Vector3D() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3D(double a) {
		x = a;
		y = a;
		z = a;
	}
	Vector3D(double ax, double ay, double az) {
		x = ax;
		y = ay;
		z = az;
	}
	Vector3D(const Vector3D &a) {
		x = a.x;
		y = a.y;
		z = a.z;
	}
	Vector3D uminus() {
		return Vector3D(-x, -y, -z);
	}
	Vector3D plus(const Vector3D &v) {
		return Vector3D(x + v.x, y + v.y, z + v.z);
	}
	void plusEquals(const Vector3D &v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}
	Vector3D minus(const Vector3D &v) {
		return Vector3D(x - v.x, y - v.y, z - v.z);
	}
	void minusEquals(const Vector3D &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	Vector3D times(double ax) {
		return Vector3D(x * ax, y * ax, z * ax);
	}
	void timesEquals(double ax) {
		x *= ax;
		y *= ax;
		z *= ax;
	}
	Vector3D divide(double ax) {
		return times(1.0/ax);
	}
	void divideEquals(double ax) {
		timesEquals(1.0/ax);
	}
	double dot(const Vector3D &v) {
		double s = x * v.x + y * v.y + z * v.z;
		return s;
	}
	Vector3D cross(const Vector3D &rhs) {
		double xt = y * rhs.z - z * rhs.y;
		double yt = z * rhs.x - x * rhs.z;
		double zt = x * rhs.y - y * rhs.x;
		return Vector3D(xt, yt, zt);
	}
	Vector3D normalize() {
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
		return s;
	}
	double distance(const Vector3D &v) {
		return sqrt(squaredDistance(v));
	}
	double squaredDistance(const Vector3D &v) {
		double s =
			(x - v.x) * (x - v.x) +
			(y - v.y) * (y - v.y) +
			(z - v.z) * (z - v.z);
		return s;
	}
};
#endif
