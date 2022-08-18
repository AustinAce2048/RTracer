#include "utils.h"
#include "color.h"
#include "hittableList.h"
#include "sphere.h"
#include "camera.h"
#include <iostream>
#include <memory>

color RayColor (const ray& r, const HittableList& world) {
    HitRecord rec;
    if (world.hit (r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color (1, 1, 1));
    }
    vec3 unitDirection = unitVector (r.direction ());
    float t = 0.5 * (unitDirection.y () + 1.0);
    return (1.0 - t) * color (1.0, 1.0, 1.0) + t * color (0.5, 0.7, 1.0);
}

int main () {
    //Define image size
    const float aspectRatio = 16.0 / 9.0;
    const int iWidth = 1280;
    const int iHeight = int(iWidth / aspectRatio);
    const int samplesPerPixel = 10;

    HittableList world;
    world.add (make_shared<Sphere>(point3 (0, 0, 1), 0.5));
    world.add (make_shared<Sphere>(point3 (0, -100.5, 1), 100));

    //Camera
    Camera cam;

    //Renderer
    std::cout << "P3\n" << iWidth << ' ' << iHeight << "\n255\n";
    //Loop through the pixels in rows left to right and from top to bottom
    //RGB channels are 0.0f - 1.0f
    for (int i = iHeight - 1; i >= 0; i--) {
        //Tracking progress
        std::cerr << "\rLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < iWidth; j++) {
            color pixelColor (0,0,0);
            for (int s = 0; s < samplesPerPixel; s++) {
                float u = (j + RandomFloat ()) / (iWidth - 1);
                float v = (i + RandomFloat ()) / (iHeight - 1);
                ray r = cam.GetRay (u, v);
                pixelColor += RayColor (r, world);
            }
            WriteColor (std::cout, pixelColor, samplesPerPixel);
        }
    }
    
    std::cerr << "\nFinished\n";
}