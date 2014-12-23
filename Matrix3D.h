#ifndef __MATRIX3D_H
#define __MATRIX3D_H
#include <math.h>
#include <Vector3D.h>

class Matrix3D {
public:
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
	Matrix3D() {
		m11 = 0;
		m12 = 0;
		m13 = 0;
		m21 = 0;
		m22 = 0;
		m23 = 0;
		m31 = 0;
		m32 = 0;
		m33 = 0;
	}
	Matrix3D(double a) {
		m11 = a;
		m12 = a;
		m13 = a;
		m21 = a;
		m22 = a;
		m23 = a;
		m31 = a;
		m32 = a;
		m33 = a;
	}
	Matrix3D(double am11, double am12, double am13, double am21, double am22, double am23, double am31, double am32, double am33) {
		m11 = am11;
		m12 = am12;
		m13 = am13;
		m21 = am21;
		m22 = am22;
		m23 = am23;
		m31 = am31;
		m32 = am32;
		m33 = am33;
	}
	Matrix3D(const Matrix3D &a) {
		m11 = a.m11;
		m12 = a.m12;
		m13 = a.m13;
		m21 = a.m21;
		m22 = a.m22;
		m23 = a.m23;
		m31 = a.m31;
		m32 = a.m32;
		m33 = a.m33;
	}
	Matrix3D uminus() {
		return Matrix3D(-m11, -m12, -m13, -m21, -m22, -m23, -m31, -m32, -m33);
	}
	Matrix3D plus(const Matrix3D &v) {
		return Matrix3D(m11 + v.m11, m12 + v.m12, m13 + v.m13, m21 + v.m21, m22 + v.m22, m23 + v.m23, m31 + v.m31, m32 + v.m32, m33 + v.m33);
	}
	void plusEquals(const Matrix3D &v) {
		m11 += v.m11;
		m12 += v.m12;
		m13 += v.m13;
		m21 += v.m21;
		m22 += v.m22;
		m23 += v.m23;
		m31 += v.m31;
		m32 += v.m32;
		m33 += v.m33;
	}
	Matrix3D minus(const Matrix3D &v) {
		return Matrix3D(m11 - v.m11, m12 - v.m12, m13 - v.m13, m21 - v.m21, m22 - v.m22, m23 - v.m23, m31 - v.m31, m32 - v.m32, m33 - v.m33);
	}
	void minusEquals(const Matrix3D &v) {
		m11 -= v.m11;
		m12 -= v.m12;
		m13 -= v.m13;
		m21 -= v.m21;
		m22 -= v.m22;
		m23 -= v.m23;
		m31 -= v.m31;
		m32 -= v.m32;
		m33 -= v.m33;
	}
	Matrix3D times(double ax) {
		return Matrix3D(m11 * ax, m12 * ax, m13 * ax, m21 * ax, m22 * ax, m23 * ax, m31 * ax, m32 * ax, m33 * ax);
	}
	void timesEquals(double ax) {
		m11 *= ax;
		m12 *= ax;
		m13 *= ax;
		m21 *= ax;
		m22 *= ax;
		m23 *= ax;
		m31 *= ax;
		m32 *= ax;
		m33 *= ax;
	}
	Matrix3D divide(double ax) {
		return times(1.0/ax);
	}
	void divideEquals(double ax) {
		timesEquals(1.0/ax);
	}
	Matrix3D times(const Matrix3D &v) {
		Matrix3D r;
		r.m11 = m11 * v.m11 + m12 * v.m21 + m13 * v.m31;
		r.m12 = m21 * v.m11 + m22 * v.m21 + m23 * v.m31;
		r.m13 = m31 * v.m11 + m32 * v.m21 + m33 * v.m31;
		r.m21 = m11 * v.m12 + m12 * v.m22 + m13 * v.m32;
		r.m22 = m21 * v.m12 + m22 * v.m22 + m23 * v.m32;
		r.m23 = m31 * v.m12 + m32 * v.m22 + m33 * v.m32;
		r.m31 = m11 * v.m13 + m12 * v.m23 + m13 * v.m33;
		r.m32 = m21 * v.m13 + m22 * v.m23 + m23 * v.m33;
		r.m33 = m31 * v.m13 + m32 * v.m23 + m33 * v.m33;
		return r;
	}
	void timesEquals(const Matrix3D &v) {
		Matrix3D r;
		r.m11 = m11 * v.m11 + m12 * v.m21 + m13 * v.m31;
		r.m12 = m21 * v.m11 + m22 * v.m21 + m23 * v.m31;
		r.m13 = m31 * v.m11 + m32 * v.m21 + m33 * v.m31;
		r.m21 = m11 * v.m12 + m12 * v.m22 + m13 * v.m32;
		r.m22 = m21 * v.m12 + m22 * v.m22 + m23 * v.m32;
		r.m23 = m31 * v.m12 + m32 * v.m22 + m33 * v.m32;
		r.m31 = m11 * v.m13 + m12 * v.m23 + m13 * v.m33;
		r.m32 = m21 * v.m13 + m22 * v.m23 + m23 * v.m33;
		r.m33 = m31 * v.m13 + m32 * v.m23 + m33 * v.m33;
		*this = r;
	}
	Vector3D times(const Vector3D &v) {
		Vector3D r;
		r.x = m11 * v.x + m12 * v.y + m13 * v.z;
		r.y = m21 * v.x + m22 * v.y + m23 * v.z;
		r.z = m31 * v.x + m32 * v.y + m33 * v.z;
		return r;
	}
	Vector3D transposeTimes(const Vector3D &v) {
		Vector3D r;
		r.x = m11 * v.x + m21 * v.y + m31 * v.z;
		r.y = m12 * v.x + m22 * v.y + m32 * v.z;
		r.z = m13 * v.x + m23 * v.y + m33 * v.z;
		return r;
	}
	void setIdentity() {
		m11 = 1;
		m12 = 0;
		m13 = 0;
		m21 = 0;
		m22 = 1;
		m23 = 0;
		m31 = 0;
		m32 = 0;
		m33 = 1;
	}
	double det() {
		double t1 = m11*m22*m33;
		double t2 = m12*m23*m31;
		double t3 = m13*m21*m32;
		double t4 = m13*m22*m31;
		double t5 = m12*m21*m33;
		double t6 = m11*m23*m32;
		return t1 + t2 + t3 - t4 - t5 - t6;
	}
	Matrix3D inv() {
		double d = det();
		double t11 = m22*m33-m23*m32;
		double t12 = m13*m32-m12*m33;
		double t13 = m12*m23-m13*m22;
		double t21 = m23*m31-m21*m33;
		double t22 = m11*m33-m13*m31;
		double t23 = m13*m21-m11*m23;
		double t31 = m21*m32-m22*m31;
		double t32 = m12*m31-m11*m32;
		double t33 = m11*m22-m12*m21;
		t11 /= d;
		t12 /= d;
		t13 /= d;
		t21 /= d;
		t22 /= d;
		t23 /= d;
		t31 /= d;
		t32 /= d;
		t33 /= d;
		return Matrix3D(t11,t12,t13,t21,t22,t23,t31,t32,t33);
	}
};
#endif
