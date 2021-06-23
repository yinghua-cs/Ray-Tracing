//  color.h -- output color to standard output stream
//  - 3.3 Color Utility Functions, Ray Tracing in One Weekend, Version 3.2.3, 2020-12-07, by Peter Shirley.
// 
//  Created by Yinghua Han on 04/25/2021.
//  Copyright © 2021 Yinghua Han. All rights reserved.

# ifndef COLOR_H
# define COLOR_H

# include "vec3.h"

# include <iostream>

void write_color(std::ostream & out, color pixel_color)
{
	// Write the translated [0, 255] value of each color component.
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

# endif