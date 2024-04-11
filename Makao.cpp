#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct deck
{
	string figure;
	string color;
};

void CreateDeck(deck Card[52])
{
	int number = 2, c = 0;
	for (int j = 0; j < 4; j++)
	{
		number = 2;
		for (int i = 0; i < 13; i++)
		{
			if (j == 0)
			{
				Card[c].color = "C";
			}
			else if (j == 1)
			{
				Card[c].color = "D";
			}
			else if (j == 2)
			{
				Card[c].color = "H";
			}
			else if (j == 3)
			{
				Card[c].color = "S";
			}
			if (number == 11)
			{
				Card[c].figure = "J";
			}
			else if (number == 12)
			{
				Card[c].figure = "Q";
			}
			else if (number == 13)
			{
				Card[c].figure = "K";
			}
			else if (number == 14)
			{
				Card[c].figure = "A";
			}
			else if (number == 10)
			{
				Card[c].figure = "10";
			}
			else if (number < 10)
			{
				Card[c].figure = (char)(number + 48);
			}
			number++;
			c++;
		}
	}
}

void AdjustDeck(string& top_c, string& top_f, deck Card[52], vector<string> color1, vector<string> color2, vector<string> color3, vector<string> color4, vector<string> figure1, vector<string> figure2, vector<string> figure3, vector<string> figure4)
{
	for (int i = 0; i < 52; i++)
	{
		for (int a = 0; a < color1.size(); a++)
		{
			if (Card[i].color == color1[a])
			{
				if (Card[i].figure == figure1[a]) Card[i].color = "0";
			}
		}
		for (int b = 0; b < color2.size(); b++)
		{
			if (Card[i].color == color2[b])
			{
				if (Card[i].figure == figure2[b]) Card[i].color = "0";
			}

		}
		for (int c = 0; c < color3.size(); c++)
		{
			if (Card[i].color == color3[c])
			{
				if (Card[i].figure == figure3[c]) Card[i].color = "0";
			}

		}
		for (int d = 0; d < color4.size(); d++)
		{
			if (Card[i].color == color4[d])
			{
				if (Card[i].figure == figure4[d]) Card[i].color = "0";
			}

		}
		if (Card[i].color == top_c)
		{
			if (Card[i].figure == top_f) Card[i].color = "0";
		}
	}
}

void HowMany(string& top_c, string& top_f, deck Card[52], vector<string> color1, vector<string> color2, vector<string> color3, vector<string> color4, vector<string> figure1, vector<string> figure2, vector<string> figure3, vector<string> figure4)
{
	int count = 0;
	for (int i = 0; i < 52; i++)
	{
		if (Card[i].color == "0") count++;
	}
	if (count == 52) CreateDeck(Card);
	AdjustDeck(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
}

void OnCreate(string &top_c, string &top_f, deck Card[52], int players, vector<string> &color1, vector<string> &color2, vector<string> &color3, vector<string> &color4, vector<string> &figure1, vector<string> &figure2, vector<string> &figure3, vector<string> &figure4)
{
	int rnd = 0;
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			rnd = rand() % 52;
			if (Card[rnd].color == "0");
			else break;
		}
		color1.push_back(Card[rnd].color);
		figure1.push_back(Card[rnd].figure);
		Card[rnd].color = "0";
	}
	if (players >= 2)
	{
		for (int i = 0; i < 5; i++)
		{
			while (1)
			{
				rnd = rand() % 52;
				if (Card[rnd].color == "0");
				else break;
			}
			color2.push_back(Card[rnd].color);
			figure2.push_back(Card[rnd].figure);
			Card[rnd].color = "0";
		}
	}
	if (players >= 3)
	{
		for (int i = 0; i < 5; i++)
		{
			while (1)
			{
				rnd = rand() % 52;
				if (Card[rnd].color == "0");
				else break;
			}
			color3.push_back(Card[rnd].color);
			figure3.push_back(Card[rnd].figure);
			Card[rnd].color = "0";
		}
	}
	if (players == 4)
	{
		for (int i = 0; i < 5; i++)
		{
			while (1)
			{
				rnd = rand() % 52;
				if (Card[rnd].color == "0");
				else break;
			}
			color4.push_back(Card[rnd].color);
			figure4.push_back(Card[rnd].figure);
			Card[rnd].color = "0";
		}
	}
	while (1)
	{
		rnd = rand() % 52;
		if (Card[rnd].color == "0" || Card[rnd].figure == "2" || Card[rnd].figure == "3" || Card[rnd].figure == "4" || Card[rnd].figure == "Q" || Card[rnd].figure == "A");
		else break;
	}
	top_c = Card[rnd].color;
	top_f = Card[rnd].figure;
	Card[rnd].color = "0";
}

void MakaoCheck(string& top_c, string& top_f, deck Card[52], int makao, int turn, vector<string>& color1, vector<string>& color2, vector<string>& color3, vector<string>& color4, vector<string>& figure1, vector<string>& figure2, vector<string>& figure3, vector<string>& figure4)
{
	int rnd = 0;
	if (turn == 1)
	{
		if (color1.size() == 1 && makao == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				while (1)
				{
					rnd = rand() % 52;
					if (Card[rnd].color == "0");
					else break;
				}
				color1.push_back(Card[rnd].color);
				figure1.push_back(Card[rnd].figure);
				Card[rnd].color = "0";
				HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);

			}
		}
	}
	else if (turn == 2)
	{
		if (color2.size() == 1 && makao == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				while (1)
				{
					rnd = rand() % 52;
					if (Card[rnd].color == "0");
					else break;
				}
				color2.push_back(Card[rnd].color);
				figure2.push_back(Card[rnd].figure);
				Card[rnd].color = "0";
				HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);

			}
		}
	}
	else if (turn == 3)
	{
		if (color3.size() == 1 && makao == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				while (1)
				{
					rnd = rand() % 52;
					if (Card[rnd].color == "0");
					else break;
				}
				color3.push_back(Card[rnd].color);
				figure3.push_back(Card[rnd].figure);
				Card[rnd].color = "0";
				HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);

			}
		}
	}
	else if (turn == 4)
	{
		if (color4.size() == 1 && makao == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				while (1)
				{
					rnd = rand() % 52;
					if (Card[rnd].color == "0");
					else break;
				}
				color4.push_back(Card[rnd].color);
				figure4.push_back(Card[rnd].figure);
				Card[rnd].color = "0";
				HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);

			}
		}
	}
}

bool WinCondition(int turn, int players, vector<string> color1, vector<string> color2, vector<string> color3, vector<string> color4)
{
	if (players == 2)
	{
		if (color1.size() == 0 || color2.size() == 0) return true;
	}
	else if (players == 3)
	{
		if ((color1.size() == 0 && color2.size() == 0) || (color1.size() == 0 && color3.size() == 0) || (color2.size() == 0 && color3.size() == 0)) return true;
	}
	else if (players == 4)
	{
		if ((color1.size() == 0 && color2.size() == 0 && color3.size() == 0) || (color1.size() == 0 && color2.size() == 0 && color4.size() == 0) || (color1.size() == 0 && color3.size() == 0 && color4.size() == 0) || (color2.size() == 0 && color3.size() == 0 && color4.size() == 0)) return true;
	}
	else return false;
}

int CheckPossibility(int add, string demand, int turn, string top_c, string top_f, vector<string> color1, vector<string> color2, vector<string> color3, vector<string> color4, vector<string> figure1, vector<string> figure2, vector<string> figure3, vector<string> figure4)
{
	int possibilities = 0;
	if (turn == 1)
	{
		for (int i = 0; i < color1.size(); i++)
		{
			if (add != 0 && ((top_f == "2" && (figure1[i] == "2" || (color1[i] == top_c && figure1[i] == "3")) || (top_f == "3" && (figure1[i] == "3" || (color1[i] == top_c && figure1[i] == "2")))))) possibilities++;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color1[i] == top_c || figure1[i] == top_f)) possibilities++;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color1[i] == demand || figure1[i] == "A")) possibilities++;
				else if (top_f == "Q" || figure1[i] == "Q") possibilities++;
				else if (top_f != "A" && (color1[i] == top_c || figure1[i] == top_f)) possibilities++;
			}
		}
	}
	else if (turn == 2)
	{
		for (int i = 0; i < color2.size(); i++)
		{
			if (add !=0 && ((top_f == "2" && (figure2[i] == "2" || (color2[i] == top_c && figure2[i] == "3")) || (top_f == "3" && (figure2[i] == "3" || (color2[i] == top_c && figure2[i] == "2")))))) possibilities++;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color2[i] == top_c || figure2[i] == top_f)) possibilities++;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color2[i] == demand || figure2[i] == "A")) possibilities++;
				else if (top_f == "Q" || figure2[i] == "Q") possibilities++;
				else if (top_f != "A" && (color2[i] == top_c || figure2[i] == top_f)) possibilities++;
			}
		}
	}
	else if (turn == 3)
	{
		for (int i = 0; i < color3.size(); i++)
		{
			if (add!=0 && ((top_f == "2" && (figure3[i] == "2" || (color3[i] == top_c && figure3[i] == "3")) || (top_f == "3" && (figure3[i] == "3" || (color3[i] == top_c && figure3[i] == "2")))))) possibilities++;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color3[i] == top_c || figure3[i] == top_f)) possibilities++;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color3[i] == demand || figure3[i] == "A")) possibilities++;
				else if (top_f == "Q" || figure3[i] == "Q") possibilities++;
				else if (top_f != "A" && (color3[i] == top_c || figure3[i] == top_f)) possibilities++;
			}
		}
	}
	else if (turn == 4)
	{
		for (int i = 0; i < color4.size(); i++)
		{
			if (add!=0 && ((top_f == "2" && (figure4[i] == "2" || (color4[i] == top_c && figure4[i] == "3")) || (top_f == "3" && (figure4[i] == "3" || (color4[i] == top_c && figure4[i] == "2")))))) possibilities++;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color4[i] == top_c || figure4[i] == top_f)) possibilities++;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color4[i] == demand || figure4[i] == "A")) possibilities++;
				else if (top_f == "Q" || figure4[i] == "Q") possibilities++;
				else if (top_f != "A" && (color4[i] == top_c || figure4[i] == top_f)) possibilities++;
			}
		}
	}
	return possibilities;
}

int PlayMore(int turn, string top_f, vector<string> figure1, vector<string> figure2, vector<string> figure3, vector<string> figure4)
{
	int amount[3]={}, i=0;
	if (turn == 1)
	{
		for (int a = 0; a < figure1.size(); a++)
		{
			if (figure1[a] == top_f)
			{
				amount[i] = a + 1;
				i++;
			}
		}
	}
	else if (turn == 2)
	{
		for (int a = 0; a < figure2.size(); a++)
		{
			if (figure2[a] == top_f)
			{
				amount[i] = a + 1;
				i++;
			}
		}
	}
	else if (turn == 3)
	{
		for (int a = 0; a < figure3.size(); a++)
		{
			if (figure3[a] == top_f)
			{
				amount[i] = a + 1;
				i++;
			}
		}
	}
	else if (turn == 4)
	{
		for (int a = 0; a < figure4.size(); a++)
		{
			if (figure4[a] == top_f)
			{
				amount[i] = a + 1;
				i++;
			}
		}
	}
	if (i > 0)
	{
		cout << endl;
		cout << "You can play those cards (position): ";
		for (int e = 0; e < i; e++)
		{
			cout << amount[e] << " ";
		}
		cout << endl;
	}
	return i;
}

int CheckIfPossible(int add, int draw, string demand, int position, string& top_c, string& top_f, int turn, vector<string>& color1, vector<string>& color2, vector<string>& color3, vector<string>& color4, vector<string>& figure1, vector<string>& figure2, vector<string>& figure3, vector<string>& figure4)
{
	int allowed = 0;
	while (1)
	{
		if (turn == 1)
		{
			if (add != 0 && ((top_f == "2" && (figure1[position - 1] == "2" || (color1[position - 1] == top_c && figure1[position - 1] == "3")) || (top_f == "3" && (figure1[position - 1] == "3" || (color1[position - 1] == top_c && figure1[position - 1] == "2")))))) allowed = 1;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color1[position - 1] == top_c || figure1[position - 1] == top_f)) allowed = 1;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color1[position - 1] == demand || figure1[position - 1] == "A")) allowed = 1;
				else if (top_f == "Q" || figure1[position - 1] == "Q") allowed = 1;
				else if (top_f != "A" && (color1[position - 1] == top_c || figure1[position - 1] == top_f)) allowed = 1;
			}
		}
		else if (turn == 2)
		{
			if (add!=0 && ((top_f == "2" && (figure2[position - 1] == "2" || (color2[position - 1] == top_c && figure2[position - 1] == "3")) || (top_f == "3" && (figure2[position - 1] == "3" || (color2[position - 1] == top_c && figure2[position - 1] == "2")))))) allowed = 1;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color2[position - 1] == top_c || figure2[position - 1] == top_f)) allowed = 1;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color2[position - 1] == demand || figure2[position - 1] == "A")) allowed = 1;
				else if (top_f == "Q" || figure2[position - 1] == "Q") allowed = 1;
				else if (top_f != "A" && (color2[position - 1] == top_c || figure2[position - 1] == top_f)) allowed = 1;
			}
		}
		else if (turn == 3)
		{
			if (add!=0 && ((top_f == "2" && (figure3[position - 1] == "2" || (color3[position - 1] == top_c && figure3[position - 1] == "3")) || (top_f == "3" && (figure3[position - 1] == "3" || (color3[position - 1] == top_c && figure3[position - 1] == "2")))))) allowed = 1;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color3[position - 1] == top_c || figure3[position - 1] == top_f)) allowed = 1;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color3[position - 1] == demand || figure3[position - 1] == "A")) allowed = 1;
				else if (top_f == "Q" || figure3[position - 1] == "Q") allowed = 1;
				else if (top_f != "A" && (color3[position - 1] == top_c || figure3[position - 1] == top_f)) allowed = 1;
			}
		}
		else if (turn == 4)
		{
			if (add!=0 && ((top_f == "2" && (figure4[position - 1] == "2" || (color1[position - 1] == top_c && figure4[position - 1] == "3")) || (top_f == "3" && (figure4[position - 1] == "3" || (color4[position - 1] == top_c && figure4[position - 1] == "2")))))) allowed = 1;
			else if (add == 0 && (top_f == "2" || top_f == "3") && (color4[position - 1] == top_c || figure4[position - 1] == top_f)) allowed = 1;
			else if (top_f != "2" && top_f != "3")
			{
				if (top_f == "A" && (color4[position - 1] == demand || figure4[position - 1] == "A")) allowed = 1;
				else if (top_f == "Q" || figure4[position - 1] == "Q") allowed = 1;
				else if (top_f != "A" && (color4[position - 1] == top_c || figure4[position - 1] == top_f)) allowed = 1;
			}
		}
		if (allowed == 0 && draw == 0)
		{
			cout << "You cannot play this card, pick another one that matches either the color or the figure of the top card: ";
			cin >> position;
		}
		else break;
	}
	return allowed;
}

void PlayCard(int &add, string& demand, int position, string& top_c, string& top_f, deck Card[52], int turn, vector<string>& color1, vector<string>& color2, vector<string>& color3, vector<string>& color4, vector<string>& figure1, vector<string>& figure2, vector<string>& figure3, vector<string>& figure4)
{
	if (turn == 1)
	{
		top_c = color1[position - 1];
		top_f = figure1[position - 1];
		color1.erase(color1.begin() + position - 1);
		figure1.erase(figure1.begin() + position - 1);
		color1.shrink_to_fit();
		figure1.shrink_to_fit();
		if (top_f == "2") add += 2;
		if (top_f == "3") add += 3;
	}
	else if (turn == 2)
	{
		top_c = color2[position - 1];
		top_f = figure2[position - 1];
		color2.erase(color2.begin() + position - 1);
		figure2.erase(figure2.begin() + position - 1);
		color2.shrink_to_fit();
		figure2.shrink_to_fit();
		if (top_f == "2") add += 2;
		if (top_f == "3") add += 3;
	}
	else if (turn == 3)
	{
		top_c = color3[position - 1];
		top_f = figure3[position - 1];
		color3.erase(color3.begin() + position - 1);
		figure3.erase(figure3.begin() + position - 1);
		color3.shrink_to_fit();
		figure3.shrink_to_fit();
		if (top_f == "2") add += 2;
		if (top_f == "3") add += 3;
	}
	else if (turn == 4)
	{
		top_c = color4[position - 1];
		top_f = figure4[position - 1];
		color4.erase(color4.begin() + position - 1);
		figure4.erase(figure4.begin() + position - 1);
		color4.shrink_to_fit();
		figure4.shrink_to_fit();
		if (top_f == "2") add += 2;
		if (top_f == "3") add += 3;
	}
	if (top_f == "A")
	{
		cout << "What is your demand (color): ";
		cin >> demand;
	}
}

int Game(int &add, string &demand, int &draw, int& makao, int& turn, string& top_c, string& top_f, deck Card[52], int players, vector<string>& color1, vector<string>& color2, vector<string>& color3, vector<string>& color4, vector<string>& figure1, vector<string>& figure2, vector<string>& figure3, vector<string>& figure4)
{
	int rnd = 0, position = 0, more=0;
	string move, answer;
	draw = 0;
	cout << "Top card: " << top_c << top_f << endl;
	cout << "Your hand: ";
	if (turn == 1)
	{
		if (color1.size() != 0)
		{
			for (int i = 0; i < color1.size(); i++)
			{
				cout << color1[i] << figure1[i] << " ";
			}
			cout << endl;
			cout << "Player 1's move (there are " << CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) << " possible moves): ";
			cin >> move;
			while (1)
			{
				if (move == "quit") return 0;
				else if (move == "pass")
				{
					while (1)
					{
						rnd = rand() % 52;
						if (Card[rnd].color == "0");
						else
						{
							color1.push_back(Card[rnd].color);
							figure1.push_back(Card[rnd].figure);
							Card[rnd].color = "0";
							HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							position = color1.size();
							draw = 1;
							if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1)
							{
								cout << endl;
								cout << "Drawn card: " << color1[color1.size() - 1] << figure1[figure1.size() - 1] << endl;
								cout << "Do you want to play it? (Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N")
								{
									if (top_f == "2" || top_f == "3")
									{
										for (int i = 0; i < add; i++)
										{
											while (1)
											{
												rnd = rand() % 52;
												if (Card[rnd].color == "0");
												else break;
											}
											color1.push_back(Card[rnd].color);
											figure1.push_back(Card[rnd].figure);
											Card[rnd].color = "0";
											HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
										}
										add = 0;
									}
								}
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1)
							{
								if (top_f == "2" || top_f == "3")
								{
									for (int i = 0; i < add; i++)
									{
										while (1)
										{
											rnd = rand() % 52;
											if (Card[rnd].color == "0");
											else break;
										}
										color1.push_back(Card[rnd].color);
										figure1.push_back(Card[rnd].figure);
										Card[rnd].color = "0";
										HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
									}
									add = 0;
								}
							}
							break;
						}
					}
					break;
				}
				else if (move == "cheat")
				{
					system("CLS");
					cout << "Top card: " << top_c << top_f << endl;
					cout << "Your hand: ";
					for (int i = 0; i < color1.size(); i++)
					{
						cout << color1[i] << figure1[i] << " ";
					}
					cout << endl;
					cout << "Player 2's hand: ";
					for (int i = 0; i < color2.size(); i++)
					{
						cout << color2[i] << figure2[i] << " ";
					}
					cout << endl;
					cout << "Player 3's hand: ";
					for (int i = 0; i < color3.size(); i++)
					{
						cout << color3[i] << figure3[i] << " ";
					}
					cout << endl;
					cout << "Player 4's hand: ";
					for (int i = 0; i < color4.size(); i++)
					{
						cout << color4[i] << figure4[i] << " ";
					}
					cout << endl;
					cin >> move;
				}
				else if (move == "play")
				{
					if (CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 0)
					{
						cout << "Pick a card (number of position counting from left to right): ";
						cin >> position;
						while (1)
						{
							if (position > color1.size() || position < 0)
							{
								cout << "There isn't any card on this position, pick correct one: ";
								cin >> position;
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
						}
						PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
						more = PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
						if (more > 0)
						{
							for (int i = 0; i < more; i++)
							{
								cout << "Do you want to play a card? (Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									if (i > 0) PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
									cout << endl;
									cout << "What card do you want to play(position) : ";
									cin >> position;
									while (1)
									{
										cout << endl;
										if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
										else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
									}
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N") break;
							}
						}
						cout << endl;
						cout << "Do you want to end your turn? (Y/N): ";
						cin >> answer;
						if (answer == "Y") break;
						else if (answer == "N")
						{
							cout << "Call makao or end turn: ";
							cin >> move;
						}
						if (move == "makao")
						{
							while (1)
							{
								if (color1.size() != 1)
								{
									cout << "Incorrect move, try again: ";
									cin >> move;
									if (move != "makao") break;
								}
								else if (color1.size() == 1) break;
							}
							makao = 1;
							break;
						}
						else break;
					}
					else
					{
						if (top_f == "2" || top_f == "3")
						{
							for (int i = 0; i < add; i++)
							{
								while (1)
								{
									rnd = rand() % 52;
									if (Card[rnd].color == "0");
									else break;
								}
								color1.push_back(Card[rnd].color);
								figure1.push_back(Card[rnd].figure);
								Card[rnd].color = "0";
								HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							}
							add = 0;
						}
						else cout << "No play is possible, pick another option: ";
					}
					cin >> move;
				}
			}
		}
	}
	else if (turn == 2)
	{
		if (color2.size() != 0)
		{
			for (int i = 0; i < color2.size(); i++)
			{
				cout << color2[i] << figure2[i] << " ";
			}
			cout << endl;
			cout << "Player 2's move (there are " << CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) << " possible moves): ";
			cin >> move;
			while (1)
			{
				if (move == "quit") return 0;
				else if (move == "pass")
				{
					while (1)
					{
						rnd = rand() % 52;
						if (Card[rnd].color == "0");
						else
						{
							color2.push_back(Card[rnd].color);
							figure2.push_back(Card[rnd].figure);
							Card[rnd].color = "0";
							HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							position = color2.size();
							draw = 1;
							if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1)
							{
								cout << endl;
								cout << "Drawn card: " << color2[color2.size() - 1] << figure2[figure2.size() - 1] << endl;
								cout << "Do you want to play it? (Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									position = color2.size();
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N");
								{
									if (top_f == "2" || top_f == "3")
									{
										for (int i = 0; i < add; i++)
										{
											while (1)
											{
												rnd = rand() % 52;
												if (Card[rnd].color == "0");
												else break;
											}
											color2.push_back(Card[rnd].color);
											figure2.push_back(Card[rnd].figure);
											Card[rnd].color = "0";
											HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
										}
										add = 0;
									}
								}
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1)
							{
								if (top_f == "2" || top_f == "3")
								{
									for (int i = 0; i < add; i++)
									{
										while (1)
										{
											rnd = rand() % 52;
											if (Card[rnd].color == "0");
											else break;
										}
										color2.push_back(Card[rnd].color);
										figure2.push_back(Card[rnd].figure);
										Card[rnd].color = "0";
										HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
									}
									add = 0;
								}
							}
							break;
						}
					}
					break;
				}
				else if (move == "cheat")
				{
					system("CLS");
					cout << "Top card: " << top_c << top_f << endl;
					cout << "Your hand: ";
					for (int i = 0; i < color2.size(); i++)
					{
						cout << color2[i] << figure2[i] << " ";
					}
					cout << endl;
					cout << "Player 1's hand: ";
					for (int i = 0; i < color1.size(); i++)
					{
						cout << color1[i] << figure1[i] << " ";
					}
					cout << endl;
					cout << "Player 3's hand: ";
					for (int i = 0; i < color3.size(); i++)
					{
						cout << color3[i] << figure3[i] << " ";
					}
					cout << endl;
					cout << "Player 4's hand: ";
					for (int i = 0; i < color4.size(); i++)
					{
						cout << color4[i] << figure4[i] << " ";
					}
					cout << endl;
					cin >> move;
				}
				else if (move == "play")
				{
					if (CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 0)
					{
						cout << "Pick a card (number of position counting from left to right): ";
						cin >> position;
						while (1)
						{
							if (position > color2.size() || position < 0)
							{
								cout << "There isn't any card on this position, pick correct one: ";
								cin >> position;
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
						}
						PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
						more = PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
						if (more > 0)
						{
							for (int i = 0; i < more; i++)
							{
								cout << "Do you want to play a card?(Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									if(i>0) PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
									cout << endl;
									cout << "What card do you want to play(position) : ";
									cin >> position;
									while (1)
									{
										cout << endl;
										if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
										else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
									}
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N") break;
							}
						}
						cout << endl;
						cout << "Do you want to end your turn? (Y/N): ";
						cin >> answer;
						if (answer == "Y") break;
						else if (answer == "N")
						{
							cout << "Call makao or pass: ";
							cin >> move;
						}
						if (move == "makao")
						{
							while (1)
							{
								if (color2.size() != 1)
								{
									cout << "Incorrect move, try again: ";
									cin >> move;
									if (move != "makao") break;
								}
								else if (color2.size() == 1) break;
							}
							makao = 1;
							break;
						}
						else break;
					}
					else
					{
						if (top_f == "2" || top_f == "3")
						{
							for (int i = 0; i < add; i++)
							{
								while (1)
								{
									rnd = rand() % 52;
									if (Card[rnd].color == "0");
									else break;
								}
								color2.push_back(Card[rnd].color);
								figure2.push_back(Card[rnd].figure);
								Card[rnd].color = "0";
								HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							}
							add = 0;
						}
						else cout << "No play is possible, pick another option: ";
					}
					cin >> move;
				}
			}
		}
	}
	else if (turn == 3)
	{
		if (color3.size() != 0)
		{
			for (int i = 0; i < color3.size(); i++)
			{
				cout << color3[i] << figure3[i] << " ";
			}
			cout << endl;
			cout << "Player 3's move (there are " << CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) << " possible moves): ";
			cin >> move;
			while (1)
			{
				if (move == "quit") return 0;
				else if (move == "pass")
				{
					while (1)
					{
						rnd = rand() % 52;
						if (Card[rnd].color == "0");
						else
						{
							color3.push_back(Card[rnd].color);
							figure3.push_back(Card[rnd].figure);
							Card[rnd].color = "0";
							HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							position = color3.size();
							draw = 1;
							if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1)
							{
								cout << endl;
								cout << "Drawn card: " << color3[color3.size() - 1] << figure3[figure3.size() - 1] << endl;
								cout << "Do you want to play it? (Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									position = color3.size();
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N")
								{
									if (top_f == "2" || top_f == "3")
									{
										for (int i = 0; i < add; i++)
										{
											while (1)
											{
												rnd = rand() % 52;
												if (Card[rnd].color == "0");
												else break;
											}
											color3.push_back(Card[rnd].color);
											figure3.push_back(Card[rnd].figure);
											Card[rnd].color = "0";
											HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
										}
										add = 0;
									}
								}
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1)
							{
								if (top_f == "2" || top_f == "3")
								{
									for (int i = 0; i < add; i++)
									{
										while (1)
										{
											rnd = rand() % 52;
											if (Card[rnd].color == "0");
											else break;
										}
										color3.push_back(Card[rnd].color);
										figure3.push_back(Card[rnd].figure);
										Card[rnd].color = "0";
										HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
									}
									add = 0;
								}
							}
							break;
						}
					}
					break;
				}
				else if (move == "cheat")
				{
					system("CLS");
					cout << "Top card: " << top_c << top_f << endl;
					cout << "Your hand: ";
					for (int i = 0; i < color3.size(); i++)
					{
						cout << color3[i] << figure3[i] << " ";
					}
					cout << endl;
					cout << "Player 1's hand: ";
					for (int i = 0; i < color1.size(); i++)
					{
						cout << color1[i] << figure1[i] << " ";
					}
					cout << endl;
					cout << "Player 2's hand: ";
					for (int i = 0; i < color2.size(); i++)
					{
						cout << color2[i] << figure2[i] << " ";
					}
					cout << endl;
					cout << "Player 4's hand: ";
					for (int i = 0; i < color4.size(); i++)
					{
						cout << color4[i] << figure4[i] << " ";
					}
					cout << endl;
					cin >> move;
				}
				else if (move == "play")
				{
					if (CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 0)
					{
						cout << "Pick a card (number of position counting from left to right): ";
						cin >> position;
						while (1)
						{
							if (position > color3.size() || position < 0)
							{
								cout << "There isn't any card on this position, pick correct one: ";
								cin >> position;
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
						}
						PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
						more = PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
						if (more > 0)
						{
							cout << "Do you want to play a card?: ";
							cin >> answer;
							if (answer == "Y")
							{
								cout << endl;
								for (int i = 0; i < more; i++)
								{
									if (i > 0) PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
									cout << "What card do you want to play(position) : ";
									cin >> position;
									while (1)
									{
										cout << endl;
										if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
										else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
									}
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
							}
							else if (answer == "N") break;
						}
						cout << endl;
						cout << "Do you want to end your turn? (Y/N): ";
						cin >> answer;
						if (answer == "Y") break;
						else if (answer == "N")
						{
							cout << "Call makao or pass: ";
							cin >> move;
						}
						if (move == "makao")
						{
							while (1)
							{
								if (color3.size() != 1)
								{
									cout << "Incorrect move, try again: ";
									cin >> move;
									if (move != "makao") break;
								}
								else if (color3.size() == 1) break;
							}
							makao = 1;
							break;
						}
						else break;
					}
					else
					{
						if (top_f == "2" || top_f == "3")
						{
							for (int i = 0; i < add; i++)
							{
								while (1)
								{
									rnd = rand() % 52;
									if (Card[rnd].color == "0");
									else break;
								}
								color3.push_back(Card[rnd].color);
								figure3.push_back(Card[rnd].figure);
								Card[rnd].color = "0";
								HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							}
							add = 0;
						}
						else cout << "No play is possible, pick another option: ";
					}
					cin >> move;
				}
			}
		}
	}
	else if (turn == 4)
	{
		if (color4.size() != 0)
		{
			for (int i = 0; i < color4.size(); i++)
			{
				cout << color4[i] << figure4[i] << " ";
			}
			cout << endl;
			cout << "Player 4's move (there are " << CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) << " possible moves): ";
			cin >> move;
			while (1)
			{
				if (move == "quit") return 0;
				else if (move == "pass")
				{
					while (1)
					{
						rnd = rand() % 52;
						if (Card[rnd].color == "0");
						else
						{
							color4.push_back(Card[rnd].color);
							figure4.push_back(Card[rnd].figure);
							Card[rnd].color = "0";
							HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							position = color4.size();
							draw = 1;
							if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1)
							{
								cout << endl;
								cout << "Drawn card: " << color4[color4.size() - 1] << figure4[figure4.size() - 1] << endl;
								cout << "Do you want to play it? (Y/N): ";
								cin >> answer;
								if (answer == "Y")
								{
									position = color4.size();
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N")
								{
									if (top_f == "2" || top_f == "3")
									{
										for (int i = 0; i < add; i++)
										{
											while (1)
											{
												rnd = rand() % 52;
												if (Card[rnd].color == "0");
												else break;
											}
											color4.push_back(Card[rnd].color);
											figure4.push_back(Card[rnd].figure);
											Card[rnd].color = "0";
											HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
										}
										add = 0;
									}
								}
							}
							break;
						}
					}
					break;
				}
				else if (move == "cheat")
				{
					system("CLS");
					cout << "Top card: " << top_c << top_f << endl;
					cout << "Your hand: ";
					for (int i = 0; i < color4.size(); i++)
					{
						cout << color4[i] << figure4[i] << " ";
					}
					cout << endl;
					cout << "Player 1's hand: ";
					for (int i = 0; i < color1.size(); i++)
					{
						cout << color1[i] << figure1[i] << " ";
					}
					cout << endl;
					cout << "Player 2's hand: ";
					for (int i = 0; i < color2.size(); i++)
					{
						cout << color2[i] << figure2[i] << " ";
					}
					cout << endl;
					cout << "Player 3's hand: ";
					for (int i = 0; i < color3.size(); i++)
					{
						cout << color3[i] << figure3[i] << " ";
					}
					cout << endl;
					cin >> move;
				}
				else if (move == "play")
				{
					if (CheckPossibility(add, demand, turn, top_c, top_f, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 0)
					{
						cout << "Pick a card (number of position counting from left to right): ";
						cin >> position;
						while (1)
						{
							if (position > color4.size() || position < 0)
							{
								cout << "There isn't any card on this position, pick correct one: ";
								cin >> position;
							}
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
							else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
						}
						PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
						more = PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
						if (more > 0)
						{
							for (int i = 0; i < more; i++)
							{
								cout << "Do you want to play a card?: ";
								cin >> answer;
								if (answer == "Y")
								{
									if (i > 0) PlayMore(turn, top_f, figure1, figure2, figure3, figure4);
									cout << endl;
									cout << "What card do you want to play(position) : ";
									cin >> position;
									while (1)
									{
										cout << endl;
										if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) != 1);
										else if (CheckIfPossible(add, draw, demand, position, top_c, top_f, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4) == 1) break;
									}
									PlayCard(add, demand, position, top_c, top_f, Card, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
								}
								else if (answer == "N") break;
							}
						}
						cout << endl;
						cout << "Do you want to end your turn? (Y/N): ";
						cin >> answer;
						if (answer == "Y") break;
						else if (answer == "N")
						{
							cout << "Call makao or pass: ";
							cin >> move;
						}
						if (move == "makao")
						{
							while (1)
							{
								if (color4.size() != 1)
								{
									cout << "Incorrect move, try again: ";
									cin >> move;
									if (move != "makao") break;
								}
								else if (color4.size() == 1) break;
							}
							makao = 1;
							break;
						}
						else break;
					}
					else
					{
						if (top_f == "2" || top_f == "3")
						{
							for (int i = 0; i < add; i++)
							{
								while (1)
								{
									rnd = rand() % 52;
									if (Card[rnd].color == "0");
									else break;
								}
								color4.push_back(Card[rnd].color);
								figure4.push_back(Card[rnd].figure);
								Card[rnd].color = "0";
								HowMany(top_c, top_f, Card, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
							}
							add = 0;
						}
						else cout << "No play is possible, pick another option: ";
					}
					cin >> move;
				}
			}
		}
	}
	system("CLS");
}

int main()
{
	srand(time(NULL));
	int number = 2, c = 0, players = 0, turn = 0, makao=0, quit=1, draw=0, add=0;
	string top_c, top_f, option, demand;
	vector<string> color1;
	vector<string> color2;
	vector<string> color3;
	vector<string> color4;
	vector<string> figure1;
	vector<string> figure2;
	vector<string> figure3;
	vector<string> figure4;
	deck Card[52];
	CreateDeck(Card);
	cout << "Commands:" << endl;
	cout << "pass - end your turn and draw a card" << endl;
	cout << "cheat - reveal every player's hand" << endl;
	cout << "play - pick a card from your hand and put it on the stack" << endl;
	cout << "(Play exclusive option) makao - call it when you have one card left" << endl;
	cout << "quit - ends the game" << endl;
	cout << "regular or control game: ";
	cin >> option;
	if (option == "regular")
	{
		cout << "How many players? (2-4)" << endl;
		cin >> players;
		while (1)
		{

			if (players < 2 || players>4)
			{
				cout << "Wrong. Try again." << endl;
				cin >> players;
			}
			else break;
		}
		system("CLS");
		OnCreate(top_c, top_f, Card, players, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
		if (players == 2)
		{
			turn = rand() % 2 + 1;
		}
		else if (players == 3)
		{
			turn = rand() % 3 + 1;
		}
		else if (players == 4)
		{
			turn = rand() % 4 + 1;
		}
	}
	else if (option == "control")
	{
		players = 2;
		turn = 1;
		color1.push_back("C");
		figure1.push_back("2");
		Card[0].color = "0";
		top_c = "C";
		top_f = "3";
		Card[1].color = "0";
	}
	while (1)
	{
		quit=Game(add, demand, draw, makao, turn, top_c, top_f, Card, players, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
		if(option == "control") color2.clear();
		if (quit == 0) break;
		MakaoCheck(top_c, top_f, Card, makao, turn, color1, color2, color3, color4, figure1, figure2, figure3, figure4);
		if (WinCondition(turn, players, color1, color2, color3, color4) == true)
		{
			break;
		}
		if (players == 2)
		{
			if (turn == 1) turn++;
			else if (turn == 2) turn--;
		}
		else if (players == 3)
		{
			if (turn == 3) turn = 1;
			else turn++;
		}
		else if (players == 4)
		{
			if (turn == 4) turn = 1;
			else turn++;
		}
	}
	cout << endl;
	cout << "Good game" << endl;
	cout << endl;
	return 0;
}