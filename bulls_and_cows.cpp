#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

int generate_start_number() // проверяет, чтобы числа были разными
{
	int correct_number = rand() % 10000;
	bool b = false;
	while (! b)
	{
		if ((correct_number / 1000) != ((correct_number / 100) % 10) && 
			(correct_number / 1000) != ((correct_number % 100) / 10) && 
			(correct_number / 1000) != (correct_number % 10) && 
			((correct_number / 100) % 10) != ((correct_number % 100) / 10) && 
			((correct_number / 100) % 10) != (correct_number % 10) && 
			((correct_number % 100) / 10) != (correct_number % 10) && 
			correct_number >= 1000)
		{
			b = true;
		}
		else
		{
			correct_number = rand() % 10000;
		}
	}
	return correct_number;
}

int cows(int correct_number, int my_number) 
{
	int cows_counter;
	cows_counter = 0;
	if ((correct_number / 1000) == (my_number / 1000) ||
		(correct_number / 1000) == ((my_number / 100) % 10) ||
		(correct_number / 1000) == ((my_number % 100) / 10) ||
		(correct_number / 1000) == (my_number % 10))
	{
		cows_counter++;
	}
	if (((correct_number / 100) % 10) == (my_number / 1000) ||
		((correct_number / 100) % 10) == ((my_number / 100) % 10) ||
		((correct_number / 100) % 10) == ((my_number % 100) / 10) ||
		((correct_number / 100) % 10) == (my_number % 10))
	{
		cows_counter++;
	}
	if (((correct_number % 100) / 10) == (my_number / 1000) ||
		((correct_number % 100) / 10) == ((my_number / 100) % 10) ||
		((correct_number % 100) / 10) == ((my_number % 100) / 10) ||
		((correct_number % 100) / 10) == (my_number % 10))
	{
		cows_counter++;
	}
	if ((correct_number % 10) == (my_number / 1000) ||
		(correct_number % 10) == ((my_number / 100) % 10) ||
		(correct_number % 10) == ((my_number % 100) / 10) ||
		(correct_number % 10) == (my_number % 10))
	{
		cows_counter++;
	}
	return cows_counter;
}

int bulls(int correct_number, int my_number)
{
	int bulls_counter;
	bulls_counter = 0;
	if ((correct_number / 1000) == (my_number / 1000))
	{
		bulls_counter++;
	}
	if (((correct_number / 100) % 10) == ((my_number / 100) % 10))
	{
		bulls_counter++;
	}
	if (((correct_number % 100) / 10) == ((my_number % 100) / 10))
	{
		bulls_counter++;
	}
	if ((correct_number % 10) == (my_number % 10))
	{
		bulls_counter++;
	}
	return bulls_counter;
}

void Game_new(int correct_number)
{
	int my_number;
	bool win, correct;
	win = false;
	correct = false;
	system("CLS");
	cout << "The specified number, good luck!" << endl;
	//printf("The specified number:%d\n",x);
	do
	{
		do
		{
			cout << "Enter number: ";
			cin >> my_number;
			if ((my_number >= 1000) && (my_number <= 9999))
				correct = true;
			else
				cout << "Error!Incorrect number!" << endl;
		} while (correct == false);
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Bulls:" << bulls(correct_number, my_number);
		cout << "  Cows:" << cows(correct_number, my_number) << endl;
		if (my_number == correct_number)
			win = true;
	} while (win == false);
	cout << "++++++++++++++++++++++++++++++Achievement+++++++++++++++++++++++++++++++++++++" << endl;
	system("PAUSE");
}

void New_game_easy(int correct_number)
{
	int my_number;
	bool win, correct;
	win = false;
	correct = false;
	system("CLS");
	cout << "The specified number:" << correct_number << endl;
	do {
		do {
			cout << "Enter number:";
			cin >> my_number;
			if ((my_number >= 1000) && (my_number <= 9999))
				correct = true;
			else
				cout << "Error!Incorrect number!" << endl;
		} while (correct == false);
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Bulls:" << bulls(correct_number, my_number);
		cout << "  Cows:" << cows(correct_number, my_number) << endl;
		if (my_number == correct_number)
			win = true;
	} while (win == false);
	cout << "+++++++++++++++++++++++++++++++Achievement++++++++++++++++++++++++++++++++++++++" << endl;
	system("PAUSE");
}

void New_game_hard(int correct_number)
{
	int my_number, attempt;
	bool win, correct;
	win = false;
	correct = false;
	attempt = 1;
	system("CLS");
	cout << "The number set you have 5 attempts, good luck!" << endl;
	//printf("The specified number:%d\n",x);
	do
	{
		cout << "Attempt:" << endl; 
		cout << attempt;
		do
		{
			cout << "Enter the number:" << endl;
			cin >> my_number;
			if ((my_number >= 1000) && (my_number <= 9999))
				correct = true;
			else
				cout << "Error!Incorrect number!" << endl;
		} while (correct == false);
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Bulls:" << bulls(correct_number, my_number);
		cout << "  Cows:" << cows(correct_number, my_number) << endl;
		if (my_number == correct_number)
			win = true;
		if (attempt == 5)break;
		attempt++;
	} while (win == false);
	if (my_number == correct_number)
		cout << "+++++++++++++++++++++++++++++++Achievement+++++++++++++++++++++++++++++++" << endl;
	if (attempt == 5)
		cout << "+++++++++++++++++++++++++++++++YUO LOSE++++++++++++++++++++++++++++++++++++" << endl;
	system("PAUSE");
}

void runTest ()
{
	assert(cows(1234, 4321) == 4);
	puts("Test 1 passed");
	assert(cows(4568, 2931) == 0);
	puts("Test 2 passed");
	assert(cows(1234, 8921) == 2);
	puts("Test 3 passed");
	assert(cows(1987, 1997) == 3);
	puts("Test 4 passed");
	assert(cows(1234, 4987) == 1);
	puts("Test 5 passed");
	assert(bulls(1234, 4321) == 0);
	puts("Test 6 passed");
	assert(bulls(1234, 1658) == 1);
	puts("Test 7 passed");
	assert(bulls(4895, 4823) == 2);
	puts("Test 8 passed");
	assert(bulls(1234, 1235) == 3);
	puts("Test 9 passed");
	assert(bulls(1234, 1234) == 4);
	puts("Test 10 passed");
	getch();
}

int main()
{
	int l, j;
	char c;
	srand(time(0));
	j = generate_start_number();
	
	while (1)
	{
		system("CLS");
		puts("  1 - New Game");
		puts("  2 - New Game (easy)");
		puts("  3 - New Game (hard)");
		puts("  4 - Test Game");
		puts("  0 - Exit");
		c = getch();
		
		switch (c)
		{
		case '1':Game_new(j);break;
		case '2':New_game_easy(j);break;
		case '3':New_game_hard(j);break;
		case '4':runTest();break;
		case '0':return 0;
		default: puts("Error!");
		}
	}
}


