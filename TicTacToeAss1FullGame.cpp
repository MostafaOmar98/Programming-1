//============================================================================
// Name        : TicTacToeAss1FullGame 2 Players and AI Version.
// Author      : Mostafa Omar Mahmoud El-Sayed
// ID	       : 20170292
//============================================================================

#include <bits/stdc++.h>
using namespace std;
void PrintGrid(char grid[3][3]);
bool win(char grid[3][3]);
bool WinMove(char grid[3][3], char& num, int& x, int& y, set<char> ai, set<pair<int, int> > coordinates);
bool NotLoseMove(char grid[3][3], char& num, int& x, int& y, set<char> ai, set<pair<int, int> > coordinates, set<char> player);
bool EvenValidation(char num, set<char> player);
bool OddValidation(char num, set<char> player);

int main() {
	string twoplayers;
	cout << "Do you want to play two players? (Type Yes or No): ";
	cin >> twoplayers;
	cout << endl;
	for (int i = 0; i < (int)twoplayers.size(); ++i)
		twoplayers[i] = tolower(twoplayers[i]);
	if (twoplayers == "yes")
	{
		char grid[3][3] = {""};
		PrintGrid(grid);
		set<char> p1, p2; // sets represent available numbers for players to choose from
		set<pair<int, int> > coordinates; // USED coordinates, cannot be picked
		for (int i = '1'; i <= '9'; i += 2)
			p1.insert(i);
		for (int i = '0'; i <= '8'; i+=2)
			p2.insert(i);
		int turn = 1; // p1 = 1, p2 = -1
		int moves = 0;
		while (!win(grid) && moves < 9)
		{
			int x, y; // coordinates
			pair<int, int> temp;
			if (turn == 1) // p1
			{
				char num;
				do
				{
					cout << "Enter Number [";
					for (set<char>::iterator it = p1.begin(); it !=p1.end(); it++)
					{
						set<char>::iterator itcheck = it;
						itcheck++;
						if (itcheck == p1.end())
							cout << *it;
						else
							cout << *it << ", ";
					}
					cout << "]: ";
					cin >> num;
				}
				while (num > '9' || num < '0' || (num - '0')%2 == 0 ||p1.find(num) == p1.end() || !isdigit(num));
				do
				{
					cout << "Enter Empty Block Coordinates (x,y) ([1~3], [1~3]): ";
					cin >> x >> y;
					temp = make_pair(x, y);
				}
				while (x > 3 || y > 3 || x < 0 || y < 0 || coordinates.find(temp) != coordinates.end());
				grid[x-1][y-1] = num;
				p1.erase(num); // make number not usable anymore
			}
			else if (turn == -1) // p2
			{
				char num;
				do
				{
					cout << "Enter Number [";
					for (set<char>::iterator it = p2.begin(); it !=p2.end(); it++)
					{
						set<char>::iterator itcheck = it;
						itcheck++;
						if (itcheck == p2.end())
							cout << *it;
						else
							cout << *it << ", ";
					}
					cout << "]: ";
					cin >> num;
				}
				while (num > '8' || num < '0' || (num - '0')%2 == 1|| p2.find(num) == p2.end() || !isdigit(num));
				do
				{
					cout << "Enter Empty Block Coordinates (x,y) ([1~3], [1~3]): ";
					cin >> x >> y;
					temp = make_pair(x, y);
				}
				while (x > 3 || y > 3 || x < 0 || y < 0 || coordinates.find(temp) != coordinates.end());
				grid[x-1][y-1] = num;
				p2.erase(num); // make number not usable anymore
			}
			coordinates.insert(temp);
			PrintGrid(grid);
			turn *= -1;
			++moves;
		}
		if (!win(grid))
			cout << "Tie" << endl;
		else
		{
			if (turn *-1 == 1)
				cout << "Player 1 win" << endl;
			else
				cout << "Player 2 win" << endl;
		}

	}
	else
	{
		char grid[3][3] = {""};
		set<char> player, ai; // sets represent available numbers for players to choose from
		set<pair<int, int> > coordinates; // USED coordinates, cannot be picked
		string choice;
		cout << "Type: 'Even' or 'odd' without the quotes: ";
		cin >> choice;
		cout << endl;
		PrintGrid(grid);
		for (int i = 0; i < (int)choice.size(); ++i)
		{
			choice[i] = tolower(choice[i]);
		}
		int turn;
		if (choice == "odd")
		{
			for (int i = '1'; i <= '9'; i += 2)
				player.insert(i);
			for (int i = '0'; i <= '8'; i+=2)
				ai.insert(i);
			turn = 1;
		}
		else if (choice == "even")
		{
			for (int i = '1'; i <= '9'; i += 2)
				ai.insert(i);
			for (int i = '0'; i <= '8'; i+=2)
				player.insert(i);
			turn = -1;
		}
		int moves = 0;
		while (!win(grid) && moves < 9)
		{
			int x,  y; // coordinates
			pair<int, int> temp;
			if (turn == 1) // player
			{
				char num;
				if (choice == "odd")
				{
					do
					{
						cout << "Enter Number [";
						for (set<char>::iterator it = player.begin(); it !=player.end(); it++)
						{
							set<char>::iterator itcheck = it;
							itcheck++;
							if (itcheck == player.end())
								cout << *it;
							else
								cout << *it << ", ";
						}
						cout << "]: ";
						cin >> num;
					}
					while (!OddValidation(num, player));
				}
				else
				{
					do
					{
						cout << "Enter Number [";
						for (set<char>::iterator it = player.begin(); it !=player.end(); it++)
						{
							set<char>::iterator itcheck = it;
							itcheck++;
							if (itcheck == player.end())
								cout << *it;
							else
								cout << *it << ", ";
						}
						cout << "]: ";
						cin >> num;
					}
					while (!EvenValidation(num, player));

				}
				do
				{
					cout << "Enter Empty Block Coordinates (x,y) ([1~3], [1~3]): ";
					cin >> x >> y;
					temp = make_pair(x, y);
				}
				while (x > 3 || y > 3 || x < 0 || y < 0 || coordinates.find(temp) != coordinates.end());
				grid[x-1][y-1] = num;
				player.erase(num); // make number not usable anymore
			}
			else if (turn == -1) // ai
			{
				char num;
				if (WinMove(grid ,num, x, y, ai, coordinates))
				{
					grid[x-1][y-1] = num;
				}
				else if (NotLoseMove(grid, num, x, y, ai, coordinates, player))
				{
					grid[x-1][y-1] = num;
				}
				else
				{
					for (int i = 0; i < 3; ++i)
					{
						for (int j = 0; j < 3; ++j)
						{
							temp = make_pair(i+1, j+1);
							if (coordinates.find(temp) == coordinates.end())
							{
								x = i+1;
								y = j+1;
								break;
							}
						}
					}
					num = *ai.begin();
					grid[x-1][y-1] = num;
				}
				temp = make_pair(x, y);
				ai.erase(num); // make number not usable anymore
				cout << "The bot played " << num << " in coordinates (" << x << " , " << y << ")" << endl;
			}
			coordinates.insert(temp);
			PrintGrid(grid);
			turn *= -1;
			++moves;
		}
		if (!win(grid))
			cout << "Tie" << endl;
		else
		{
			if (turn *-1 == 1)
				cout << "You Win" << endl;
			else
				cout << "You Lose" << endl;
		}

	}
	return 0;
}

void PrintGrid(char grid[3][3])
{
	cout << endl;
	for (int i = 0; i < 3; ++i) // row
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (k == 1)
					cout << grid[i][j];
				else
					cout << " ";
			}
			if (j != 2)
				cout << "*";
		}
		cout << endl << endl;
	}
	cout << endl;
}
bool win(char grid[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		bool fulline = true;
		int sum = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (isdigit(grid[i][j]))
				sum += grid[i][j] - '0';
			else
			{
				fulline = false;
				break;
			}
		}
		if (sum == 15 && fulline)
			return true;
	}
	for (int i = 0; i < 3; ++i)
	{
		int sum = 0;
		bool fulline = true;
		for (int j = 0; j < 3; ++j)
		{
			if (isdigit(grid[j][i]))
				sum += grid[j][i] - '0';
			else
			{
				fulline = false;
				break;
			}
		}
		if (sum == 15 && fulline)
			return true;
	}
	if (isdigit(grid[0][0]) && isdigit(grid[1][1]) && isdigit(grid[2][2]))
	{
		if (grid[2][2] + grid[1][1] + grid[0][0] - 3 * '0' == 15)
			return true;
	}
	if (isdigit(grid[0][2]) && isdigit(grid[1][1]) && isdigit(grid[2][0]))
	{
		if (grid[0][2] + grid[1][1] + grid[2][0] - 3 * '0' == 15)
			return true;
	}
	return false;

}
bool WinMove(char grid[3][3], char& num, int& x, int& y, set<char> ai, set<pair<int, int> > coordinates)
{
	char original;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			original = grid[i][j];
			pair<int, int> temp = make_pair(i+1, j+1);
			if (coordinates.find(temp) == coordinates.end())
			{
				for (set<char>::iterator it = ai.begin(); it != ai.end(); it++)
				{
					grid[i][j] = *it;
//					cout << i << " " << j << endl;
					if (win(grid))
					{
						num = *it;
						x = i+1;
						y = j+1;
						return true;
					}
				}
			}
			grid[i][j] = original;
		}
	}
	return false;
}
bool NotLoseMove(char grid[3][3], char& num, int& x, int& y, set<char> ai, set<pair<int, int> > coordinates, set<char> player)
{
	char original;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			original = grid[i][j];
			pair<int, int> temp = make_pair (i+1, j+1);
			if (coordinates.find(temp) == coordinates.end())
			{
				for (set<char>:: iterator it = player.begin(); it != player.end(); it++)
				{
					grid[i][j] = *it;
					if (win(grid))
					{
						x = i+1;
						y = j+1;
						num = *ai.begin();
						return true;
					}
				}
			}
			grid[i][j] = original;
		}
	}
	return false;
}
bool EvenValidation(char num, set<char> player)
{
	if (num > '8' || num <'0' || (num - '0') % 2 == 1 || !isdigit(num) || player.find(num) == player.end())
		return false;
	return true;
}
bool OddValidation(char num, set<char> player)
{
	if (num < '0' || (num - '0')%2 == 0 || !isdigit(num) || player.find(num) == player.end())
		return false;
	return true;
}
