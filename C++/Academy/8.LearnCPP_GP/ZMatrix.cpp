#include "ZMatrix.h"
#include <cmath> // sin, cos

ZMatrix::ZMatrix()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m[i][j] = (i == j) ? 1.0 : 0.0;
}

ZMatrix ZMatrix::CreateScale(double sx, double sy, double sz)
{
	ZMatrix mat;
	mat.m[0][0] = sx;
	mat.m[1][1] = sy;
	mat.m[2][2] = sz;
	return mat;
}

ZMatrix ZMatrix::CreateRotationX(double radians)
{
	ZMatrix mat;
	double c = cos(radians);
	double s = sin(radians);
	mat.m[1][1] = c; mat.m[1][2] = -s;
	mat.m[2][1] = s; mat.m[2][2] = c;
	return mat;
}

ZMatrix ZMatrix::CreateRotationY(double radians)
{
	ZMatrix mat;
	double c = cos(radians);
	double s = sin(radians);
	mat.m[0][0] = c; mat.m[0][2] = -s;
	mat.m[2][0] = s; mat.m[2][2] = c;
	return mat;
}

ZMatrix ZMatrix::CreateRotationZ(double radians)
{
	ZMatrix mat;
	double c = cos(radians);
	double s = sin(radians);
	mat.m[0][0] = c; mat.m[0][1] = -s;
	mat.m[1][0] = s; mat.m[1][1] = c;
	return mat;
}

ZMatrix ZMatrix::CreateTranslation(double tx, double ty, double tz)
{
	ZMatrix mat;
	mat.m[3][0] = tx;
	mat.m[3][1] = ty;
	mat.m[3][2] = tz;
	return mat;
}

ZMatrix ZMatrix::operator*(const ZMatrix& rhs) const
{
	ZMatrix result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = (this->m[i][0] * rhs.m[0][j]) +
							 (this->m[i][1] * rhs.m[1][j]) +
							 (this->m[i][2] * rhs.m[2][j]) +
							 (this->m[i][3] * rhs.m[3][j]);
		}
	}
	return result;
}

