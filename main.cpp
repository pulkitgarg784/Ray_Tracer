#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>

bool hit_sphere(const point3& center, double radius, const ray& r){
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant>0);
}

color ray_color(const ray& r){
    // add a red sphere in the center
    if (hit_sphere(point3(0,0,-1), 0.5, r)){
        return color(1,0,0);
    }
    vec3 unit_dir = unit_vector(r.direction());
    auto t = 0.5*(unit_dir.y() + 1);
    // lerp between white and blue for sky
    return (1.0-t)* color(1.0,1.0,1.0) + t*color(0.5,0.7,1);
}

int main(){
    // Set initial consts
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int img_width = 1080;
    const int img_height = static_cast<int>(img_width / aspect_ratio);

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // Render the output
    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";
    for (int j = img_height -1; j >= 0 ; --j) {
        std::cerr << "\rProgress: " << (img_height - j) * 100 /img_height << '%' << std::flush;
        for (int i = 0; i < img_width; ++i) {
            auto u = double(i) / (img_width-1);
            auto v = double(j) / (img_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}