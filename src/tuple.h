#ifndef TUPLE_H
#define TUPLE_H

#include <math.h>

#define EPSILON 0.00001

class Tuple
{
public:
    float x;

    float y;

    float z;

    float w;

    Tuple() : x(0), y(0), z(0), w(0) {}

    Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    static Tuple point(float x, float y, float z)
    {
        return Tuple(x, y, z, 1.0);
    }

    static Tuple color(float r, float g, float b)
    {
        return Tuple(r, g, b, 0.0);
    }

    static Tuple vector(float x, float y, float z)
    {
        return Tuple(x, y, z, 0.0);
    }

    Tuple operator+(const Tuple &t) const
    {
        return Tuple(x + t.x, y + t.y, z + t.z, w + t.w);
    }

    Tuple operator-(const Tuple &t) const
    {
        return Tuple(x - t.x, y - t.y, z - t.z, w - t.w);
    }

    Tuple operator-() const
    {
        return Tuple(-x, -y, -z, -w);
    }

    Tuple operator*(float scalar) const
    {
        return Tuple(
            x * scalar,
            y * scalar,
            z * scalar,
            w * scalar);
    }

    Tuple hadamard(const Tuple &t) const
    {
        return Tuple(
            x * t.x,
            y * t.y,
            z * t.z,
            w * t.w);
    }

    Tuple operator/(float scalar) const
    {
        return Tuple(
            x / scalar,
            y / scalar,
            z / scalar,
            w / scalar);
    }

    float dot(const Tuple &t) const
    {
        return x * t.x + y * t.y + z * t.z + w * t.w;
    }

    Tuple cross(const Tuple &t) const
    {
        return Tuple(
            y * t.z - z * t.y,
            z * t.x - x * t.z,
            x * t.y - y * t.x, 0);
    }

    float mag() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    Tuple norm() const
    {
        float m = mag();
        return Tuple(x / m, y / m, z / m, w / m);
    }

    bool operator==(const Tuple &t) const
    {
        return fabs(x - t.x) < EPSILON &&
               fabs(y - t.y) < EPSILON &&
               fabs(z - t.z) < EPSILON &&
               fabs(w - t.w) < EPSILON;
    }

    bool operator!=(const Tuple &t) const
    {
        return !(*this == t);
    }

    bool is_point() const
    {
        return w == 1.0;
    }

    bool is_vector() const
    {
        return w == 0.0;
    }
};

#endif