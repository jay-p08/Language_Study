#pragma once

class ZMatrix
{
public:
	double m[4][4];

public:
	ZMatrix(); // 단위행렬로 초기화

	ZMatrix operator*(const ZMatrix& rhs) const;

	static ZMatrix CreateScale(double sx, double sy, double sz);
	static ZMatrix CreateRotationX(double radians);
	static ZMatrix CreateRotationY(double radians);
	static ZMatrix CreateRotationZ(double radians);
	static ZMatrix CreateTranslation(double tx, double ty, double tz);
};