#include "ZVector3.h"
#include "ZMatrix.h"
#include <cmath> // sqrt, sin, cos

#pragma region Static Functions

double ZVector3::Dot(const ZVector3& u, const ZVector3& v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

ZVector3 ZVector3::Cross(const ZVector3& u, const ZVector3& v)
{
	double x = u.y * v.z - u.z * v.y;
	double y = u.z * v.x - u.x * v.z;
	double z = u.x * v.y - u.y * v.x;
	return ZVector3(x, y, z);
}

#pragma endregion

#pragma region Constructors and Destructor

ZVector3::ZVector3() : x(0.0f), y(0.0f), z(0.0f) {}

ZVector3::ZVector3(double x, double y, double z) : x(x), y(y), z(z) {}

ZVector3::ZVector3(const ZVector3& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

ZVector3::~ZVector3() {}

#pragma endregion

#pragma region member Functions

double ZVector3::Dot(const ZVector3& rhs) const
{
	return (this->x * rhs.x) + (this->y * rhs.y) + (this->z * rhs.z);
}

ZVector3 ZVector3::Scale(double k) const
{
	return ZVector3(this->x * k, this->y * k, this->z * k);
}

double ZVector3::Length() const
{
	// std::sqrt(x * x + y * y + z * z);
	return sqrt(Dot(*this));
}

double ZVector3::radBetween(const ZVector3& a, const ZVector3& b) const
{
	double dotProduct = Dot(a, b);
	double magA = a.Length();
	double magB = b.Length();

	if (magA == 0.0 || magB == 0.0) {
		throw std::runtime_error("Zero-length vector provided.");
	}

	double cosTheta = dotProduct / (magA * magB);

	// floating point           ([-1, 1]             )
	if (cosTheta > 1.0) cosTheta = 1.0;
	if (cosTheta < -1.0) cosTheta = -1.0;

	return std::acos(cosTheta);
}

double ZVector3::degBetween(const ZVector3& a, const ZVector3& b) const {
	return radBetween(a, b) * 180.0 / 3.141592;
}

ZVector3 ZVector3::Normalize() const
{
	double len = Length();
	if (len == 0.0) return ZVector3(0, 0, 0);
	return ZVector3(this->x / len, this->y / len, this->z / len);
}

ZVector3 ZVector3::Cross(const ZVector3& rhs) const
{
	return ZVector3::Cross(*this, rhs);
}

ZVector3 ZVector3::Transform(const ZMatrix& matrix) const
{
	// D3D는 행-벡터(row-vector)를 사용하므로, 동차좌표의 w=1을 적용하여 변환합니다.
	double newX = x * matrix.m[0][0] + y * matrix.m[1][0] + z * matrix.m[2][0] + 1.0 * matrix.m[3][0];
	double newY = x * matrix.m[0][1] + y * matrix.m[1][1] + z * matrix.m[2][1] + 1.0 * matrix.m[3][1];
	double newZ = x * matrix.m[0][2] + y * matrix.m[1][2] + z * matrix.m[2][2] + 1.0 * matrix.m[3][2];
	return ZVector3(newX, newY, newZ);
}

#pragma endregion

#pragma region Operator Overloads

ZVector3 ZVector3::operator+(const ZVector3& rhs) const
{
	return ZVector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

ZVector3 ZVector3::operator-(const ZVector3& rhs) const
{
	return ZVector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

void ZVector3::operator=(const ZVector3& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

ZVector3 ZVector3::operator*(const ZVector3& rhs) const
{
	return ZVector3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
}

ZVector3 ZVector3::operator*(double k) const
{
	return Scale(k);
}

#pragma endregion
