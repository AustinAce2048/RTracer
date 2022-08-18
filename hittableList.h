#pragma once
#include "hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable {
    public:
        HittableList () {}
        HittableList (shared_ptr<Hittable> object) {add (object);}

        void clear () {objects.clear ();}
        void add (shared_ptr<Hittable> object) {objects.push_back (object);}

        virtual bool hit (const ray& r, float tMin, float tMax, HitRecord& rec) const override;

    public:
        std::vector<shared_ptr<Hittable>> objects;
};

bool HittableList::hit (const ray& r, float tMin, float tMax, HitRecord& rec) const {
    HitRecord tempRec;
    bool hitAnything = false;
    float closestSoFar = tMax;

    for (const shared_ptr<Hittable>& object : objects) {
        if (object -> hit (r, tMin, closestSoFar, tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }

    return hitAnything;
};