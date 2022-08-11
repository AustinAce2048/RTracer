#include <iostream>
#include "color.h"

int main () {
    //Define image size
    const int iWidth = 1280;
    const int iHeight = 720;

    //Renderer
    std::cout << "P3\n" << iWidth << ' ' << iHeight << "\n255\n";
    //Loop through the pixels in rows left to right and from top to bottom
    //RGB channels are 0.0f - 1.0f
    for (int i = iHeight - 1; i >= 0; i--) {
        //Tracking progress
        std::cerr << "\rLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < iWidth; j++) {
            color pixelColor (float (j) / (iWidth - 1), float (i) / (iHeight - 1), 0.25);
            WriteColor (std::cout, pixelColor);
        }
    }

    //Just black and white right now, might be a color issue

    std::cerr << "\nDone.\n";
}