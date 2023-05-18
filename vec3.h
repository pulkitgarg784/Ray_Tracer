#ifndef RAY_TRACER_VEC3_H
#define RAY_TRACER_VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3{
public:
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // return x,y,z
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // negation operator
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    //indexing operators
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    // addition and multiplication operators
    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // division
    vec3& operator/=(const double t) {
        return *this *= 1/t; // just multiply by inverse
    }

    // length of vectors
    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
public:
    double e[3];
};

using point3 = vec3;
using color3 = vec3;

#endif //RAY_TRACER_VEC3_H
