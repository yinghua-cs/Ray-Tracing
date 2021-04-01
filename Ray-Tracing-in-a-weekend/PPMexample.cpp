# include <iostream>

int main()
{
	int nx = 200;
	int ny = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)	// 99 ~ 0 
	{
		for (int i = 0; i < nx; i++)	// 0 ~199
		{
			float r = float(i) / float(nx);	// column : 0 % ~ 100 %; increase "red" left -> right 
			float g = float(j) / float(ny);	// row : 100 % ~ 0 %; decrease "green" top -> bottom
			float b = 0.2;
			int ir = int(255.99 * r);	
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);
			std::cout << ir << " " << ig << " " << ib << "\n";

		}
	}

	return 0;
}