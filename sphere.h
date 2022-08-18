#pragma once
#include "hittable.h"
#include "vec3.h"

class Sphere : public Hittable {
    public:
        Sphere () {}
        Sphere (point3 cen, float r) : center (cen), radius (r) {};

        virtual bool hit (const ray& r, float tMin, float tMax, HitRecord& rec) const override;

    public:
        point3 center;
        float radius;
};

bool Sphere::hit (const ray& r, float tMin, float tMax, HitRecord& rec) const {
    vec3 oc = r.origin () - center;
    auto a = r.direction ().LengthSquared ();
    auto half_b = dot (oc, r.direction ());
    auto c = oc.LengthSquared () - radius*radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) {
        return false;
    }
    auto sqrtd = sqrt (discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-half_b + sqrtd) / a;
        if (root < tMin || tMax < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at (rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.SetFaceNormal (r, outward_normal);

    return true;
};