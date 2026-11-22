// HMOOD__TG@i_8_f
 

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


struct Vector2
{
    union
    {
        struct
        {
            float X;
            float Y;
        };
        float data[2];
    };


     
    inline Vector2();
    inline Vector2(float data[]);
    inline Vector2(float value);
    inline Vector2(float x, float y);


     
    static inline Vector2 Zero();
    
    static inline Vector2 Right();
    static inline Vector2 Left();
    static inline Vector2 Up();
    static inline Vector2 Down();


     
    static inline float Angle(Vector2 a, Vector2 b);

     
    

     
    static inline float Component(Vector2 a, Vector2 b);

     
    static inline float Distance(Vector2 a, Vector2 b);

     
    static inline float Dot(Vector2 lhs, Vector2 rhs);

     
    

     
    static inline Vector2 Lerp(Vector2 a, Vector2 b, float t);

     
    static inline Vector2 LerpUnclamped(Vector2 a, Vector2 b, float t);

     
    static inline float Magnitude(Vector2 v);

     
    static inline Vector2 Max(Vector2 a, Vector2 b);

     
    static inline Vector2 Min(Vector2 a, Vector2 b);

     
    

     
    static inline Vector2 Normalized(Vector2 v);

     
    

     
    static inline Vector2 Project(Vector2 a, Vector2 b);

     
    

     
    static inline Vector2 Reject(Vector2 a, Vector2 b);

     
    

     
    static inline Vector2 Scale(Vector2 a, Vector2 b);

     
    

     
    static inline Vector2 SlerpUnclamped(Vector2 a, Vector2 b, float t);

     
    static inline float SqrMagnitude(Vector2 v);

     


 
    inline struct Vector2& operator+=(const float rhs);
    inline struct Vector2& operator-=(const float rhs);
    inline struct Vector2& operator*=(const float rhs);
    inline struct Vector2& operator/=(const float rhs);
    inline struct Vector2& operator+=(const Vector2 rhs);
    inline struct Vector2& operator-=(const Vector2 rhs);
};

inline Vector2 operator-(Vector2 rhs);
inline Vector2 operator+(Vector2 lhs, const float rhs);
inline Vector2 operator-(Vector2 lhs, const float rhs);
inline Vector2 operator*(Vector2 lhs, const float rhs);
inline Vector2 operator/(Vector2 lhs, const float rhs);
inline Vector2 operator+(const float lhs, Vector2 rhs);
inline Vector2 operator-(const float lhs, Vector2 rhs);
inline Vector2 operator*(const float lhs, Vector2 rhs);
inline Vector2 operator/(const float lhs, Vector2 rhs);
inline Vector2 operator+(Vector2 lhs, const Vector2 rhs);
inline Vector2 operator-(Vector2 lhs, const Vector2 rhs);
inline bool operator==(const Vector2 lhs, const Vector2 rhs);
inline bool operator!=(const Vector2 lhs, const Vector2 rhs);


 

Vector2::Vector2() : X(0.f), Y(0.f) {}
Vector2::Vector2(float data[]) : X(data ? data[0] : 0.f), Y(data ? data[1] : 0.f) {}
Vector2::Vector2(float value) : X(std::isfinite(value) ? value : 0.f), Y(std::isfinite(value) ? value : 0.f) {}
Vector2::Vector2(float x, float y) : X(std::isfinite(x) ? x : 0.f), Y(std::isfinite(y) ? y : 0.f) {}


Vector2 Vector2::Zero() { return Vector2(0.f, 0.f); }

Vector2 Vector2::Right() { return Vector2(1.f, 0.f); }
Vector2 Vector2::Left() { return Vector2(-1.f, 0.f); }
Vector2 Vector2::Up() { return Vector2(0.f, 1.f); }
Vector2 Vector2::Down() { return Vector2(0.f, -1.f); }


float Vector2::Angle(Vector2 a, Vector2 b)
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


float Vector2::Component(Vector2 a, Vector2 b)
{
    float magB = Magnitude(b);
    if (!std::isfinite(magB) || magB <= 1e-8f)
        return 0.f;
    float res = Dot(a, b) / magB;
    return std::isfinite(res) ? res : 0.f;
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
    return Vector2::Magnitude(a - b);
}

float Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
    float res = lhs.X * rhs.X + lhs.Y * rhs.Y;
    return std::isfinite(res) ? res : 0.f;
}


Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
    if (!std::isfinite(t)) return a;
    if (t < 0.f) return a;
    else if (t > 1.f) return b;
    return LerpUnclamped(a, b, t);
}

Vector2 Vector2::LerpUnclamped(Vector2 a, Vector2 b, float t)
{
    if (!std::isfinite(t)) return a;
    return (b - a) * t + a;
}

float Vector2::Magnitude(Vector2 v)
{
    float sqr = SqrMagnitude(v);
    if (!std::isfinite(sqr) || sqr <= 0.f)
        return 0.f;
    float m = sqrtf(sqr);
    return std::isfinite(m) ? m : 0.f;
}

Vector2 Vector2::Max(Vector2 a, Vector2 b)
{
    float x = a.X > b.X ? a.X : b.X;
    float y = a.Y > b.Y ? a.Y : b.Y;
    return Vector2(x, y);
}

Vector2 Vector2::Min(Vector2 a, Vector2 b)
{
    float x = a.X > b.X ? b.X : a.X;
    float y = a.Y > b.Y ? b.Y : a.Y;
    return Vector2(x, y);
}


Vector2 Vector2::Normalized(Vector2 v)
{
    float mag = Magnitude(v);
    if (!std::isfinite(mag) || mag <= 1e-8f)
        return Vector2::Zero();
    return v / mag;
}


Vector2 Vector2::Project(Vector2 a, Vector2 b)
{
    float sqrM = SqrMagnitude(b);
    if (!std::isfinite(sqrM) || sqrM <= 1e-8f)
        return Vector2::Zero();
    float scale = Dot(a, b) / sqrM;
    return std::isfinite(scale) ? (b * scale) : Vector2::Zero();
}


Vector2 Vector2::Reject(Vector2 a, Vector2 b)
{
    return a - Project(a, b);
}


Vector2 Vector2::Scale(Vector2 a, Vector2 b)
{
    return Vector2(a.X * b.X, a.Y * b.Y);
}


Vector2 Vector2::SlerpUnclamped(Vector2 a, Vector2 b, float t)
{
    if (!std::isfinite(t))
        return a;
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    if (magA <= 1e-8f && magB <= 1e-8f)
        return Vector2::Zero();
    if (magA <= 1e-8f)
        return LerpUnclamped(Vector2::Zero(), b, t);
    if (magB <= 1e-8f)
        return LerpUnclamped(a, Vector2::Zero(), t);

    Vector2 dirA = a / magA;
    Vector2 dirB = b / magB;
    float dot = Dot(dirA, dirB);
    dot = fmaxf(dot, -1.0f);
    dot = fminf(dot, 1.0f);
    float theta = acosf(dot) * t;
    Vector2 relativeVec = Normalized(dirB - dirA * dot);
    Vector2 newVec = dirA * cosf(theta) + relativeVec * sinf(theta);
    float interpMag = magA + (magB - magA) * t;
    return newVec * interpMag;
}

float Vector2::SqrMagnitude(Vector2 v)
{
    float res = v.X * v.X + v.Y * v.Y;
    return std::isfinite(res) ? res : 0.f;
}


struct Vector2& Vector2::operator+=(const float rhs)
{
    if (!std::isfinite(rhs)) return *this;
    X += rhs;
    Y += rhs;
    return *this;
}

struct Vector2& Vector2::operator-=(const float rhs)
{
    if (!std::isfinite(rhs)) return *this;
    X -= rhs;
    Y -= rhs;
    return *this;
}

struct Vector2& Vector2::operator*=(const float rhs)
{
    if (!std::isfinite(rhs)) {
        X = 0.f;
        Y = 0.f;
        return *this;
    }
    X *= rhs;
    Y *= rhs;
    return *this;
}

struct Vector2& Vector2::operator/=(const float rhs)
{
    if (!std::isfinite(rhs) || fabsf(rhs) <= 1e-8f) {
        X = 0.f;
        Y = 0.f;
        return *this;
    }
    X /= rhs;
    Y /= rhs;
    return *this;
}

struct Vector2& Vector2::operator+=(const Vector2 rhs)
{
    if (std::isfinite(rhs.X)) X += rhs.X;
    if (std::isfinite(rhs.Y)) Y += rhs.Y;
    return *this;
}

struct Vector2& Vector2::operator-=(const Vector2 rhs)
{
    if (std::isfinite(rhs.X)) X -= rhs.X;
    if (std::isfinite(rhs.Y)) Y -= rhs.Y;
    return *this;
}

Vector2 operator-(Vector2 rhs) { return rhs * -1.f; }
Vector2 operator+(Vector2 lhs, const float rhs) { return lhs += rhs; }
Vector2 operator-(Vector2 lhs, const float rhs) { return lhs -= rhs; }
Vector2 operator*(Vector2 lhs, const float rhs) { return lhs *= rhs; }
Vector2 operator/(Vector2 lhs, const float rhs) { return lhs /= rhs; }
Vector2 operator+(const float lhs, Vector2 rhs) { return rhs += lhs; }
Vector2 operator-(const float lhs, Vector2 rhs) { return Vector2(lhs - rhs.X, lhs - rhs.Y); }
Vector2 operator*(const float lhs, Vector2 rhs) { return rhs *= lhs; }
Vector2 operator/(const float lhs, Vector2 rhs) {
    float x = (std::isfinite(rhs.X) && fabsf(rhs.X) > 1e-8f) ? (lhs / rhs.X) : 0.f;
    float y = (std::isfinite(rhs.Y) && fabsf(rhs.Y) > 1e-8f) ? (lhs / rhs.Y) : 0.f;
    return Vector2(x, y);
}
Vector2 operator+(Vector2 lhs, const Vector2 rhs) { return lhs += rhs; }
Vector2 operator-(Vector2 lhs, const Vector2 rhs) { return lhs -= rhs; }

bool operator==(const Vector2 lhs, const Vector2 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

bool operator!=(const Vector2 lhs, const Vector2 rhs)
{
    return !(lhs == rhs);
}
