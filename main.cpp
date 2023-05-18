#include <iostream>

int main(){

    // Set initial consts
    const int img_width = 256;
    const int img_height = 256;

    // Render the output
    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";
    for (int j = img_height -1; j >= 0 ; --j) {
        std::cerr << "\rProgress: " << (img_height - j) * 100 /img_height << '%' << std::flush;
        for (int i = 0; i < img_width; ++i) {
            auto r = double(i) / (img_width - 1);
            auto g = double(j) / (img_height - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cerr << "\nDone.\n";
}