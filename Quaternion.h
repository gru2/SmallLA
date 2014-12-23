#ifndef __QUATERNION_H
#define __QUATERNION_H
#include <math.h>
#include <Matrix3D.h>

class Quaternion {
public:
	double w;
	double x;
	double y;
	double z;
	Quaternion() {
		w = 0;
		x = 0;
		y = 0;
		z = 0;
	}
	Quaternion(double a) {
		w = a;
		x = a;
		y = a;
		z = a;
	}
	Quaternion(double aw, double ax, double ay, double az) {
		w = aw;
		x = ax;
		y = ay;
		z = az;
	}
	Quaternion(const Quaternion &a) {
		w = a.w;
		x = a.x;
		y = a.y;
		z = a.z;
	}
	Quaternion uminus() {
		return Quaternion(-w, -x, -y, -z);
	}
	Quaternion plus(const Quaternion &v) {
		return Quaternion(w + v.w, x + v.x, y + v.y, z + v.z);
	}
	void plusEquals(const Quaternion &v) {
		w += v.w;
		x += v.x;
		y += v.y;
		z += v.z;
	}
	Quaternion minus(const Quaternion &v) {
		return Quaternion(w - v.w, x - v.x, y - v.y, z - v.z);
	}
	void minusEquals(const Quaternion &v) {
		w -= v.w;
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	Quaternion times(const Quaternion &rhs) {
		double wt = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
		double xt = x * rhs.w + w * rhs.x + y * rhs.z - z * rhs.y;
		double yt = y * rhs.w + w * rhs.y + z * rhs.x - x * rhs.z;
		double zt = z * rhs.w + w * rhs.z + x * rhs.y - y * rhs.x;
		return Quaternion(wt, xt, yt, zt);
	}
	void timesEquals(const Quaternion &rhs) {
		double wt = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
		double xt = x * rhs.w + w * rhs.x + y * rhs.z - z * rhs.y;
		double yt = y * rhs.w + w * rhs.y + z * rhs.x - x * rhs.z;
		double zt = z * rhs.w + w * rhs.z + x * rhs.y - y * rhs.x;
		w = wt;
		x = xt;
		y = yt;
		z = zt;
	}
	Quaternion times(double ax) {
		return Quaternion(w * ax, x * ax, y * ax, z * ax);
	}
	void timesEquals(double ax) {
		w *= ax;
		x *= ax;
		y *= ax;
		z *= ax;
	}
	Quaternion divide(double ax) {
		return times(1.0/ax);
	}
	void divideEquals(double ax) {
		timesEquals(1.0/ax);
	}
	double dot(const Quaternion &v) {
		double s = w * v.w + x * v.x + y * v.y + z * v.z;
		return s;
	}
	Quaternion normalize() {
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
		s += w * w;
		s += x * x;
		s += y * y;
		s += z * z;
		return s;
	}
	double distance(const Quaternion &v) {
		return sqrt(squaredDistance(v));
	}
	double squaredDistance(const Quaternion &v) {
		double s =
			(w - v.w) * (w - v.w) +
			(x - v.x) * (x - v.x) +
			(y - v.y) * (y - v.y) +
			(z - v.z) * (z - v.z);
		return s;
	}
	Matrix3D toMatrix3() {
		double xx = x*x;
		double xy = x*y;
		double xz = x*z;
		double xw = x*w;
		double yy = y*y;
		double yz = y*z;
		double yw = y*w;
		double zz = z*z;
		double zw = z*w;
		double m11 = 1.0 - 2.0 * ( yy + zz );
		double m12 = 2.0 * ( xy - zw );
		double m13 = 2.0 * ( xz + yw );
		double m21 = 2.0 * ( xy + zw );
		double m22 = 1.0 - 2.0 * ( xx + zz );
		double m23 = 2.0 * ( yz - xw );
		double m31 = 2.0 * ( xz - yw );
		double m32 = 2.0 * ( yz + xw );
		double m33 = 1.0 - 2.0 * ( xx + yy );
		return Matrix3D(m11, m12, m13, m21, m22, m23, m31, m32, m33);
	}
	static Quaternion identity() {
		return Quaternion(1.0, 0.0, 0.0, 0.0);
	}
	static Quaternion rotationX(double angle) {
		double s = sin(0.5 * angle);
		double c = cos(0.5 * angle);
		return Quaternion(c, s, 0.0, 0.0);
	}
	static Quaternion rotationY(double angle) {
		double s = sin(0.5 * angle);
		double c = cos(0.5 * angle);
		return Quaternion(c, 0.0, s, 0.0);
	}
	static Quaternion rotationZ(double angle) {
		double s = sin(0.5 * angle);
		double c = cos(0.5 * angle);
		return Quaternion(c, 0.0, 0.0, s);
	}
};
#endif
