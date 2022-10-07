//Header files
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include "help.h"
#include "Animation.h"
#include <thread>
#include <fstream>
using namespace std;



//Global variables



int p1 = 630, p2 = 150, p3 = 710, p4 = 235;
int entered = 0;
int previous_i{};
int previous_j{};
int swap_i = 0;
int swap_j = 0;
bool CheckAgain = false;
int PlayerScore = 0;
int BotScore = 0;
int board[8][8];
bool TimeFinished = false;
int HighScore;
bool player2 = false;
int store_bot_score = 0;




//Function prototypes



void PlayGame(int board[][8]);
void menu(int board[][8]);
void check(int board[][8],bool animation);
void check1(int board[][8],bool animation);
void interference(int board[][8],int type);
void single_row_operation(int board[][8], int r, int  c);
void board_updater_after_row(int board[][8], int i, int j, bool flag);
void input();
void AttributeGiver(int board[][8], int r, int c);
void check_special_gem_col(int board[][8], int row, int col);
void row_operation(int board[][8], int i, int j, int position);
void check_special_gem_row(int board[][8], int row, int col);
void TwoRowOperation(int board[][8], int i, int j);
void elbow_thunder_operator(int board[][8], int r, int c);
void check_elbow(int board[][8], int r, int c);
void swap_restricter(int board[][8]);
bool checking_the_swapped(int board[][8]);
void check_special_col(int board[][8]);
void special_gem_col_operation(int board[][8], int r, int c, int position);
void check_special_row(int board[][8]);
void Special_gem_row_operation(int board[][8], int r, int c, int case_of_equality, int position);
void GiveRandomValues(int board[][8]);
void instructions(int board[][8]);
void LoadingContent();
void PrintDiamond(int x, int y);
void LoadingPageText();
void check_T_shape(int board[][8], int r, int c);
void elbow_operator(int board[][8], int r, int c);
void operate_if_star(int board[][8],bool flag);
void timer();
void GameOver(int board[][8]);
void threader(int board[][8], int turn);
void PrintScore(int type);
void bot();
void Player2();





//Functions


// This function runs the input function(which takes the input from the user and
// performs swapping and does the necessary checking of the board and the timer
// turn taken in the parameter decides to thread with bot or with the user input
void threader(int board[][8],int turn)
{
	if (turn == 1)
	{
		thread thread1 = thread(bot);
		thread thread2 = thread(timer);
		thread2.join();
		thread1.join();
	}
	else if (turn == 0)
	{
		thread thread1 = thread(input);
		thread thread2 = thread(timer);
		thread2.join();
		thread1.join();
	}
}

//This function Prints the score
void PrintScore(int type)
{
	if (type == 1)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t   H I G H S C O R E : " << HighScore << endl << endl;;
		cout << "\t\t\t\t\t\t\t\t\t       S C O R E : " << PlayerScore << endl;
	}
	else
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t   B O T S C O R E : " << BotScore << endl << endl;;
		cout << "\t\t\t\t\t\t\t\t\t       S C O R E : " << PlayerScore << endl;
	}
	Sleep(3000);
	system("cls");
}


//This fuction prints score and saves the highest score and calls the menu function to again ask for different options
// Parameter bool computer tell whether it was bot playing or person
void GameOver(int board[][8],bool computer)
{
	if (!computer)
	{
		ofstream fout("HighScore"); // this is to save high score 
		ifstream fin("HighScore");
		if (HighScore < PlayerScore)
		{
			HighScore = PlayerScore;
			fout << HighScore;
		}
		else
		{
			fin >> HighScore;
		}
		fout.close();
		system("cls");
		over();
		Sleep(3000);
		system("cls");
		PrintScore(1);
		system("cls");
	}
	else
	{
		BotScore = store_bot_score;  
		system("cls");
		over(); // prints gameover
		Sleep(3000);
		system("cls");
		PrintScore(2);
		cout << endl << endl<<endl;
		if (BotScore > PlayerScore)
		{
			cout << "				You Played Well But you probably need to practice more" << endl;
		}
		else
		{
			cout << "				That was Incredible.Man is still the most extraordinary computer of all time" << endl;
		}
		Sleep(3000);
		system("cls");
	}
	cin.ignore(80,'\n');
	TimeFinished = false; // reset the value to its default
	menu(board); // menu function is called
}
void timer()
{
	int x, y;
	x = 613;
	y = 52;
	myRect(598+3, 40, 1357, 70, 255, 255, 255); // this prints the bar of the timer
	for (int s =60; s >= 0; --s)
	{
		gotoxy(0, 0); // to reset the cursor to origin to print score 
		cout << endl << endl << endl << endl << endl << endl << endl;;
		if (player2)
		{
			cout << "			SCORE : " <<PlayerScore;
		}
		else
		{
			cout << "			SCORE : " << BotScore;
		}
		myRectL(x, y, x + 12, y+5, 0, 139, 139, 13);
		x += 12;
		Sleep(10000);
	}
	TimeFinished = true;

}
// This function handles the turn of the player after the bot has taken its turn
void Player2()
{
	cout << "Are you Ready" << endl;
	Sleep(1000);
	system("cls");
	GiveRandomValues(board);  // to give random values to board before the turn of player2
	for (int i = 0; i < 10; ++i)  // this loop checks initially if there is any three same coloums or rows
	{
		check(board, 0);
		check1(board, 0);
	}
	player2 = true;
	PlayerScore = 0;
	interference(board, 0); 
}

//This function swaps the gem (up,right,left,down) and checks if three gems are same or not 
// if not then it swaps back and remaining are checked
// and then it checks so on for the elbow or flame gem cases
void bot()
{
	while (!TimeFinished)
	{
		for (int i = 0; i < 8 && !TimeFinished; ++i)
		{
			for (int j = 0; j < 8 && !TimeFinished; ++j)
			{
				if (i >= 1&&!TimeFinished) // up
				{
					swap(board[i][j], board[i - 1][j]);
					
					if (checking_the_swapped(board))
					{
						interference(board, 3);
						{
							Sleep(500);
						}
						for (int p = 0; p < 10; ++p)
						{
							check_elbow(board, i - 1, j);
							check_special_gem_col(board, i - 1, j);
							check_special_gem_row(board, i - 1, j);
							operate_if_star(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
						}
						interference(board, 3);
					}
					else
					{
						swap(board[i][j], board[i - 1][j]);
					}
				}
				if (i <= 6 && !TimeFinished) //down
				{
					swap(board[i][j], board[i + 1][j]);
					if (checking_the_swapped(board))
					{
						interference(board, 3);
						{
							Sleep(500);
						}
						for (int p = 0; p < 10; ++p)
						{
							check_elbow(board, i + 1, j);
							check_special_gem_col(board, i + 1, j);
							check_special_gem_row(board, i + 1, j);
							operate_if_star(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
						}
						interference(board, 3);
					}
					else
					{
						swap(board[i][j], board[i + 1][j]);
					}
				}
				
				if (j >= 1 && !TimeFinished) //left
				{
					swap(board[i][j], board[i][j - 1]);
					if (checking_the_swapped(board))
					{
						interference(board, 3);
						{
							Sleep(500);
						}
						for (int p = 0; p < 10; ++p)
						{
							check_elbow(board, i, j - 1);
							check_special_gem_col(board, i, j - 1);
							check_special_gem_row(board, i, j - 1);
							operate_if_star(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
						}
						interference(board, 3);
					}
					else
					{
						swap(board[i][j], board[i][j - 1]);
					}
				}
				if (j <= 6 && !TimeFinished) //right
				{
					swap(board[i][j], board[i][j + 1]);
					if (checking_the_swapped(board))
					{
						interference(board, 3);
						{
							Sleep(500);
						}
						for (int p = 0; p < 10; ++p)
						{
							check_elbow(board, i, j + 1);
							check_special_gem_col(board, i, j + 1);
							check_special_gem_row(board, i, j + 1);
							operate_if_star(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
							check(board, 1);
							check1(board, 1);
						}
						interference(board, 3);
					}
					else
					{
						swap(board[i][j], board[i][j + 1]);
					}
				}
			}
		}
	}
	system("cls");
	TimeFinished = false;
	store_bot_score = BotScore; // this is to store the bots score and to be safe for any loss of data
	Player2();
}
//This fuction is used to give the attributes to the Special gem so that it may be distinguished
// Attribute is given with the help of incrementing a constant of +5 
void AttributeGiver(int board[][8], int r, int c)
{
	board[r][c] += 5;
}
// This functions check if the special gem is to be made or not and then gives the attribute to that 
// gem , then it performs the necessary operation and also calls the animator to print the animation
void check_special_gem_col(int board[][8], int row, int col)
{
	int position = 0;
	bool checking = false;
	for (int c = 0; c < 8; ++c)
	{
		for (int r = 0; r < 5; ++r)
		{
			checking = 0;
			if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && board[r + 2][c] == board[r + 3][c])
			{
				
				if (r + 1 == row && c == col)
				{
					checking = true; // to see if the special is to be made or not
					position = 2; // to know the position of special gem
				}
				else if (r + 2 == row && c == col)
				{
					checking = true; // to see if the special is to be made or not
					position = 3; // to know the position of special gem
				}
				
				if (checking)
				{
					PlayerScore += 1200;
					BotScore += 1200;

					board[row][col] += 5;
					special_animator_col(board, row, col, position); // animation 
					if (position == 2)
					{
						single_row_operation(board, row -1, c);
						single_row_operation(board, row + 2, c);
						single_row_operation(board, row + 2, c);
					}
					else if (position == 3)
					{
						single_row_operation(board, row - 1, c);
						single_row_operation(board, row - 1, c);
						single_row_operation(board, row + 1, c);
					}
					break;
				}
			}
		}
	}
}
// this function performs the necessary operation after a special gem is made and also calls
// the animator it takes the position of the special gem and the value of its row and col to per
// fom the operation(delete particular rows).
void row_operation(int board[][8], int i, int j, int position)
{
	special_animator_row(board,i,j, position);
	if (position == 2)
	{
		int c1 = j - 1;
		int c2 = j + 1;
		int c3 = j + 2;
		for (int r = i; r >= 0; --r)
		{
			if (r == 0)
			{
				board[r][c1] = rand() % 5;
				board[r][c2] = rand() % 5;
				board[r][c3] = rand() % 5;

			}
			else
			{
				board[r][c1] = board[r - 1][c1];
				board[r][c2] = board[r - 1][c2];
				board[r][c3] = board[r - 1][c3];
			}
		}
	}
	else if (position == 3)
	{
		int c1 = j + 1;
		int c2 = j - 1;
		int c3 = j - 2;
		for (int r = i; r >= 0; --r)
		{
			if (r == 0)
			{
				board[r][c1] = rand() % 5;
				board[r][c2] = rand() % 5;
				board[r][c3] = rand() % 5;

			}
			else
			{
				board[r][c1] = board[r - 1][c1];
				board[r][c2] = board[r - 1][c2];
				board[r][c3] = board[r - 1][c3];
			}
		}
	}
}
// This functions check if the special gem is to be made or not and then gives the attribute to that 
// gem , then it performs the necessary operation and also calls the animator to print the animation
void check_special_gem_row(int board[][8], int row, int col)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			bool flag = 0;
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3])
			{
				if (i == row && j + 1 == col)
				{
					PlayerScore += 1200;
					BotScore += 1200;

					AttributeGiver(board, i, j + 1);

					row_operation(board, i, j + 1, 2);
				}
				else if (i == row && j + 2 == col)
				{
					PlayerScore += 1200;
					BotScore += 1200;

					AttributeGiver(board, i, j + 2);

					row_operation(board, i, j + 2, 3);
				}
			}
		}
	}
}
// This function takes a row and col and delets the col of that row and the col next to it of same
//row 
void TwoRowOperation(int board[][8], int i, int j)
{
	for (int k = i; k >= 0; k--)
	{
		if (k == 0)
		{
			board[k][j] = rand() % 5;
			board[k][j + 1] = rand() % 5;
		}
		else
		{
			board[k][j] = board[k - 1][j];
			board[k][j + 1] = board[k - 1][j + 1];
		}
	}
}
// This function performs the necessary operation once the destroyer gem explodes 
void elbow_thunder_operator(int board[][8], int r, int c)
{
	srand(time(0));
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i == c)
			{
				board[j][i] = rand() % 5;
			}
		}
	}
	for (int k = 0; k < 8; k += 2)
	{
		TwoRowOperation(board, r, k);
	}

}

// This function checks if a T is formed either way and then gives attributes to the row and col 
// of the destroyer gem, then it also calls the animator to print the anmation
void check_T_shape(int board[][8], int r, int c)
{
	int position = 0;
	if (board[r][c - 1] == board[r][c] && board[r][c] == board[r][c + 1] &&c>=1&&c<=6)
	{
		if (board[r][c] == board[r + 1][c] && board[r+1][c] == board[r+2][c] && r<=5)
		{
			board[r][c] += 20;

			position = 1;
		}
		else if (board[r][c] == board[r - 1][c] && board[r - 1][c] == board[r - 2][c] && r >=2)
		{
			board[r][c] += 20;

			position = 2;

		}
	}
	else if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r - 1][c] && r >= 1 && r <= 6)
	{

		if (c <= 5&& board[r][c + 1] == board[r][c] && board[r][c] == board[r][c + 2] )
		{
			board[r][c] += 20;
			position = 3;

		}
		else if (c >=2&&board[r][c - 1] == board[r][c] && board[r][c] == board[r][c - 2])
		{
			board[r][c] += 20;
			position = 4;

		}
	}
	if (position != 0)
	{
		PlayerScore += 2000;
		BotScore += 2000;

		T_making_animator(board, r, c, position);
	}
	
	if (position==1)
	{
		single_row_operation(board, r, c - 1);
		single_row_operation(board, r, c + 1);

		single_row_operation(board, r + 2, c);
		single_row_operation(board, r + 2, c);
	}
	else if (position==2)
	{
		single_row_operation(board, r, c - 1);
		single_row_operation(board, r, c + 1);
		single_row_operation(board, r - 1, c);
		single_row_operation(board, r - 1, c);

	}
	else if (position == 3)
	{
		single_row_operation(board, r + 1, c);
		single_row_operation(board, r, c);
		TwoRowOperation(board, r, c + 1);
	}
	else if (position == 4)
	{
		single_row_operation(board, r + 1, c);
		single_row_operation(board, r, c);
		TwoRowOperation(board, r, c - 2);
	}
}

void elbow_operator(int board[][8], int r, int c,int turn1,int turn2)
{
	elbow_making_animator(board, r, c, turn1, turn2);
	if (turn1 == 1||turn2==1)
	{
		single_row_operation(board, r - 1, c);
		single_row_operation(board, r - 1, c);
	}
	if (turn1 ==2||turn2==2)
	{
		TwoRowOperation(board, r, c + 1);
	}
	if (turn1 == 3||turn2==3)
	{
		TwoRowOperation(board, r, c -2);
	}
	if (turn1 == 4||turn2==4)
	{
		single_row_operation(board, r + 1, c);
		single_row_operation(board, r + 2, c);
	}
}
//This fuction checks if L case is to be made or not then gives attribute to it also calls animator
// to display beautiful animation, it takes the row and col and of the swapped 
void check_elbow(int board[][8], int r, int c)
{
	bool flag1 = 0;
	bool flag2 = 0;
	bool elbow = false;
	int turn1 = 0;
	int turn2 = 0;

	if (board[r][c] == board[r - 1][c] && board[r - 1][c] == board[r - 2][c] && r >= 2)
	{
		turn1 = 1;
		flag1 = 1;
	}
	else if (board[r][c + 1] == board[r][c] && board[r][c + 1] == board[r][c + 2] && c <= 5)
	{
		turn1 = 2;

		flag1 = 1;
	}
	else if (board[r][c - 1] == board[r][c] && board[r][c - 1] == board[r][c - 2] && c >= 2)
	{
		turn1 = 3;

		flag1 = 1;
	}
	else if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && r <= 5)
	{
		turn1 = 4;

		flag1 = 1;
	}

	if (flag1 == 1)
	{
		if (board[r][c] == board[r - 1][c] && board[r - 1][c] == board[r - 2][c] && r >= 2)
		{
			turn2 = 1;
			flag2 = 1;
		}
		if (c <= 5 && board[r][c] == board[r][c + 1] && board[r][c + 1] == board[r][c + 2])
		{
			turn2 = 2;

			flag2 = 1;
		}
		if (board[r][c - 1] == board[r][c] && board[r][c - 1] == board[r][c - 2] && c >= 2)
		{
			turn2 = 3;

			flag2 = 1;
		}
		if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && r <= 5)
		{
			turn2 = 4;

			flag2 = 1;
		}
		if (flag2)
		{
			if (turn1 == 1 || turn1 == 4)
			{
				if (turn2 == 2 || turn2 == 3)
				{
					elbow = 1;
				}
			}
			else if (turn1 == 2 || turn1 == 3)
			{
				if (turn2 == 1 || turn2 == 4)
				{
					elbow = 1;
				}
			}
		}
	}
	if (elbow)
	{
		board[r][c] += 20;
		PlayerScore += 2000;
		BotScore += 2000;
		elbow_operator(board, r, c, turn1, turn2);
	}
	if (!elbow)
	{

		check_T_shape(board, r, c); // to check if T case is made or not
	}
}

//This function return true if after swapping the board 3 rows or 3 col are same and viceversa
bool checking_the_swapped(int board[][8])
{
	bool flag = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i])
			{
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[j][i] - 5 == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] || board[j][i] == board[j + 1][i] - 5 && board[j + 1][i] - 5 == board[j + 2][i] || board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] - 5)
			{
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j] == board[i][j + 1] - 5 && board[i][j + 1] - 5 == board[i][j + 2])
				flag = 1;
			else if (board[i][j] - 5 == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
				flag = 1;
			else if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] - 5)
				flag = 1;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[j][i] - 20 == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] || board[j][i] == board[j + 1][i] - 20&& board[j + 1][i] - 20 == board[j + 2][i] || board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] - 20)
			{
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j] == board[i][j + 1] - 20 && board[i][j + 1] -20 == board[i][j + 2])
				flag = 1;
			else if (board[i][j] - 20 == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
				flag = 1;
			else if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] - 20)
				flag = 1;
		}
	}
	if (flag == 1)
	{
		return true;
	}
	return false;
}

//This function checks if the swapping is done correctly or not 
void swap_restricter(int board[][8])
{
	bool flag = 1;
	if (previous_i == swap_i && (previous_j + 1 == swap_j || previous_j - 1 == swap_j))
	{
		flag = 0;

	}
	if (previous_j == swap_j && (previous_i + 1 == swap_i || previous_i - 1 == swap_i))
	{
		flag = 0;
	}
	if (flag == 1)
	{
		swap(board[swap_i][swap_j], board[previous_i][previous_j]);
	}
	else if (checking_the_swapped(board) == false)
	{
		swap(board[swap_i][swap_j], board[previous_i][previous_j]);

	}
}
// This function takes input from the user(cursor movement),
// performs swapping and also checks the board
void input()
{
	int key;
	while (!TimeFinished) // Time finished is updated after 60 sec of game
	{
		bool pressed = isCursorKeyPressed(key);
		myRect(p1, p2, p3, p4, 255, 255, 255);
		if (pressed)
		{
			myRect(p1, p2, p3, p4, 0, 0, 0);
			if (key == 1)
			{
				if (p1 != 630) // to mantain the boundry of cursor
				{
					p1 -= 90;
					p3 -= 90;
					swap_j--;
				}
				myRect(p1, p2, p3, p4, 255, 255, 255);
			}
			else if (key == 2)
			{
				if (p2 != 150)// to mantain the boundry of cursor
				{
					p2 -= 90;
					p4 -= 90;
					swap_i--;

				}
				myRect(p1, p2, p3, p4, 255, 255, 255);

			}
			else if (key == 4)
			{
				if (p4 != 865) // to mantain the boundry of cursor
				{
					p2 += 90;
					p4 += 90;
					++swap_i;

				}
				myRect(p1, p2, p3, p4, 255, 255, 255);

			}
			else if (key == 3)
			{
				if (p3 != 1340)// to mantain the boundry of cursor
				{
					p1 += 90;
					p3 += 90;
					++swap_j;

				}
				myRect(p1, p2, p3, p4, 255, 255, 255);
			}
			else if (key == 5)
			{
				++entered; // to observe entered is pressed once
			}
			if (entered == 1 && CheckAgain == false)
			{
				previous_i = swap_i;
				previous_j = swap_j;
				CheckAgain = true;
			}
			else if (entered == 2)
			{
				entered = 0;
				swap(board[swap_i][swap_j], board[previous_i][previous_j]);
				//swap_restricter(board);
				for (int p = 0; p < 10; ++p) // This loop is used to check again and again 
				{
					check_elbow(board, swap_i, swap_j);
					check_special_gem_col(board, swap_i, swap_j);
					check_special_gem_row(board, swap_i, swap_j);
					check_special_gem_col(board, previous_i, previous_j);
					check_special_gem_row(board, previous_i, previous_j);
					operate_if_star(board, 1);
					check(board, 1);
					check1(board, 1);
					check(board, 1);
					check1(board, 1);
					check(board, 1);
					check1(board, 1);
				}
				interference(board, 3);
				CheckAgain = 0;
			}
		}
	}
	system("cls");
	if (!player2)
	{
		GameOver(board, 0);
	}
	else
	{
		GameOver(board, 1);
	}
}
// This functions operates if a destroyer gem is exploded and also expreses the animations
// flag tells if it is initial check or post check
void operate_if_star(int board[][8],bool flag)
{
	for (int i = 0; i < 8; ++i) // this loop checks for the row condition
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j]  == board[i][j + 1] - 20 && board[i][j + 1] - 20 == board[i][j + 2])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if(flag==1)
					thunder_animator(board, i, j + 1);
				elbow_thunder_operator(board, i, j + 1);
			}
			else if (board[i][j] - 20 == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if (flag == 1)
					thunder_animator(board, i, j);
				elbow_thunder_operator(board, i, j );
			}
			else if (board[i][j]  == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] - 20)
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if (flag == 1)
					thunder_animator(board, i, j + 2);
				elbow_thunder_operator(board, i, j + 2);
			}
		}
	}
	for (int i = 0; i < 8; ++i) // this loop is to check the col condition
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[j][i]-20== board[j + 1][i] && board[j + 1][i] == board[j + 2][i])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if(flag==1)
					thunder_animator(board, j,i );
				elbow_thunder_operator(board, j,i  );
			}
			else if (board[j][i] == board[j + 1][i]-20 && board[j + 1][i]-20 == board[j + 2][i])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if (flag == 1)
					thunder_animator(board, j+1, i);
				elbow_thunder_operator(board, j+1, i);
			}
			else if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i]-20)
			{
				PlayerScore += 1500;
				BotScore += 1500;
				if(flag==1)
					thunder_animator(board, j+2, i);
				elbow_thunder_operator(board, j+2, i);
			}
		}
	}
}
//This function takes row and col and then deletes the three consecutive from the board
// bool flag tell if to delete 3 or 4 consecutive rows if flag=1 it mean delete 4 and 3 incase of 0
void board_updater_after_row(int board[][8], int row, int j, bool flag)
{
	for (int i = row - 1; i >= 0; --i)
	{
		if (i == 0)
		{
			if (flag == 1)
			{
				board[i][j] = rand() % 5;
				board[i][j + 1] = rand() % 5;
				board[i][j + 2] = rand() % 5;
				board[i][j + 3] = rand() % 5;
			}
			else
			{
				board[i][j] = rand() % 5;
				board[i][j + 1] = rand() % 5;
				board[i][j + 2] = rand() % 5;
			}
		}
		else
		{
			if (flag == 1)
			{
				board[i][j] = board[i - 1][j];
				board[i][j + 1] = board[i - 1][j + 1];
				board[i][j + 2] = board[i - 1][j + 2];
				board[i][j + 3] = board[i - 1][j + 3];
			}
			else
			{
				board[i][j] = board[i - 1][j];
				board[i][j + 1] = board[i - 1][j + 1];
				board[i][j + 2] = board[i - 1][j + 2];
			}
		}
	}
}
// This function is used to operate(exploding of the special gem) according to the position given
//  of the special gem and also cals the animator
void special_gem_col_operation(int board[][8], int r, int c, int position)
{
	special_gem_explode_animator_col(board, r, c, position);
	if (position == 1)
	{
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
		single_row_operation(board, r + 2, c);
	}
	else if (position == 2)
	{
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
	}
	else if (position == 3)
	{
		single_row_operation(board, r + 2, c);
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
		board_updater_after_row(board, r + 2, c - 1, 0);
	}
}
//This function is used to check if the special gem is paired with other two gems of same type and the calls the operator
void check_special_col(int board[][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[j][i] - 5 == board[j + 1][i] && board[j + 1][i] == board[j + 2][i])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				special_gem_col_operation(board, j, i, 1);
			}
			else if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] - 5)
			{
				PlayerScore += 1500;
				BotScore += 1500;
				special_gem_col_operation(board, j+2, i, 3);
			}
			else if (board[j][i] == board[j + 1][i] - 5 && board[j + 1][i] - 5 == board[j + 2][i])
			{
				PlayerScore += 1500;
				BotScore += 1500;
				special_gem_col_operation(board, j+1, i, 2);
			}
		}
	}
}
//This function checks if three gems are same in the coloums and then operates necessarily
void check1(int board[][8],bool animation)
{
	check_special_col(board);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (animation)
			{
				check_elbow(board, j, i);
				operate_if_star(board, 1);
				if (j <= 5)
				{
					check_elbow(board, j + 2, i);
					operate_if_star(board, 1);
				}
				if (i<=5)
				{
					check_elbow(board, j, i + 2);
					operate_if_star(board, 1);
				}
			}
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 2][i] == board[j + 3][i])
			{
				PlayerScore += 250;
				BotScore += 250;
				if (animation)
				{
					colanimator(board, i, j, 1);

				}
				single_row_operation(board, j+3, i );
				single_row_operation(board, j+3, i );
				single_row_operation(board, j+3, i );
				single_row_operation(board, j+3, i );
			}
			else if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i])
			{
				PlayerScore += 250;
				BotScore += 250;
				if (animation)
				{
					colanimator(board, i, j,0);

				}
				single_row_operation(board, j + 2, i);
				single_row_operation(board, j + 2, i);
				single_row_operation(board, j + 2, i);
			}
		}
	}
}
//This is the most useful function and it deletes only one element from the board
// It deletes the element whose row and col is given
void single_row_operation(int board[][8], int r, int c)
{
	for (int i = r; i >= 0; --i)
	{
		if (i == 0)
		{
			board[i][c] = rand() % 5;
		}
		else
		{
			board[i][c] = board[i - 1][c];
		}
	}
}
//This function is used to print the shapes 
// type tells wheter whether player is playing or bot was playing 0 incase of bot and 1 incase of player 
// (it further decides to thread with the help of it)and incase any other value is given it just prints 
//the shape on the board
void interference(int board[][8], int type)
{
	myRects(500, 120, 1650, 1200, 11, 11, 11);
	int red, green, blue;
	myRect(600, 120, 1375, 908, 0, 139, 139);
	int x1 = 650, y1 = 170, x2 = 690, y2 = 210, r = 255, g = 0, b = 0;
	for (int i = 0; i < 8; ++i)
	{
		x1 = 650;
		x2 = 690;
		for (int j = 0; j < 8; ++j)
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
		y1 += 90;
		y2 += 90;
	}
	if (type == 0)
	{
		threader(board, 0);
	}
	else if (type == 1)
	{
		threader(board, 1);
	}
}
//This function is used to operates when the special gem explodes according to the position given to it 
// it also calls the animator to display the animation
void Special_gem_row_operation(int board[][8], int r, int c, int case_of_equality, int position)
{
	special_gem_explode_animator_row(board, r, c, position, case_of_equality);
	if (case_of_equality == 3)
	{
		if (position == 1)
		{
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
			single_row_operation(board, r, c + 2);
		}
		else if (position == 2)
		{
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
		}
		else if (position == 3)
		{
			single_row_operation(board, r, c - 2);
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
			board_updater_after_row(board, r + 2, c - 1, 0);
		}
	}
}
//this function checks if 3 rows are same including the special gem 
void check_special_row(int board[][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j] == board[i][j + 1] - 5 && board[i][j + 1] - 5 == board[i][j + 2])
			{
				Special_gem_row_operation(board, i, j+1, 3, 2);
				PlayerScore += 1500;
				BotScore += 1500;
			}

			else if (board[i][j] - 5 == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				Special_gem_row_operation(board, i, j, 3, 1);
				PlayerScore += 1500;
				BotScore += 1500;
			}
			else if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] - 5)
			{
				Special_gem_row_operation(board, i, j+2, 3, 3);
				PlayerScore += 1500;
				BotScore += 1500;
			}
		}
	}
}
//This function checks if three gems are same in the rows and then operates necessarily

void check(int board[][8],bool animation)
{
	check_special_row(board);

	bool flag = false;
	for (int i = 0; i < 8; ++i)
	{

		for (int j = 0; j < 6; ++j)
		{
			if (animation)
			{
				check_elbow(board, i, j);
				operate_if_star(board, 1);
				if (i <= 5)
				{
					check_elbow(board, i + 2, j);
					operate_if_star(board, 1);
				}

				if (j <= 5)
				{
					check_elbow(board, i, j + 2);
					operate_if_star(board, 1);
				}

			}
			flag = 0;
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				PlayerScore += 250;
				BotScore += 250;

				if (i == 0)
				{
					if (board[i][j + 2] == board[i][j + 3] && j < 5)
					{
						board[i][j] = rand() % 5;
						board[i][j + 1] = rand() % 5;
						board[i][j + 2] = rand() % 5;
						board[i][j + 3] = rand() % 5;
						flag = 1;
					}
					else
					{
						board[i][j] = rand() % 5;
						board[i][j + 1] = rand() % 5;
						board[i][j + 2] = rand() % 5;
					}
				}
				else
				{
					PlayerScore += 250;
					BotScore += 250;

					if (board[i][j + 2] == board[i][j + 3] && j < 5)
					{
						board[i][j] = board[i - 1][j];
						board[i][j + 1] = board[i - 1][j + 1];
						board[i][j + 2] = board[i - 1][j + 2];
						board[i][j + 3] = board[i - 1][j + 3];
						flag = 1;
					}
					else
					{
						board[i][j] = board[i - 1][j];
						board[i][j + 1] = board[i - 1][j + 1];
						board[i][j + 2] = board[i - 1][j + 2];
					}
				}


				if (animation==true)
				{
					animator(board, i, j, flag);
				}
				board_updater_after_row(board, i, j, flag);

			}

		}
	}
}
void LoadingPageText()
{
	cout << "\n                            BBBBBBB    EEEEEEEE   JJJJJJJJ   EEEEEEEE   WW      WW      WW   EEEEEEEE   LL          EEEEEEEE   DDDDDD     ";
	cout << "\n                            BB     B   EE               JJ   EE          WW    WWWW    WW    EE         LL          EE         DD    DD    ";
	cout << "\n                            BBBBBBB    EEEEEEEE         JJ   EEEEEEEE     WW  WW  WW  WW     EEEEEEEE   LL          EEEEEEEE   DD     DD    ";
	cout << "\n                            BB     B   EE         JJ    JJ   EE            WWWW    WWWW      EE         LL          EE         DD    DD    ";
	cout << "\n                            BBBBBBB    EEEEEEEE     JJJJJ    EEEEEEEE       WW      WW 	     EEEEEEEE   LLLLLLLLL   EEEEEEEE   DDDDDDD      ";
	cout << endl;		      
	cout << endl;		      
	cout << endl;		      
	cout << "\n                                              BBBBBBB     LL         IIIIIIIII   TTTTTTTTTTTT   ZZZZZZZZZZZ        ";
	cout << "\n                                              BB     B    LL            II            TT                ZZ          ";
	cout << "\n                                              BBBBBBB     LL            II            TT             ZZ              ";
	cout << "\n                                              BB     B    LL            II            TT          ZZ                ";
	cout << "\n                                              BBBBBBB     LLLLLLLLL  IIIIIIIII        TT        ZZZZZZZZZZZ        ";

}
void PrintDiamond(int x, int y)
{
	myLine(x, y, x + 330, y, 0, 255, 255);
	myLine(x-35, y+58, x + 365, y+58, 0,255 , 255);
	myLine(x+370-40, y, x+370 , y +60, 0, 255, 255);
	myLine(x, y, x-40 , y + 60, 0, 255, 255);
	myLine(x-40, y+58, x+170 , y + 490, 0,255, 255);
	myLine(x+30, y+58, x+170 , y + 490, 0, 255, 255);
	myLine(x+100, y+58, x+170 , y + 490,0 ,255 , 255);
	myLine(x+370 , y+58, x-60 + 230, y + 490,0,  255, 255);
	myLine(x+300 , y+58, x-60 + 230, y + 490, 0, 255, 255);
	myLine(x+230 , y+58, x-60 + 230, y + 490, 0, 255, 255);
}
void LoadingContent()
{
	int x = 700, y = 400;
	LoadingPageText();
	PrintDiamond(x,y);
	Sleep(4000);
	system("cls");
}
void instructions(int board[][8])
{
	int key = 0;
	system("cls");
	cout << "\t\t\t\t\t\t\t\t\t============================\n";
	cout << "\t\t\t\t\t\t\t\t\t\tINSTRUCTIONS\n";
	cout << "\t\t\t\t\t\t\t\t\t============================\n\n\n\n\n";
	cout << "\t\t\t\t\t1.Match 3 gems of same shape in row or coloum\n\n" << endl;
	cout << "\t\t\t\t\t2.Match 4 gems in the rows or coloum to make a special gem\n\n" << endl;
	cout << "\t\t\t\t\t3.Make a elbow L shape of a T shape to make a star gem\n\n"<< endl;
	cout << "\t\t\t\t\t4.Press Enter on the gem to select a gem to swap and press Enter again to perform swapping\n\n"<< endl;
	cout << "\t\t\t\t\t5.The bar above the board shows the time consumed\n\n"<< endl;
	cout << "\t\t\t\t\tPRESS ENTER TO RETURN TO THE MAIN MENU"<< endl;

	while (1)
	{
		bool pressed = isCursorKeyPressed(key);
		if (key == 5)
		{
			break;
		}
	}
	menu(board);
}
void menu(int board[][8])
{
	BotScore = 0;
	PlayerScore = 0;
	player2 = false;

	int x = 745, y = 250;
	int key = 0;
	int selection = 1;
	system("cls");
	cout << endl;
	cout << "						    	 **************MADE BY PROCHESSOR_ZAKI**************" << endl << endl << endl << endl << endl;
	cout << "									MAIN MENU                      " << endl << endl << endl << endl << endl;
	cout << "									PLAY GAME                      " << endl << endl;
	cout << "							             PLAY VS COMPUTER" << endl << endl;
	cout << "								       INSTRUCTIONS" << endl << endl;
	cout << "									  QUIT" << endl << endl;
	while (1)
	{
		myRect(x, y, x + 200, y + 50, 0, 255, 255);

		bool pressed = isCursorKeyPressed(key);
		if (pressed)
		{
			if (key == 2)
			{
				if (y != 250)
				{
					myRect(x, y, x + 200, y + 50, 0, 0, 0);
					y -= 50;
					myRect(x, y, x + 200, y + 50, 0, 255, 255);
					selection--;

				}

			}
			if (key == 4)
			{
				if (y != 400)
				{
					myRect(x, y, x + 200, y + 50, 0, 0, 0);
					selection++;
					y += 50;
					myRect(x, y, x + 200, y + 50, 0, 255, 255);
				}
			}
			if (key == 5)
			{
				break;
			}
		}
	}
	if (selection == 1)
	{
		PlayGame(board);
	}
	else if(selection==2)
	{
		for (int i = 0; i < 10; ++i)
		{
			check(board, 0);
			check1(board, 0);
		}
		BotScore = 0;
		PlayerScore = 0;
		system("cls");
		interference(board, 1);
	}
	else if (selection == 3)
	{
		instructions(board);
	}
	else if (selection == 4)
	{
		exit(0);
	}
	_getch();
}


void PlayGame(int board[][8])
{
	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		check(board, 0);
		check1(board, 0);
	}
	BotScore = 0;
	PlayerScore = 0;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "				P O L I S H I N G   G E M S   T O   E N S U R E   Y O U   H A V E   S P A R K L I N G   E X P R I E N C E........" << endl;
	{
		Sleep(1500);
	}
	system("cls");

	interference(board,0);
}
void GiveRandomValues(int board[][8])
{
	srand(time(0));

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = rand() % 5;
		}
	}
}
int main()
{
	ifstream fin("HighScore");
	fin >> HighScore;
	GiveRandomValues(board);
	{
		Sleep(3000);
	}
	LoadingContent();
	menu(board);
	_getch();
	system("pause");
	return 0;
}
