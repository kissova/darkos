// HMOOD__TG@i_8_f
 

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


struct Vector3
{
    union
    {
        struct
        {
            float X;
            float Y;
            float Z;
        };
        float data[3];
    };


     
    inline Vector3();
    inline Vector3(float data[]);
    inline Vector3(float value);
    inline Vector3(float x, float y);
    inline Vector3(float x, float y, float z);


     
    static inline Vector3 Zero();
    
    static inline Vector3 Right();
    static inline Vector3 Left();
    static inline Vector3 Up();
    static inline Vector3 Down();
    static inline Vector3 Forward();


 
    static inline float Angle(Vector3 a, Vector3 b);

     
    

     
    static inline float Component(Vector3 a, Vector3 b);

     
    static inline Vector3 Cross(Vector3 lhs, Vector3 rhs);

     
    static inline float Distance(Vector3 a, Vector3 b);


 
    static inline float Dot(Vector3 lhs, Vector3 rhs);

     
    

     
    static inline Vector3 Lerp(Vector3 a, Vector3 b, float t);

     
    static inline Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t);

     
    static inline float Magnitude(Vector3 v);

     
    static inline Vector3 Max(Vector3 a, Vector3 b);

     
    static inline Vector3 Min(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 Normalized(Vector3 v);

     
    

     
    

     
    static inline Vector3 Project(Vector3 a, Vector3 b);

     
    static inline Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal);

     
    

     
    static inline Vector3 Reject(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 Scale(Vector3 a, Vector3 b);

     
    

     
    static inline Vector3 SlerpUnclamped(Vector3 a, Vector3 b, float t);

     
    static inline float SqrMagnitude(Vector3 v);

     


 
    inline struct Vector3& operator+=(const float rhs);
    inline struct Vector3& operator-=(const float rhs);
    inline struct Vector3& operator*=(const float rhs);
    inline struct Vector3& operator/=(const float rhs);
    inline struct Vector3& operator+=(const Vector3 rhs);
    inline struct Vector3& operator-=(const Vector3 rhs);
};

inline Vector3 operator-(Vector3 rhs);
inline Vector3 operator+(Vector3 lhs, const float rhs);
inline Vector3 operator-(Vector3 lhs, const float rhs);
inline Vector3 operator*(Vector3 lhs, const float rhs);
inline Vector3 operator/(Vector3 lhs, const float rhs);
inline Vector3 operator+(const float lhs, Vector3 rhs);
inline Vector3 operator-(const float lhs, Vector3 rhs);
inline Vector3 operator*(const float lhs, Vector3 rhs);
inline Vector3 operator/(const float lhs, Vector3 rhs);
inline Vector3 operator+(Vector3 lhs, const Vector3 rhs);
inline Vector3 operator-(Vector3 lhs, const Vector3 rhs);
inline bool operator==(const Vector3 lhs, const Vector3 rhs);
inline bool operator!=(const Vector3 lhs, const Vector3 rhs);


 

Vector3::Vector3() : X(0.f), Y(0.f), Z(0.f) {}
Vector3::Vector3(float data[])
    : X(data && std::isfinite(data[0]) ? data[0] : 0.f),
      Y(data && std::isfinite(data[1]) ? data[1] : 0.f),
      Z(data && std::isfinite(data[2]) ? data[2] : 0.f) {}
Vector3::Vector3(float value)
    : X(std::isfinite(value) ? value : 0.f),
      Y(std::isfinite(value) ? value : 0.f),
      Z(std::isfinite(value) ? value : 0.f) {}
Vector3::Vector3(float x, float y)
    : X(std::isfinite(x) ? x : 0.f),
      Y(std::isfinite(y) ? y : 0.f),
      Z(0.f) {}
Vector3::Vector3(float x, float y, float z)
    : X(std::isfinite(x) ? x : 0.f),
      Y(std::isfinite(y) ? y : 0.f),
      Z(std::isfinite(z) ? z : 0.f) {}


Vector3 Vector3::Zero() { return Vector3(0.f, 0.f, 0.f); }

Vector3 Vector3::Right() { return Vector3(1.f, 0.f, 0.f); }
Vector3 Vector3::Left() { return Vector3(-1.f, 0.f, 0.f); }
Vector3 Vector3::Up() { return Vector3(0.f, 1.f, 0.f); }
Vector3 Vector3::Down() { return Vector3(0.f, -1.f, 0.f); }
Vector3 Vector3::Forward() { return Vector3(0.f, 0.f, 1.f); }


float Vector3::Angle(Vector3 a, Vector3 b)
{
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    float denom = magA * magB;
    if (!std::isfinite(denom) || denom <= 1e-8f)
        return 0.f;
    float v = Dot(a, b) / denom;
    if (!std::isfinite(v))
        return 0.f;
    v = fmaxf(v, -1.0f);
    v = fminf(v, 1.0f);
    float angle = acosf(v);
    return std::isfinite(angle) ? angle : 0.f;
}


float Vector3::Component(Vector3 a, Vector3 b)
{
    float magB = Magnitude(b);
    if (!std::isfinite(magB) || magB <= 1e-8f)
        return 0.f;
    float res = Dot(a, b) / magB;
    return std::isfinite(res) ? res : 0.f;
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
    float x = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
    float y = lhs.Z * rhs.X - lhs.X * rhs.Z;
    float z = lhs.X * rhs.Y - lhs.Y * rhs.X;
    return Vector3(x, y, z);
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
    return Vector3::Magnitude(a - b);
}

float Vector3::Dot(Vector3 lhs, Vector3 rhs)
{
    float res = lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
    return std::isfinite(res) ? res : 0.f;
}


Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
    if (!std::isfinite(t)) return a;
    if (t < 0.f) return a;
    else if (t > 1.f) return b;
    return LerpUnclamped(a, b, t);
}

Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t)
{
    if (!std::isfinite(t)) return a;
    return (b - a) * t + a;
}

float Vector3::Magnitude(Vector3 v)
{
    float sqr = SqrMagnitude(v);
    if (!std::isfinite(sqr) || sqr <= 0.f)
        return 0.f;
    float m = sqrtf(sqr);
    return std::isfinite(m) ? m : 0.f;
}

Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
    float x = a.X > b.X ? a.X : b.X;
    float y = a.Y > b.Y ? a.Y : b.Y;
    float z = a.Z > b.Z ? a.Z : b.Z;
    return Vector3(x, y, z);
}

Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
    float x = a.X > b.X ? b.X : a.X;
    float y = a.Y > b.Y ? b.Y : a.Y;
    float z = a.Z > b.Z ? b.Z : a.Z;
    return Vector3(x, y, z);
}


Vector3 Vector3::Normalized(Vector3 v)
{
    float mag = Magnitude(v);
    if (!std::isfinite(mag) || mag <= 1e-8f)
        return Vector3::Zero();
    return v / mag;
}


Vector3 Vector3::Project(Vector3 a, Vector3 b)
{
    float sqrM = SqrMagnitude(b);
    if (!std::isfinite(sqrM) || sqrM <= 1e-8f)
        return Vector3::Zero();
    float scale = Dot(a, b) / sqrM;
    return std::isfinite(scale) ? (b * scale) : Vector3::Zero();
}

Vector3 Vector3::ProjectOnPlane(Vector3 vector, Vector3 planeNormal)
{
    return Reject(vector, planeNormal);
}


Vector3 Vector3::Reject(Vector3 a, Vector3 b)
{
    return a - Project(a, b);
}


Vector3 Vector3::Scale(Vector3 a, Vector3 b)
{
    return Vector3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
}


Vector3 Vector3::SlerpUnclamped(Vector3 a, Vector3 b, float t)
{
    if (!std::isfinite(t))
        return a;
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    if (magA <= 1e-8f && magB <= 1e-8f)
        return Vector3::Zero();
    if (magA <= 1e-8f)
        return LerpUnclamped(Vector3::Zero(), b, t);
    if (magB <= 1e-8f)
        return LerpUnclamped(a, Vector3::Zero(), t);

    Vector3 dirA = a / magA;
    Vector3 dirB = b / magB;
    float dot = Dot(dirA, dirB);
    dot = fmaxf(dot, -1.0f);
    dot = fminf(dot, 1.0f);
    float theta = acosf(dot) * t;
    Vector3 relativeVec = Normalized(dirB - dirA * dot);
    Vector3 newVec = dirA * cosf(theta) + relativeVec * sinf(theta);
    float interpMag = magA + (magB - magA) * t;
    return newVec * interpMag;
}

float Vector3::SqrMagnitude(Vector3 v)
{
    float res = v.X * v.X + v.Y * v.Y + v.Z * v.Z;
    return std::isfinite(res) ? res : 0.f;
}


struct Vector3& Vector3::operator+=(const float rhs)
{
    if (!std::isfinite(rhs)) return *this;
    X += rhs;
    Y += rhs;
    Z += rhs;
    return *this;
}

struct Vector3& Vector3::operator-=(const float rhs)
{
    if (!std::isfinite(rhs)) return *this;
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    return *this;
}

struct Vector3& Vector3::operator*=(const float rhs)
{
    if (!std::isfinite(rhs)) {
        X = 0.f;
        Y = 0.f;
        Z = 0.f;
        return *this;
    }
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    return *this;
}

struct Vector3& Vector3::operator/=(const float rhs)
{
    if (!std::isfinite(rhs) || fabsf(rhs) <= 1e-8f) {
        X = 0.f;
        Y = 0.f;
        Z = 0.f;
        return *this;
    }
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    return *this;
}

struct Vector3& Vector3::operator+=(const Vector3 rhs)
{
    if (std::isfinite(rhs.X)) X += rhs.X;
    if (std::isfinite(rhs.Y)) Y += rhs.Y;
    if (std::isfinite(rhs.Z)) Z += rhs.Z;
    return *this;
}

struct Vector3& Vector3::operator-=(const Vector3 rhs)
{
    if (std::isfinite(rhs.X)) X -= rhs.X;
    if (std::isfinite(rhs.Y)) Y -= rhs.Y;
    if (std::isfinite(rhs.Z)) Z -= rhs.Z;
    return *this;
}


Vector3 operator-(Vector3 rhs) { return rhs * -1.f; }
Vector3 operator+(Vector3 lhs, const float rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const float rhs) { return lhs -= rhs; }
Vector3 operator*(Vector3 lhs, const float rhs) { return lhs *= rhs; }
Vector3 operator/(Vector3 lhs, const float rhs) { return lhs /= rhs; }
Vector3 operator+(const float lhs, Vector3 rhs) { return rhs += lhs; }
Vector3 operator-(const float lhs, Vector3 rhs) { return Vector3(lhs - rhs.X, lhs - rhs.Y, lhs - rhs.Z); }
Vector3 operator*(const float lhs, Vector3 rhs) { return rhs *= lhs; }
Vector3 operator/(const float lhs, Vector3 rhs) {
    float x = (std::isfinite(rhs.X) && fabsf(rhs.X) > 1e-8f) ? (lhs / rhs.X) : 0.f;
    float y = (std::isfinite(rhs.Y) && fabsf(rhs.Y) > 1e-8f) ? (lhs / rhs.Y) : 0.f;
    float z = (std::isfinite(rhs.Z) && fabsf(rhs.Z) > 1e-8f) ? (lhs / rhs.Z) : 0.f;
    return Vector3(x, y, z);
}
Vector3 operator+(Vector3 lhs, const Vector3 rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const Vector3 rhs) { return lhs -= rhs; }

bool operator==(const Vector3 lhs, const Vector3 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

bool operator!=(const Vector3 lhs, const Vector3 rhs)
{
    return !(lhs == rhs);
}
