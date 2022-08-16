#include "ray.h"
#include "color.h"
#include <iostream>

float HitSphere (const point3& center, float radius, const ray& r) {
    vec3 oc = r.origin () - center;
    float a = dot (r.direction (), r.direction ());
    float b = 2.0 * dot (oc, r.direction ());
    float c = dot (oc, oc) - (radius * radius);
    float discriminant = b * b - (4 * a * c);
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt (discriminant)) / (2.0 * a);
    }
}

color RayColor (const ray& r) {
    float t = HitSphere (point3 (0, 0, -1), 0.5, r);
    if (t > 0.0) {
        vec3 n = unitVector (r.at (t) - vec3 (0, 0, 1));
        return 0.5 * color (n.x () + 1, n.y () + 1, n.z () + 1);
    }
    vec3 unitDirection = unitVector (r.direction ());
    t = 0.5 * (unitDirection.y () + 1.0);
    return (1.0 - t) * color (1.0, 1.0, 1.0) + t * color (0.5, 0.7, 1.0);
}

int main () {
    //Define image size
    const float aspectRatio = 16.0 / 9.0;
    const int iWidth = 1280;
    const int iHeight = int(iWidth / aspectRatio);

    //Camera
    float viewportHeight = 2.0;
    float viewportWidth = aspectRatio * viewportHeight;
    //Focal length = distance between projection plane and projection point
    float focalLength = 0.05;
    point3 origin = point3 (0, 0, 0);
    vec3 horizontal = vec3 (viewportWidth, 0, 0);
    vec3 vertical = vec3 (0, viewportHeight, 0);
    vec3 lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3 (0, 0, focalLength);

    //Renderer
    std::cout << "P3\n" << iWidth << ' ' << iHeight << "\n255\n";
    //Loop through the pixels in rows left to right and from top to bottom
    //RGB channels are 0.0f - 1.0f
    for (int i = iHeight - 1; i >= 0; i--) {
        //Tracking progress
        std::cerr << "\rLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < iWidth; j++) {
            float u = float (j) / (iWidth - 1);
            float v = float (i) / (iHeight - 1);
            ray r = ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
            color pixelColor = RayColor (r);
            WriteColor (std::cout, pixelColor);
        }
    }

    //Color issue

    std::cerr << "\nDone.\n";
}