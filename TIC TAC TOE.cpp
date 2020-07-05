#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
bool win(int& player1, int& player2, bool& f)
{
	if (player2 == 3 || player1 == 3)
	{
		f = true;
		return f;
	}

	else
	{
		player1 = 0;
		player2 = 0;
		return 0;
	}
}

bool finish(vector<vector<int>> board)
{
	bool f = 0;
	int player1 = 0, player2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				break;
			}

			else
			{
				if (board[i][j] == 1)
				{
					player1++;
				}

				else
				{
					player2++;
				}
			}
		}

		if (win(player1, player2, f) == true)
		{
			break;
		}
	}
	if (f == 0)
	{
		for (int k = 0; k < 3; k++)
		{
			if (f == true)
			{
				break;
			}

			for (int j = 0; j < 3; j++)
			{
				if (board[j][k] == 0)
				{
					break;
				}

				else
				{
					if (board[j][k] == 1)
					{
						player1++;
					}

					else
					{
						player2++;
					}
				}
			}

			if (win(player1, player2, f) == true)
			{
				break;
			}
		}

		if (f == false)
		{
			for (int k = 0; k < 3; k++)
			{
				if (board[k][k] == 0)
				{
					break;
				}

				else
				{
					if (board[k][k] == 1) {
						player1++;
					}

					else
					{
						player2++;
					}
				}
			}
			if (win(player1, player2, f) == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					if (board[i][2 - i] == 0)
					{
						break;
					}
					else
					{
						if (board[i][2 - i] == 1)
						{
							player1++;
						}

						else
						{
							player2++;
						}
					}
				}
				win(player1, player2, f);
			}
		}
	}
	return f;
}
bool valid_play(string pos, vector<vector<int>>& board, vector<int>& posn, int P)
{
	char y[] = { 't','m','b' }, x[] = { 'l','m','r' };
	for (int i = 0; i < 3; i++)
	{
		if (pos[0] == y[i])
		{
			posn[0] = i;
		}

		if (pos[1] == x[i])
		{
			posn[1] = i;
		}
	}

	if (board[posn[0]][posn[1]] != 0)
	{
		cout << "Invalid Position as it is already being used! \n";
		return 0;
	}

	else
	{
		board[posn[0]][posn[1]] = P;
	}
}

void draw(vector<vector<int>> board)
{
	cout << "-------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "| ";
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				cout << " " << " | ";
			}

			else if (board[i][j] == 1)
			{
				cout << "X" << " | ";
			}

			else
			{
				cout << "O" << " | ";
			}
		}
		cout << endl;
		cout << "-------------" << endl;
	}
}

int main()
{
	cout << "First Letter: t (top), m (middle), b (bottom) \n";
	cout << "Second Letter: l (left), m (middle), r (right) \n";
	cout << "All Letters must be in lower case (ex: abcdef...)" << endl;

	string p;
	int count = 0;
	bool check = false;
	vector<vector<int>> board(3, vector<int>(3, 0));
	draw(board);

	while (check == false && count < 9)
	{
		vector <int> posn = { 0,0 };
		cout << "What position you want to play? Player" << ((count + 10) % 2 + 1) << endl;
		cin >> p;
		if (valid_play(p, board, posn, ((count + 10) % 2) + 1))
		{
			count++;
		}

		else
		{
			continue;
		}
		draw(board);
		check = finish(board);
	}

	cout << "\nWinner: Player" << (count + 3) % 2 + 1 << endl;
	return 0;
}
