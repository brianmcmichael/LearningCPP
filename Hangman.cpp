//Hangman


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	//setup
	const int MAX_WRONG = 8;  //maximum number of incorrect guesses allowed

	vector<string> words; //collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];	//words to guess
	int wrong = 0;						//number of incorrect guesses
	string soFar(THE_WORD.size(), '-');	//words guessed so far
	string used = "";					//letters already guessed

	cout << "Welcome to Hangman. Good luck!\n";

	//main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << "incorrect guesses left.\n";
		cout << "nYou've used the following letting:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;

		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); //nake uppercase since secret word in uppercase
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "\n\nEnter you guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//update soFar to include newly guessed letter
			for (unsigned int i = 0; i < THE_WORD.length(); i++)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't the word.\n";
			++wrong;
		}

		//shut down
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been hanged!";
		}
		else
		{
			cout << "\nYou've guessed it.";
		}

		cout << "\nThe word was " << THE_WORD << endl;

		cin.get();

		return 0;


	}
}

