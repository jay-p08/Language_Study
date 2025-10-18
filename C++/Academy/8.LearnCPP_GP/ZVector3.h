#pragma once

#include <iostream>

class ZMatrix;

class ZVector3 {
public:
	double x, y, z;

	ZVector3();
	ZVector3(double x = 0.0, double y = 0.0, double z = 0.0);
	ZVector3(const ZVector3& other);
	~ZVector3();

	// 멤버 함수
	double Dot(const ZVector3& rhs) const;
	ZVector3 Cross(const ZVector3& rhs) const;
	ZVector3 Scale(double k) const;
	double Length() const;
	double radBetween(const ZVector3& a, const ZVector3& b) const;
	double degBetween(const ZVector3& a, const ZVector3& b) const;
	ZVector3 Normalize() const;
	ZVector3 Transform(const ZMatrix& matrix) const;

	// 정적(static) 함수
	static double Dot(const ZVector3& u, const ZVector3& v); // 내적 (정적 멤버 함수)
	static ZVector3 Cross(const ZVector3& u, const ZVector3& v); // 외적 (정적 멤버 함수)

	ZVector3 operator+(const ZVector3& other) const;
	ZVector3 operator-(const ZVector3& other) const;
	void operator=(const ZVector3& rhs);
	ZVector3 operator*(const ZVector3& rhs) const; // 성분별 곱셈 (Hadamard Product)
	ZVector3 operator*(double k) const;


	friend std::ostream& operator<<(std::ostream& os, const ZVector3& vec) {
		os << "ZVector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return os;
	}
};