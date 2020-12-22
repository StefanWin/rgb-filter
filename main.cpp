#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "pixel.h"

// https://stackoverflow.com/a/874160
static bool ends_with(std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length())
    {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> valid_filters = {"grayscale", "invert", "remove-red", "remove-green", "remove_blue"};

    std::string file_name = "../img.jpg";
    std::string filter = "grayscale";
    std::string output_file_name = "./output.jpg";
    if (argc > 3)
    {
        file_name = argv[1];
        filter = argv[2];
        output_file_name = argv[3];
    }
    else
    {
        std::cout << "not enough arguments provided" << std::endl;
        std::cout << "example usage : rgb-filter <input> <filter> <output>" << std::endl;
        return -1;
    }

    if (!ends_with(file_name, ".jpg") || !ends_with(output_file_name, ".jpg"))
    {
        std::cout << "input/output must be jpg!" << std::endl;
        return -1;
    }

    if (std::find(valid_filters.begin(), valid_filters.end(), filter) == valid_filters.end())
    {
        printf("invalid filter: %s!\n", filter.c_str());
        return -1;
    }

    printf("Input: %s -> Filter: %s -> Output: %s\n", file_name.c_str(), filter.c_str(), output_file_name.c_str());

    int width, height, channels;
    unsigned char *data = stbi_load(file_name.c_str(), &width, &height, &channels, STBI_rgb);
    if (data == nullptr)
    {
        throw std::runtime_error("failed to load image!");
    }
    printf("Images Metadata : %dx%d, %d channels (RGB)\n", width, height, channels);
    int length = width * height * channels;
    unsigned char *copy = (unsigned char *)malloc(length);

    auto start = std::chrono::high_resolution_clock::now();

    RGB *pixel = new RGB;
    for (uint64_t i = 0; i < length; i += 3)
    {
        pixel->r = (uint8_t)data[i];
        pixel->g = (uint8_t)data[i + 1];
        pixel->b = (uint8_t)data[i + 2];

        if (filter == "grayscale")
        {
            rgb_to_grayscale_simple(pixel);
        }
        else if (filter == "invert")
        {
            invert_color(pixel);
        }
        else if (filter == "remove-red")
        {
            remove_red(pixel);
        }
        else if (filter == "remove-green")
        {
            remove_green(pixel);
        }
        else if (filter == "remove-blue")
        {
            remove_blue(pixel);
        }

        copy[i] = (unsigned char)pixel->r;
        copy[i + 1] = (unsigned char)pixel->g;
        copy[i + 2] = (unsigned char)pixel->b;
    }
    delete pixel;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    printf("Processing took %ld ms!\n", duration);
    if (stbi_write_jpg("../test.jpg", width, height, channels, copy, 100) != 1)
    {
        throw std::runtime_error("failed to save image");
    }

    return 0;
}
