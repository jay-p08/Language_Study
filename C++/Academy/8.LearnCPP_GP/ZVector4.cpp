#include "ZVector4.h"
#include "ZVector3.h"
#include <cmath>
#include "ZMatrix.h"

// --- ZVector4 클래스 구현 ---

// 생성자 및 소멸자
ZVector4::ZVector4() : x(0.0), y(0.0), z(0.0), w(0.0) {}

ZVector4::ZVector4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

// ZVector3로부터 ZVector4를 생성하는 생성자 (주로 w=1을 넣어 사용)
ZVector4::ZVector4(const ZVector3& rhs, double w) : x(rhs.x), y(rhs.y), z(rhs.z), w(w) {}

ZVector4::ZVector4(const ZVector4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}

ZVector4::~ZVector4() {}

// 멤버 함수
ZVector4 ZVector4::Transform(const ZMatrix& matrix) const
{
    ZVector4 result;
    result.x = this->x * matrix.m[0][0] + this->y * matrix.m[1][0] + this->z * matrix.m[2][0] + this->w * matrix.m[3][0];
    result.y = this->x * matrix.m[0][1] + this->y * matrix.m[1][1] + this->z * matrix.m[2][1] + this->w * matrix.m[3][1];
    result.z = this->x * matrix.m[0][2] + this->y * matrix.m[1][2] + this->z * matrix.m[2][2] + this->w * matrix.m[3][2];
    result.w = this->x * matrix.m[0][3] + this->y * matrix.m[1][3] + this->z * matrix.m[2][3] + this->w * matrix.m[3][3];
    return result;
}

/**
 * @brief 원근 나누기(Perspective Divide)를 수행합니다.
 * 
 * @details 3D 렌더링 파이프라인에서 이 함수는 매우 특정한 시점에 사용됩니다:
 *          '클립 공간(Clip Space)' 좌표를 '정규화된 장치 좌표(NDC)'로 변환하는 단계입니다.
 *          - 클립 공간 좌표: 월드-뷰-투영(WVP) 행렬을 모두 곱한 후의 4D 벡터.
 *                          이때 w 성분은 카메라로부터의 거리(깊이) 정보를 가집니다.
 *          - NDC 좌표: 클립 공간의 x, y, z를 w로 나누어 얻는 3D 벡터.
 *                      이 과정을 통해 멀리 있는 물체는 작게 보이는 '원근 효과'가 적용됩니다.
 * 
 * @return ZVector3 원근감이 적용된 NDC 좌표 (Direct3D 기준: x,y는 -1~1, z는 0~1 사이의 값을 가짐)
 */
ZVector3 ZVector4::PerspectiveDivide() const
{
    // w가 0에 매우 가까운 경우(0으로 나누기 방지)를 대비합니다.
    if (w == 0.0)
    {
        return ZVector3(0.0, 0.0, 0.0);
    }
    // w로 x, y, z를 나누어 NDC(Normalized Device Coordinates)로 변환합니다.
    // 곱셈이 나눗셈보다 연산 비용이 저렴하므로 역수(1/w)를 곱하는 방식을 사용합니다.
    double invW = 1.0 / w;
    return ZVector3(x * invW, y * invW, z * invW);
}

// 연산자 오버로딩
void ZVector4::operator=(const ZVector4& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    this->w = rhs.w;
}

double ZVector4::Dot(const ZVector4& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

ZVector4 ZVector4::Scale(double k) const
{
    return ZVector4(x * k, y * k, z * k, w * k);
}

double ZVector4::Length() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}

ZVector4 ZVector4::Normalize() const
{
    double len = Length();
    if (len == 0.0) return ZVector4(0.0, 0.0, 0.0, 0.0);
    double invLen = 1.0 / len;
    return ZVector4(x * invLen, y * invLen, z * invLen, w * invLen);
}

// 정적(static) 함수
double ZVector4::Dot(const ZVector4& u, const ZVector4& v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}

// 연산자 오버로딩
ZVector4 ZVector4::operator+(const ZVector4& other) const
{
    return ZVector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

ZVector4 ZVector4::operator-(const ZVector4& other) const
{
    return ZVector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

ZVector4 ZVector4::operator*(const ZVector4& rhs) const
{
    return ZVector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}

ZVector4 ZVector4::operator*(double k) const
{
    return ZVector4(x * k, y * k, z * k, w * k);
}
