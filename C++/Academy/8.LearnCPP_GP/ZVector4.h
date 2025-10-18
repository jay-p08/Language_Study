#pragma once

#include <iostream>

// 다른 클래스들의 전방 선언
class ZMatrix;
class ZVector3;

class ZVector4
{
public:
    double x, y, z, w;

public:
    // 생성자 및 소멸자
    ZVector4();
    ZVector4(double x, double y, double z, double w);
    ZVector4(const ZVector3& rhs, double w);
    ZVector4(const ZVector4& rhs);
    ~ZVector4();

    // 멤버 함수
    ZVector4 Transform(const ZMatrix& matrix) const;
    ZVector3 PerspectiveDivide() const;

    // 멤버 함수
    double Dot(const ZVector4& rhs) const;
    ZVector4 Scale(double k) const;
    double Length() const;
    ZVector4 Normalize() const;

    // 정적(static) 함수
    static double Dot(const ZVector4& u, const ZVector4& v);

    // 연산자 오버로딩
    ZVector4 operator+(const ZVector4& other) const;
    ZVector4 operator-(const ZVector4& other) const;
    void operator=(const ZVector4& rhs);
    ZVector4 operator*(const ZVector4& rhs) const; // 성분별 곱셈 (Hadamard Product)
    ZVector4 operator*(double k) const;

    friend std::ostream& operator<<(std::ostream& os, const ZVector4& vec) {
        os << "ZVector4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
        return os;
    }
};
