#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H

#include "vec3.h"
#include <iostream>

// write color of pixel to output stream
void write_color(std::ostream &out, color pixel_color){
    out << static_cast<int>(255.99*pixel_color.x()) << ' '
    << static_cast<int>(255.999 * pixel_color.y()) << ' '
    << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif //RAY_TRACER_COLOR_H
