#define COLOR_H

#include "vec3.h"
#include <iostream>

void WriteColor (std::ostream &out, color pixelColor) {
    //Convert the pixel to a 0-255 format
    out << static_cast<int>(255.999 * pixelColor.x ()) << ' ' << static_cast<int>(255.999 * pixelColor.y ()) << ' ' << static_cast<int>(255.999 * pixelColor.z ()) << '\n';
}