#include <iostream>

using namespace std;


void elbow_making_animator(int board[][8], int row, int col, int turn1, int turn2)
{

	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;

	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			bool flag = 0;

			if (turn1 == 1 || turn2 == 1)
			{
				if (i == row - 1 && j == col || i == row - 2 && j == col)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			if (turn1 == 2 || turn2 == 2)
			{
				if (i == row && j == col + 1 || i == row && j == col + 2)
				{
					flag = 1;

					x1 += 90;
					x2 += 90;
				}
			}
			if (turn1 == 3 || turn2 == 3)
			{
				if (i == row && j == col - 1 || i == row && j == col - 2)
				{
					flag = 1;

					x1 += 90;
					x2 += 90;
				}
			}
			if (turn1 == 4 || turn2 == 4)
			{
				if (i == row + 1 && j == col || i == row + 2 && j == col)
				{
					flag = 1;

					x1 += 90;
					x2 += 90;
				}
			}
			if (!flag)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
					red = 0;
					green = 139;
					blue = 139;
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

					myRects(x1, y1, x2, y2, red, green, blue);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 21)
				{
					red = 155;
					green = 28;
					blue = 49;
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

					myRects(x1, y1, x2, y2, red, green, blue);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 22)
				{
					red = 120;
					green = 81;
					blue = 169;
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

					myRects(x1, y1, x2, y2, red, green, blue);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 23)
				{
					red = 218;
					green = 124;
					blue = 48;
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

					myRects(x1, y1, x2, y2, red, green, blue);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 24)
				{
					red = 19;
					green = 98;
					blue = 7;
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

					myRects(x1, y1, x2, y2, red, green, blue);
					x1 += 90;
					x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
			}
		}
		y1 += 90;
		y2 += 90;
	}

	Sleep(1000);



}
void T_making_animator(int board[][8], int row, int col, int position)
{

	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;

	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			bool flag = 0;

			if (position == 1)
			{
				if (i == row && j == col - 1 || i == row && j == col + 1)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
				if (j == col && i == row + 1|| j == col && i == row + 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			else if (position == 2)
			{
				if (i == row && j == col - 1 || i == row && j == col + 1)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
				if (j == col && i == row - 1 || j == col && i == row - 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			else if (position == 3)
			{
				if (i == row && j == col +1 || i == row && j == col + 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
				if (j == col && i == row - 1 || j == col && i == row +1)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			else if (position == 4)
			{
				if (i == row && j == col - 1 || i == row && j == col - 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
				if (j == col && i == row - 1 || j == col && i == row + 1)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			if (!flag)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
			}
		}
		y1 += 90;
		y2 += 90;
	}

	Sleep(1000);



}


void thunder_animator(int board[][8], int row, int col)
{
	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;

	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			if (i == row || j == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 1)
			{
				r = 57;
				g = 106;
				b = 117;
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 2)
			{
				r = 255;
				g = 0;
				b = 0;
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 3)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);



				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 4)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 5)
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 6)
			{
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
				myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 7)
			{
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


				myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

				myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
				myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 8)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 9)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1, y2, x2, y2, 19, 98, 7);
				myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
				myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
				myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}
		}
		y1 += 90;
		y2 += 90;
	}
	
	Sleep(1000);
	

}

void colanimator(int board[][8], int col, int row, bool flag)
{

	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);


	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;

	for (int i = 0; i < 8; ++i)
	{

		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			if (i == row && j == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i - 1 == row && j == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i - 2 == row && j == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i - 3 == row && j == col && flag == 1)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 1)
			{
				r = 57;
				g = 106;
				b = 117;
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 2)
			{
				r = 255;
				g = 0;
				b = 0;
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 3)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 4)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 5)
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 6)
			{
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
				myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 7)
			{
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


				myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

				myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
				myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 8)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 9)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1, y2, x2, y2, 19, 98, 7);
				myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
				myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
				myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}
		}
		y1 += 90;
		y2 += 90;
	}
	
	
	Sleep(1000);
	
}



void animator(int board[][8], int row, int col, bool flag)
{
	myRects(500, 120, 1650, 1200, 11, 11, 11);

	myRect(600, 120, 1375, 908, 0, 139, 139);



	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;
	for (int i = 0; i < 8; ++i)
	{

		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			if (i == row && j == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i == row && j - 1 == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i == row && j - 2 == col)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (i == row && j - 3 == col && flag == 1)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 1)
			{
				r = 57;
				g = 106;
				b = 117;
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 2)
			{
				r = 255;
				g = 0;
				b = 0;
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 3)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 4)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				//myLine(x1-5 , y2+5, x2+5, y2+5, 62, 150, 81);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 5)
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 6)
			{
				myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
				myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
				myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
				myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
				myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 7)
			{
				myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
				myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
				myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
				myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
				myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
				myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
				myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


				myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

				myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
				myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 8)
			{
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 9)
			{
				myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
				myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
				myLine(x1, y2, x2, y2, 19, 98, 7);
				myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
				myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
				myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


				x1 += 90;
				x2 += 90;
			}
			else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
			else
			{
				r = 0;
				g = 139;
				b = 139;
				myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
				x1 += 90;
				x2 += 90;
			}

		}
		y1 += 90;
		y2 += 90;
	}
	
	Sleep(1000);
	
}



void special_gem_explode_animator_col(int board[][8], int row, int col, int position)
{
	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	bool flag = 0;
	int red, green, blue;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;

	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			flag = 0;

			if ((i == row - 1 && j == col - 1) || (i == row + 1 && j == col + 1) || (i == row && j == col) || (i == row && j == col - 1) || (i == row && j == col + 1) || (i == row - 1 && j == col + 1) || (i == row - 1 && j == col) || (i == row + 1 && j == col - 1) || (i == row + 1 && j == col))
			{
				flag = 1;

				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 90;
				x2 += 90;
			}
			else if (position == 1)
			{
				if (i == row + 2 && j == col)
				{
					flag = 1;

					myRect(x1, y1, x2, y2, 0, 0, 0);
					x1 += 90;
					x2 += 90;
				}
			}
			else if (position == 3)
			{
				if (i == row - 2 && j == col)
				{
					flag = 1;

					myRect(x1, y1, x2, y2, 0, 0, 0);
					x1 += 90;
					x2 += 90;
				}
			}

			if (flag == 0)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
			}

		}
		y1 += 90;
		y2 += 90;
	}
	Sleep(1000);
}
void special_gem_explode_animator_row(int board[][8], int row, int col, int position, int case_of_equality) {


	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	bool flag = 0;
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;
	int red, green, blue;
	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			flag = 0;
			if (case_of_equality == 4)
			{
				if ((i == row - 1 && j == col - 1) || (i == row + 1 && j == col + 1) || (i == row && j == col) || (i == row && j == col - 1) || (i == row && j == col + 1) || (i == row - 1 && j == col + 1) || (i == row - 1 && j == col) || (i == row + 1 && j == col - 1) || (i == row + 1 && j == col))
				{
					flag = 1;

					myRect(x1, y1, x2, y2, 0, 0, 0);
					x1 += 90;
					x2 += 90;
				}
				else if (position == 1)
				{
					if (i == row && (j == col + 2 || j == col + 3))
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
				else if (position == 2)
				{
					if (i == row && j == col + 2)
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
				else if (position == 3)
				{
					if (i == row && j == col - 2)
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
				else if (position == 4)
				{
					if (i == row && (j == col - 2 || j == col - 3))
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
			}
			else if (case_of_equality == 3)
			{
				if ((i == row - 1 && j == col - 1) || (i == row + 1 && j == col + 1) || (i == row && j == col) || (i == row && j == col - 1) || (i == row && j == col + 1) || (i == row - 1 && j == col + 1) || (i == row - 1 && j == col) || (i == row + 1 && j == col - 1) || (i == row + 1 && j == col))
				{
					flag = 1;

					myRect(x1, y1, x2, y2, 0, 0, 0);
					x1 += 90;
					x2 += 90;
				}
				else if (position == 1)
				{
					if (i == row && j == col + 2)
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
				else if (position == 3)
				{
					if (i == row && j == col - 2)
					{
						flag = 1;

						myRect(x1, y1, x2, y2, 0, 0, 0);
						x1 += 90;
						x2 += 90;
					}
				}
			}
			if (flag == 0)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
			}

		}
		y1 += 90;
		y2 += 90;
	}

	Sleep(1000);
}

void special_animator_row(int board[][8],int row,int col,int position)
{

	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);


	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;
	int red, green, blue;
	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			bool flag = false;

			if (position == 2)
			{
				if (i == row && j == col - 1 || i == row && j == col + 1 || i == row && j == col + 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			if (position == 3)
			{
				if (i == row && j == col - 1 || i == row && j == col + 1 || i == row && j == col - 2)
				{
					flag = 1;

					x1 += 90;
					x2 += 90;
				}
			}
			if (flag == 0)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					//myRectL(x1-5, y1-5, x2+5, y2+5, 204, 190, 16, 5);



					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);

					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					//myRectL(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 218, 124, 48,5);
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					//myLine(x1-5 , y2+5, x2+5, y2+5, 62, 150, 81);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}

			}
		}
		y1 += 90;
		y2 += 90;
	}
	Sleep(1000);

}
void special_animator_col(int board[][8], int row, int col, int position)
{

	myRects(500, 120, 1650, 1200, 11, 11, 11);
	myRect(600, 120, 1375, 908, 0, 139, 139);

	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;
	int red, green, blue;
	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
		{
			bool flag = false;
			if (position == 2)
			{
				if (j == col && i == row - 1 || j == col && i == row + 1 || j == col && i == row + 2)
				{
					flag = 1;
					x1 += 90;
					x2 += 90;
				}
			}
			if (position == 3)
			{
				if (j == col && i == row - 1 || j == col && i == row + 1 || j == col && i == row - 2)
				{
					flag = 1;

					x1 += 90;
					x2 += 90;
				}
			}
			if (flag == 0)
			{
				if (board[i][j] == 1)
				{
					r = 57;
					g = 106;
					b = 117;
					//myRectL(x1-5, y1-5, x2+5, y2+5, 204, 190, 16, 5);



					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);

					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 6);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 6);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 6);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 2)
				{
					r = 255;
					g = 0;
					b = 0;
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 3)
				{
					//myRectL(x1 - 5, y1 - 5, x2 + 5, y2 + 5, 218, 124, 48,5);
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);

					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);



					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 4)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					//myLine(x1-5 , y2+5, x2+5, y2+5, 62, 150, 81);
					x1 += 90;
					x2 += 90;
				}

				
				else if (board[i][j] == 5)
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipseS(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 6)
				{
					myLineL(x1 + 22 - 4, y1 - 5, x1 - 3 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 5 + 28 - 4, y1 - 5, x1 + 20 + 28 - 4, y2 - 20 - 7, 155, 28, 49, 6);
					myLineL(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49, 7);
					myLineL(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49, 7);
					myLineL(x1 + 2, y2 + 3, x2 - 5, y2 + 2, 155, 28, 49, 8);
					myEllipseS(x1 - 2, y1, x2, y2 + 3, 155, 28, 49);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 7)
				{
					myLine(x1 + 5, y1 - 5, x2 - 5, y1 - 5, 120, 81, 169);
					myLine(x1 + 3, y1 - 5, x1 - 2, y1 + 5, 120, 81, 169);
					myLine(x2 - 2, y1 - 5, x2 + 3, y1 + 5, 120, 81, 169);
					myLine(x2 + 3, y1 + 5, x2 - 19, y2 + 7, 120, 81, 169);
					myLine(x2, y1 + 5, x2 - 23, y2 + 2, 120, 81, 169);
					myLine(x1 - 2, y1 + 5, x1 + 19, y2 + 7, 120, 81, 169);
					myLine(x1, y1 + 5, x1 + 22, y2 + 2, 120, 81, 169);


					myEllipseS(x1 + 8, y1 + 5, x2 - 8, y2 - 5, 120, 81, 169);

					myEllipseS(x1 + 3, y1 - 2, x2 - 1, y1 + 8, 120, 81, 169);
					myEllipseS(x1 + 5, y1 + 8, x2 - 3, y1 + 13, 120, 81, 169);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 8)
				{
					myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 + 20 + 2, y1, x1, y2 - 16, 218, 124, 48, 8);
					myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, 218, 124, 48, 14);
					myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, 218, 124, 48);
					myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, 218, 124, 48);
					myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 - 3, y2 - 20, x1 + 22, y2, 218, 124, 48, 8);
					myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, 218, 124, 48);
					myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, 218, 124, 48, 14);

					myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, 218, 124, 48);
					myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, 218, 124, 48, 10);
					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 9)
				{
					myLine(x1 + 20, y1, x1 - 5, y2 + 5, 19, 98, 7);
					myLine(x1 + 20, y1, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1 - 5, y2 + 5, x2 + 5, y2 + 5, 19, 98, 7);
					myLine(x1, y2, x2, y2, 19, 98, 7);
					myLine(x1 + 3, y2 - 5, x2 - 3, y2 - 5, 19, 98, 10);
					myLine(x1 + 5, y2 - 9, x2 - 3, y2 - 10, 19, 98, 14);
					myEllipseS(x1 + 10, y1 + 7, x2 - 10, y2 + 6, 19, 98, 7);


					x1 += 90;
					x2 += 90;
				}
				else if (board[i][j] == 20)
				{
				red = 0;
				green = 139;
				blue = 139;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 21)
				{
				red = 155;
				green = 28;
				blue = 49;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 22)
				{
				red = 120;
				green = 81;
				blue = 169;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 23)
				{
				red = 218;
				green = 124;
				blue = 48;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else if (board[i][j] == 24)
				{
				red = 19;
				green = 98;
				blue = 7;
				myLine(x1 + 22 - 3, y1 - 5, x1 - 3 - 3, y2 - 20, red, green, blue);
				myLineL(x1 + 20 + 2, y1, x1, y2 - 16, red, green, blue, 8);
				myLineL(x1 + 18, y1 + 10, x1 + 11, y2 - 16 + 7, red, green, blue, 14);
				myEllipseS(x1 + 10, y1 + 10, x1 + 30, y2 - 16 + 7, red, green, blue);
				myEllipseS(x1 + 15, y1 + 1, x1 + 15, y2 - 16 + 10, red, green, blue);
				myLine(x1 - 3 - 3, y2 - 20, x1 + 22 - 3, y2 + 5, red, green, blue);
				myLineL(x1 - 3, y2 - 20, x1 + 22, y2, red, green, blue, 8);
				myLine(x1 + 20 + 28 - 3, y2 - 20, x1 - 5 + 28 - 3, y2 + 5, red, green, blue);
				myLineL(x1 + 20 + 28 - 12, y2 - 17, x1 - 5 + 28 - 7, y2 + 5 - 9, red, green, blue, 14);

				myLine(x1 - 5 + 28 - 3, y1 - 5, x1 + 20 + 28 - 3, y2 - 20, red, green, blue);
				myLineL(x1 - 5 + 28 - 5, y1, x1 + 20 + 28 - 12, y2 - 20 - 5, red, green, blue, 10);

				myRects(x1, y1, x2, y2, red, green, blue);
				x1 += 90;
				x2 += 90;
				}
				else
				{
					r = 0;
					g = 139;
					b = 139;
					myEllipse(x1 - 5, y1 - 5, x2 + 5, y2 + 5, r, g, b);
					x1 += 90;
					x2 += 90;
				}
			}
		}
		y1 += 90;
		y2 += 90;
	}
	Sleep(1000);
}




