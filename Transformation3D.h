#ifndef __TRANSFORMATION3D_H
#define __TRANSFORMATION3D_H

#include <Matrix3D.h>
#include <Vector3D.h>

class Transformation3D {
public:
	Matrix3D a; // linear part
	Vector3D b; // offset

	Transformation3D() { }
	Transformation3D(const Matrix3D &a_, const Vector3D &b_) : a(a_),
		b(b_) { }
	Transformation3D(const Transformation3D &x) : a(x.a), b(x.b) { }
	Transformation3D times(const Transformation3D &x) {
		return Transformation3D(a.times(x.a), b.plus(a.times(x.b)));
	}
	Vector3D times(Vector3D &x) {
		return a.times(x).plus(b);
	}
	void timesEquals(const Transformation3D &x) {
		a.timesEquals(x.a);
		b.plusEquals(x.b);
	}
	void setIdentity() {
		a.setIdentity();
		b = Vector3D(0);
	}
	Transformation3D inv() {
		Transformation3D r;
		r.a = a.inv();
		r.b = r.a.times(b).uminus();
		return r;
	}
};

#endif
