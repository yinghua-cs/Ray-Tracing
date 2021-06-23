//  ray.h -- ray :  P(t) = A + tb.
//  - 4.1 The Ray Class, Ray Tracing in One Weekend, Version 3.2.3, 2020-12-07, by Peter Shirley.
// 
//  Created by Yinghua Han on 05/26/2021.
//  Copyright © 2021 Yinghua Han. All rights reserved.

# ifndef RAY_H
# define RAY_H

# include "vec3.h"

class ray 
{
	public:
		ray() {}
		ray(const point3 & origin, const vec3 & direction)
			: orig(origin), dir(direction)
			{}

		point3 origin() const { return orig; }
		vec3 direction() const { return dir; }

		point3 at(double t) const 
		{
			return orig + t * dir;
		}
	public:
		point3 orig;
		vec3 dir;

};

# endif