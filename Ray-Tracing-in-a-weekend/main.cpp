//  main.cpp -- output an PPM image.
//  - 2.1 The PPM Image Format, Ray Tracing in One Weekend, Version 3.2.3, 12/07/2020, by Peter Shirley.
// 	- 3.3 Color Utility Function, ... (Updated with vec3, color, 5/24/2021)
// 	- 4.2 Sending Rays Into the Scene, ... (Updated with ray, 06/23/2021) 
//  Created by Yinghua Han on 03/28/2021.
//  Copyright © 2021 Yinghua Han. All rights reserved.

# include "color.h"
# include "ray.h"
# include "vec3.h"

# include <iostream>

color ray_color(const ray& r)
{
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);			// -1 <= y <= 1, so 0 <= t <= 1
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
	
}

int main()
{
	// Image

	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// Camera

	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	auto origin = point3(0, 0, 0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);	// viewport's lower left corner

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	for (int j = image_height - 1; j >= 0; --j)	// (image_height - 1) ~ 0
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		// overwrite the same line with \r. 
		// \r will move the cursor at the start of the line.
		
		for (int i = 0; i < image_width; ++i)	// 0 ~ (image_width - 1)
		{
			auto u = double (i) / (image_width - 1);
			auto v = double (j) / (image_height - 1);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);

		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}