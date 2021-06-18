//  main.cpp -- output an PPM image.
//  - 2.1 The PPM Image Format, Ray Tracing in One Weekend, Version 3.2.3, 2020-12-07, by Peter Shirley.
// 
//  Created by Yinghua Han on 03/28/2021.
//  Copyright © 2021 Yinghua Han. All rights reserved.

# include "color.h"
# include "vec3.h"

# include <iostream>

int main()
{
	// Image

	const int image_width = 256;
	const int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = image_height - 1; j >= 0; --j)	// 255 ~ 0 
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		// overwrite the same line with \r. 
		// \r will move the cursor at the start of the line.
		
		for (int i = 0; i < image_width; ++i)	// 0 ~ 255
		{
			// // change R, G from [0, 255] to [0, 1]
			// auto r = double(i) / (image_width - 1);		// column : 0 % ~ 100 %; increase "red" left -> right 
			// auto g = double(j) / (image_height - 1);	// row : 100 % ~ 0 %; decrease "green" top -> bottom
			// auto b = 0.25;

			// int ir = static_cast<int>(255.99 * r);		// why 255.99, not 255?
			// int ig = static_cast<int>(255.99 * g);		// is it better to use "static_cast<int>" than just "int"?
			// int ib = static_cast<int>(255.99 * b);

			// std::cout << ir << ' ' << ig << ' ' << ib << '\n';

			color pixel_color(double(i) / (image_width-1), double(j) / (image_height - 1), 0.25);
			write_color(std::cout, pixel_color);

		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}