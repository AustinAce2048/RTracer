#pragma once
#include "utils.h"
#include <iostream>

void WriteColor (std::ostream &out, color pixelColor, int samplesPerPixel) {
    auto r = pixelColor.x ();
    auto g = pixelColor.y ();
    auto b = pixelColor.z ();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samplesPerPixel;
    r = sqrt (scale * r);
    g = sqrt (scale * g);
    b = sqrt (scale * b);

    // Write the translated [0,255] value of each color component.
    out << int (256 * clamp(r, 0.0, 0.999)) << ' '
        << int (256 * clamp(g, 0.0, 0.999)) << ' '
        << int (256 * clamp(b, 0.0, 0.999)) << '\n';
}