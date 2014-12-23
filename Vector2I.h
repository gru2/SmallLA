#ifndef __VECTOR2I_H
#define __VECTOR2I_H


class Vector2I {
public:
	int x;
	int y;
	Vector2I() {
		x = 0;
		y = 0;
	}
	Vector2I(int a) {
		x = a;
		y = a;
	}
	Vector2I(int ax, int ay) {
		x = ax;
		y = ay;
	}
	Vector2I(const Vector2I &a) {
		x = a.x;
		y = a.y;
	}
	Vector2I uminus() {
		return Vector2I(-x, -y);
	}
	Vector2I plus(const Vector2I &v) {
		return Vector2I(x + v.x, y + v.y);
	}
	void plusEquals(const Vector2I &v) {
		x += v.x;
		y += v.y;
	}
	Vector2I minus(const Vector2I &v) {
		return Vector2I(x - v.x, y - v.y);
	}
	void minusEquals(const Vector2I &v) {
		x -= v.x;
		y -= v.y;
	}
};
#endif
