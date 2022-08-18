#pragma once
#include <cmath>
#include <limits>
#include <memory.h>
#include <memory>
#include <cstdlib>
#include <stdlib.h>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const float infinity = std::numeric_limits<float>::infinity ();
const float pi = 3.1415926535897932385;

inline float DegreesToRadians (float degrees) {
    return degrees * pi / 180;
}

inline float RandomFloat () {
    return rand () / (RAND_MAX + 1.0);
}

inline float RandomFloat (float min, float max) {
    return min + (max - min) * RandomFloat ();
}

inline float clamp (float x, float min, float max) {
    if (x < min) {
        return min;
    }
    if (x > max) {
        return max;
    }
    return x;
}

#include "ray.h"
#include "vec3.h"