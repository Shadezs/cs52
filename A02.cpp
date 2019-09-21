//
// Name: Carlos Davila
// SSID: 1561932
// Assignment #: 2
// submission Date: 9/22/19
//
// Description of program: the program will allow a user to select
// a shape that will be printed out to the standard output.
//

#include <iostream>
#include <string>
#define WIDTH  30
#define HEIGHT 30

enum Shapes { FILLED ,HALF_RIGHT,LOWER_LEFT,BANDED, SQUARE, CHECKER, X };
enum Colors { BLACK, WHITE };
struct Pixel {
	Colors color;
};
Pixel p[WIDTH*HEIGHT];
void CreateShape(Pixel p[], int nPixels, Shapes shape);
void Draw(Pixel p[], int nPixels);
std::string chose , dummy;

int main()
{
	int nPixels = WIDTH*HEIGHT;
	std::cout << "Please pick a shape to draw : filled , half right , baneded , square, checker,lower_left, or a X?. Enter q to exit.\n";
	std::cin >> chose;

	if (chose == "filled")

	{
		CreateShape(p, nPixels, Shapes::FILLED);
		Draw(p, nPixels);
	}
	else if (chose == "square")
	{
		CreateShape(p, nPixels, Shapes::SQUARE);
		Draw(p, nPixels);
	}
	else if (chose == "checker")
	{
		CreateShape(p, nPixels, Shapes::CHECKER);
		Draw(p, nPixels);
	}
	else if (chose == "X" || chose == "x")
	{
		CreateShape(p, nPixels, Shapes::X);
		Draw(p, nPixels);
	}
	else if(chose == "half_right")
	{
		CreateShape(p, nPixels, Shapes::HALF_RIGHT);
		Draw(p, nPixels);
	
	}
	else if (chose == "lower_left") 
	{
		CreateShape(p, nPixels, Shapes::LOWER_LEFT);
		Draw(p, nPixels);

	}
	else if( chose == "baneded")
	{
		CreateShape(p, nPixels, Shapes::BANDED);
		Draw(p, nPixels);

	}
	else if (chose == "q")
	{
		system("pause");// used in visual studio
		return 0;
	}
	else
	{
		std::cout << "invalid option\n";
		main();
	}


	return 0;
} //main

void CreateShape(Pixel p[], int nPixels, Shapes shape)
{
	int r = 0;
	switch (shape)
	{
	case FILLED:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (i >= 0 || j >= 0 )
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				
			}
		}
		break;

	case HALF_RIGHT: ///	
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (j >= WIDTH/2 )
				{
					p[r].color = Colors::WHITE;
					r++;

				}
				else
				{
					p[r].color = Colors::BLACK;
					r++;
				}
			} // for j
		} //for i
		break;
	case SQUARE:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (i == 0 || j == 0 || i == WIDTH-1 || j == HEIGHT-1)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else
				{
					p[r].color = Colors::BLACK;
					r++;
				}
			}
		}
		break;
	case BANDED:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (j % 2 == 0 || i%2 ==1)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else
				{
					p[r].color = Colors::BLACK;
				}
				
			}
		}
		break;
	case LOWER_LEFT:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (j==0 && i >=1)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				if(i%2==1 || j%2==0)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else
				{
					p[r].color = Colors::BLACK;
				}
			}
			
		}
		break;
	case CHECKER:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (i%2 == 0 && j%2 ==0 )
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else if (i % 2 == 1 && j % 2 == 1)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else
				{
					p[r].color = Colors::BLACK;
					r++;
				}
			}
		}
		break;
	case X:
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (i == j || j == (HEIGHT ) - i - 1)
				{
					p[r].color = Colors::WHITE;
					r++;
				}
				else
				{
					p[r].color = Colors::BLACK;
					r++;
				}
			}
		}
		break;
	default:
		std::cout << "Check shape switch";
		break;
	}
}

void Draw(Pixel p[], int nPixels)
{
	int r = 0;
	for (int i = 0; i < WIDTH ; i++)
	{
		for (int j = 0; j < HEIGHT ; j++)
		{

			if (p[r].color == Colors::WHITE)
			{
				std::cout << "|||";
			}
			else if (p[r].color == Colors::BLACK)
			{
				std::cout << "   ";

			}
			r++;
		}
		std::cout << "\n";
	}
	main();
}
