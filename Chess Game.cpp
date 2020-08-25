#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<math.h>
using namespace std;
bool flag = true;
int l = 0;
void check_condition(int &x1, int&y1, int&x2, int &y2)
{
	do
	{
		cout << "enter x and y co-ordinate for the object you want to move " << endl;
		cin >> x1;
		cin >> y1;
		cout << "enter x and y co-ordinate for the object where you want to move " << endl;
		cin >> x2;
		cin >> y2;
	} while ((x1 < 0 || x1>7 || y1 < 0 || y1>7) || (x2 < 0 || x2>7 || y2 < 0 || y2>7));
}
int turn()
{
	if (l % 2 == 0)
	{
		l++;
		return 1;
	}
	else if (l % 2 != 0)
	{
		l++;
		return 0;
	}
}
class Piece
{
public:
	int player;
	string player_name;
	Piece() //default constructor.
	{
		player = 0;
		player_name = " ";
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
	}
	friend void print(Piece*arr[][8]);
	Piece(string x, int y) //overloaded constructor
	{
		player = y;
		player_name = x;
	}
};
void print(Piece*arr[][8])
{
	cout << "   0      1      2      3      4      5      6      7    " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " ______ ______ ______ ______ ______ ______ ______ ______ " << endl;
		for (int j = 0; j < 8; j++)
		{
			cout << "|  " << arr[i][j]->player_name << "  ";
		}
		cout << "|" << i;
		cout << endl << "|      |      |      |      |      |      |      |      |" << endl;
		cout << "|______|______|______|______|______|______|______|______|";
		cout << endl;
	}
}
class rock :public Piece
{
public:
	rock(string x, int y)
	{
		player_name = x;
		player = y;
	}
	void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		int var;
		var = arr[x1][y1]->player;
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			cout << " you can't move in this index" << endl;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if ((var == 1) || (var == 2))
			{
				if ((y1 == y2 && x1 < x2 || x1>x2) || (x1 == x2 && y1 < y2 || y1>y2))
				{
					for (int i = x1 + 1; i < x2; i++)
					{
						for (int j = y1 + 1; j < y2; j++)
						{
							if (arr[i][j]->player == 1 && arr[i][j]->player == 2)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}
					}
					if (flag == true)
					{
						delete arr[x2][y2];
						arr[x2][y2] = new rock(arr[x1][y1]->player_name, arr[x1][y1]->player);
						arr[x1][y1]->player = 3;
						arr[x1][y1]->player_name = "  ";
					}
					if (flag == false)
					{
						cout << " you can't move in this index " << endl;
					}
				}
			}
		}
	}
};
class knight :public Piece
{
public:
	knight(string x, int y)
	{
		player_name = x;
		player = y;
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		int var = 0;
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			cout << " you can't move in this index" << endl;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if ((x2 == x1 + 2 && y2 == y1 + 1) || (x2 == x1 + 2 && y2 == y1 - 1) || (x2 == x1 + 1 && y2 == y1 + 2) || (x2 == x1 + 1 && y2 == y1 - 2) || (x2 == x1 - 1 && y2 == y1 + 2) || (x2 == x1 - 1 && y2 == y1 - 2) || (x2 == x1 - 2 && y2 == y1 + 1) || (x2 == x1 - 2 && y2 == y1 - 1))
			{
				for (int i = x1 + 1; i < x2; i++)
				{
					for (int j = y1 + 1; j < y2; j++)
					{
						if (arr[i][j]->player_name == "  ")
						{
							flag = true;
						}
						else
						{
							flag = false;
							var = i;
							break;
						}
					}
				}if (flag == true)
				{
					delete arr[x2][y2];
					arr[x2][y2] = new knight(arr[x1][y1]->player_name, arr[x1][y1]->player);
					arr[x1][y1]->player = 3;
					arr[x1][y1]->player_name = "  ";
				}
				if (flag == false)
				{
					cout << " you can't move in this index " << endl;
				}
			}
		}
	}
};
class bishop :public Piece
{
public:
	bishop(string x, int y)
	{
		player_name = x;
		player = y;
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		int var = 0;
		int num1 = abs(x1 - x2);
		int num2 = abs(y1 - y2);
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			cout << " you can't move in this index" << endl;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if ((x2 == y2) || (num1 == num2))
			{
				for (int i = x1 + 1; i < x2; i++)
				{
					for (int j = y1 + 1; j < y2; j++)
					{
						if (arr[i][j]->player_name == "  ")
						{
							flag = true;
						}
						else
						{
							flag = false;
							var = i;
							break;
						}
					}
				}
				if (flag == true)
				{
					delete arr[x2][y2];
					arr[x2][y2] = new bishop(arr[x1][y1]->player_name, arr[x1][y1]->player);
					arr[x1][y1]->player = 3;
					arr[x1][y1]->player_name = "  ";
				}
				if (flag == false)
				{
					cout << " you can't move in this index " << endl;
				}
			}
		}
	}
};
class queen :public Piece
{
public:
	queen(string x, int y)
	{
		player_name = x;
		player = y;
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		int num1 = abs(x1 - x2);
		int num2 = abs(y1 - y2);
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			cout << " you cant move in this index" << endl;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if ((y1 == y2 && x1 < x2 || x1>x2) || (x1 == x2 && y1 < y2 || y1>y2) || (x2 == y2) || (num1 == num2))
			{
				for (int i = x1 + 1; i < x2; i++)
				{
					for (int j = y1 + 1; j < y2; j++)
					{
						if (arr[i][j]->player_name == "  ")
						{
							flag = true;
						}
						else
						{
							flag = false;
							break;
						}
					}
				}
				if (flag == true)
				{
					delete arr[x2][y2];
					arr[x2][y2] = new bishop(arr[x1][y1]->player_name, arr[x1][y1]->player);
					arr[x1][y1]->player = 3;
					arr[x1][y1]->player_name = "  ";
				}
				if (flag == false)
				{
					cout << " you can't move in this index " << endl;
				}
			}
		}
	}
};
class king :public Piece
{
public:
	king(string x, int y)
	{
		player_name = x;
		player = y;
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			cout << " you cant move in this index" << endl;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if ((x2 == x1 + 1 && y2 == y1 + 1) || (x2 == x1 - 1 && y2 == y1 - 1) || (x2 == x1 && y2 == y1 + 1) || (x2 == x1 && y2 == y1 - 1) || (x2 == x1 + 1 && y2 == y1) || (x2 == x1 - 1 && y2 == y1) || (x2 == x1 + 1 && y2 == y1 - 1) || (x2 == x1 - 1 && y2 == y1 + 1))
			{
				for (int i = x1 + 1; i < x2; i++)
				{
					for (int j = y1 + 1; j < y2; j++)
					{
						if (arr[i][j]->player_name == "  ")
						{
							flag = true;
						}
						else
						{
							flag = false;
							break;
						}
					}
				}
				if (flag == true)
				{
					delete arr[x2][y2];
					arr[x2][y2] = new king(arr[x1][y1]->player_name, arr[x1][y1]->player);
					arr[x1][y1]->player = 3;
					arr[x1][y1]->player_name = "  ";
				}
				if (flag == false)
				{
					cout << " you can't move in this index " << endl;
				}
			}
		}
	}
};
class pawn :public Piece
{
public:
	pawn(string x, int y)
	{
		player_name = x;
		player = y;
	}
	virtual void move(Piece *arr[][8], int x1, int y1, int x2, int y2)
	{
		int num1 = abs(x1 - x2);
		int num2 = abs(y1 - y2);
		int num = arr[x1][y1]->player;
		if (arr[x1][y1]->player == arr[x2][y2]->player)
		{
			flag = false;
		}
		if (arr[x1][y1]->player != arr[x2][y2]->player)
		{
			if (num == 1)
			{
				if (((arr[x2][y2]->player == 3)) && ((x2 == x1 + 1) && (y2 == y1 + 1) || ((x2 == y2) || (num1 == num2))))
				{
					flag = true;
				}
				else if ((x1 == 1) && (x2 == x1 + 2) && (arr[x2][y2]->player == 3) || ((x2 == y2) || (num1 == num2)))
				{
					flag = true;
				}
				else if ((arr[x2][y2]->player == 2) && ((x2 == x1 + 2) || (x2 == x1 + 1)))
				{
					flag = false;
				}
				else if ((x1 != 1) && (x2 == x1 + 1))
				{
					flag = true;
				}
				else if ((x2 == x1 + 1) || ((x2 == y2) || (num1 == num2)))
				{
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
			else if (num == 2)
			{
				if (((arr[x2][y2]->player == 3)) && ((x2 == x1 - 1) && (y2 == y1 - 1)) || ((x2 == y2) || (num1 == num2)))
				{
					flag = true;
				}
				else if ((x1 == 6) && ((x2 == x1 - 2) || (x2 == x1 - 1)) && ((arr[x2][y2]->player == 3) || (arr[x2][y2]->player == 1)) || ((x2 == y2) || (num1 == num2)))
				{
					flag = true;
				}
				else if ((arr[x2][y2]->player == 1) && ((x2 == x1 - 2) || (x2 == x1 - 1)))
				{
					flag = false;
				}
				else if ((x1 != 6) && (x2 == x1 - 1))
				{
					flag = true;
				}
				else if ((x2 == x1 - 1) || ((x2 == y2) || (num1 == num2)))
				{
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				delete arr[x2][y2];
				arr[x2][y2] = new pawn(arr[x1][y1]->player_name, arr[x1][y1]->player);
				arr[x1][y1]->player = 3;
				arr[x1][y1]->player_name = "  ";
			}
			if (flag == false)
			{
				cout << " you can't move in this index " << endl;
			}
		}
	}
};
int main()
{
	int num_1, flag_1 = 0;
	int x1, y1, x2, y2 = 0;
	Piece*arr[8][8];
	arr[0][0] = new rock("R1", 1);
	arr[0][1] = new knight("N1", 1);
	arr[0][2] = new bishop("B1", 1);
	arr[0][3] = new queen("Q1", 1);
	arr[0][4] = new king("K1", 1);
	arr[0][5] = new bishop("B1", 1);
	arr[0][6] = new knight("N1", 1);
	arr[0][7] = new rock("R1", 1);
	for (int j = 0; j < 8; j++)
	{
		arr[1][j] = new pawn("P1", 1);
	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = new Piece("  ", 3);
		}
	}
	for (int j = 0; j < 8; j++)
	{
		arr[6][j] = new pawn("P2", 2);
	}
	arr[7][0] = new rock("R2", 2);
	arr[7][1] = new knight("N2", 2);
	arr[7][2] = new bishop("B2", 2);
	arr[7][3] = new queen("Q2", 2);
	arr[7][4] = new king("K2", 2);
	arr[7][5] = new bishop("B2", 2);
	arr[7][6] = new knight("N2", 2);
	arr[7][7] = new rock("R2", 2);
	print(arr);
	cout << "enter 1 to proceed and 2 to exit" << endl;
	cin >> num_1;
	while (1)
	{
		int flag_3 = turn();
		if (flag_3 == 1)
			cout << "player 1 turn " << endl;
		else
			cout << "player 2 turn " << endl;
		check_condition(x1, y1, x2, y2);
		if (arr[x1][y1]->player == 1)
		{
			arr[x1][y1]->move(arr, x1, y1, x2, y2);
			if (flag == false)
			{
				check_condition(x1, y1, x2, y2);
				if (arr[x1][y1]->player == 1)
				{
					arr[x1][y1]->move(arr, x1, y1, x2, y2);
				}
				else
				{
					cout << "error: invalid indexes " << endl;
				}
			}
			print(arr);
		}
		if (arr[x1][y1]->player == 2)
		{
			arr[x1][y1]->move(arr, x1, y1, x2, y2);
			if (flag == false)
			{
				check_condition(x1, y1, x2, y2);
				if (arr[x1][y1]->player == 2)
				{
					arr[x1][y1]->move(arr, x1, y1, x2, y2);
				}
				else
				{
					cout << "error: invalid indexes " << endl;
				}
			}
			print(arr);
		}
		if (num_1 == 2)
		{
			break;
		}
	}
	system("pause");
	return 0;
}
