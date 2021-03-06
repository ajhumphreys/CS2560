// Andrew Humphreys CS 2560
// Homework 4 Problem 1

#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Die
{
private:
	int sides;	// Number of Sides
	int value;	// The die's value

public:
	Die(int);	// Constructor
	void roll();	// Rolls the die
	int getSides();	// Returns the number of sides
	int getValue();	// Returns the die's value
};

Die::Die(int s)
{
	// Get the system time
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);
	
	// Set the number of sides.
	sides = s;
	
	// Perform an initial roll.
	roll();
}

void Die::roll()
{
	const int MIN_VALUE = 1;	// Minimum die value

	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

int Die::getSides()
{
	return sides;
}

int Die::getValue()
{
	return value;
}

char GetChoice(string prompt);
int MaxInts(int int1, int int2);

int main()
{
	Die die1(6);	// Class for first die
	Die die2(6);	// Class for second die

	string playPrompt = "\t21 DICE GAME \nWould you like to play? (Y/N): ";		// Prompt to ask if user wants to play
	string rollPrompt = "Would you like to roll the dice? (Y/N): ";				// Prompt to ask if user wants to roll dice

	int comScore;		// Computer's Score
	int playerScore;	// Player's Score
	bool comBust;		// True if computer's score is over max score
	bool playerBust;	// True if player's score is over max score

	int winner;		// Integer that holds -1 for both bust, 0 for tie, 1 for player win, and 2 for computer win

	const int MAX_SCORE = 21;	// Maximum score for game
	const int MAX_D_HIT = 16;	// If the dealer has this score or less it will roll again

	char playChoice = 'y';		// Used to run program if user wants to play
	char rollChoice = 'y';		// Used to roll dice if user chooses to

	// Loop that lets the user play multiple games
	while (playChoice == 'y')
	{
		// Initializes scores to zero, roll choice to yes, and both of the bust variables to false
		comScore = 0;	
		playerScore = 0;
		rollChoice = 'y';
		comBust = false;
		playerBust = false;

		playChoice = GetChoice(playPrompt);

		if (playChoice == 'y') // User input yes, will play game
		{
			// First the program will get the computer's score. As the dealer, it must keep rolling if it does not have at least 16
			while (comScore <= MAX_D_HIT && comScore <= MAX_SCORE)
			{
				die1.roll();
				die2.roll();

				comScore = comScore + die1.getValue() + die2.getValue();
				if (comScore > MAX_SCORE)
				{
					comBust = true;
				}
			}


			// Loop that allows the user to roll until they choose to stop or they bust
			while (rollChoice == 'y' && playerScore <= MAX_SCORE)
			{
				rollChoice = GetChoice(rollPrompt);

				if (rollChoice == 'y')
				{
					die1.roll();
					die2.roll();

					playerScore = playerScore + die1.getValue() + die2.getValue();

					cout << "\nYou rolled a " << (die1.getValue() + die2.getValue()) << ".\n";
					cout << "Your score is: " << playerScore << endl << endl;
				}
				else if (rollChoice != 'n')
				{
					cout << "Error! Invalid Choice. Please Try Again.\n\n";
					rollChoice = 'y';
				}

				if (playerScore > MAX_SCORE)
				{
					playerBust = true;
				}
			}

			cout << "\nYour Score: " << playerScore << endl;
			cout << "Computer's Score: " << comScore << endl << endl;

			winner = MaxInts(playerScore, comScore);

			if (playerBust)
			{
				winner = 2;
			}
			else if (comBust)
			{
				winner = 1;
			}

			if (playerBust && comBust)
			{
				winner = -1;
			}

			switch (winner)
			{
			case -1:
				cout << "You and the Computer Both Bust! No Winner.\n\n";
				break;
			case 0:
				cout << "You and the Computer Tied.\n" << endl;
				break;
			case 1:
				cout << "You Have Beaten the Computer!\n" << endl;
				break;
			case 2:
				cout << "You Have Lost to the Computer!\n" << endl;
				break;
			}
		}
		else if (playChoice != 'n')	// User input invalid choice, will prompt again
		{
			cout << "Error! Invalid Choice. Please Try Again.\n\n";
			playChoice = 'y';
		}
	}

	return 0;
}

char GetChoice(string prompt)
{
	char choice;

	cout << prompt;
	cin.get(choice);
	cin.clear();
	cin.ignore(1000, '\n');

	return tolower(choice);
}

int MaxInts(int int1, int int2)
{
	int max = 0;

	if (int1 > int2)
	{
		max = 1;
	}
	else if (int1 < int2)
	{
		max = 2;
	}
	
	return max;
}

