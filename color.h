#pragma once
#include "vec3.h"
#include <iostream>

void WriteColor (std::ostream &out, color pixelColor) {
    //Convert the pixel to a 0-255 format
    out << int(255.999 * pixelColor.x ()) << ' ' << int(255.999 * pixelColor.y ()) << ' ' << int(255.999 * pixelColor.z ()) << '\n';
}