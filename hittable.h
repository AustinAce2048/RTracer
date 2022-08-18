#pragma once
#include "ray.h"

struct HitRecord {
    point3 p;
    vec3 normal;
    float t;
    bool frontFace;

    inline void SetFaceNormal (const ray& r, const vec3& outwardNormal) {
        frontFace = dot (r.direction (), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable {
    public:
        virtual bool hit (const ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
};