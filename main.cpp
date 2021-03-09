// Hangman - The classic game of hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <random>
#include <cstdlib>

using namespace std;

// Global Variables
char choice, guessChoice, guess, playAgain;
int wrong = 0;            
const int MAX_WRONG = 8;
string used = " ";
string SoFar;
// Possible Functions
char getChoice(char choice);  
char letterChoice(string word);
string wordChoice(string THE_WORD);
void instructions();
void wrapUp(string THE_WORD);

vector<string> words {"RIDDIKULUS", "OBLIVIATE", "SECTUMSEMPRA"
						"ALOHOMORA", "EXPELLIARMUS", "AGUAMENTI"
						"SONORUS", "WADDIWASI", "OPPUGNO"
						"BAUBILLIOUS", "BOMBARDA", "FIENDFYRE"};
	
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	instructions();
	
	int pick = (rand() % words.size());
	const string THE_WORD = words[pick];
	string wordSoFar(THE_WORD.size(), '-');
	
	while ((wrong < MAX_WRONG) && (wordSoFar != THE_WORD))
	{
		cout << "\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.";
		cout << "\nYou have used the following letters: " << used ;
		cout << "\n* The word is: " << SoFar << " *\n\n";

		// Get Letter or Word Choice
		getChoice(choice);

		// wordChoice(THE_WORD);
				
		if (THE_WORD.find(guess) != string::npos)   
		{	cout << "\nThat's right! " << guess << " is in the word.\n";
			// Update soFar to include newly guessed letter
			for (unsigned int i = 0; i < THE_WORD.length(); ++i)
			{
                if (THE_WORD[i] == guess)
				{
                    SoFar[i] = guess;
				}
			}
		}
		else
        {
        	cout << string(55, '-') << "\n";
            cout << "Sorry, that isn't in the word.\n";
            ++wrong;
        }
	}	
		// Wrap up
		wrapUp(THE_WORD);
	
	cout << "\n\n✫彡 End of Game ✫彡";
	return 0;
}
void instructions()
{
	cout << "✫彡 Hangman: Harry Potter Edition ✫彡\n\n";
	cout << "Instructions:";
	cout << "\nThe player can guess by letter, or attempt the whole word.";
	cout << "\nIn a game, the maximum number of incorrect guesses allowed";
	cout << "\nis 8, so be careful. Once the player is able to guess";
	cout << "\nthe correct answer, the player wins the game.\n";
	cout << string(55, '-') << "\n";
}
char getChoice(char choice)
{
	cout << "Would you like to guess a letter(L) or the word(W): ";
	cin >> choice;
	choice = toupper(choice);
	while (choice != 'L' && choice != 'W')
	{	cout << "\nInvalid choice – please enter ‘L’ or ‘W’ : ";
		cout << "\n Choice:  ";
		cin.ignore(256,'\n');
		cin >> choice;
		choice = toupper(choice);
	}
	if (choice == 'L')
	{
		cout << "\nEnter your letter guess: ";
		cin >> guess;
		guess = toupper(guess);
	
	while (used.find(guess) != string::npos)
	{	cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter another guess: ";
		cin >> guess;
		guess = toupper(guess);
	}
	used += guess;
	return guess;
	}
	return choice;
}
char letterChoice(string word)
{
	cout << "\nEnter your letter guess: ";
	cin >> guess;
	guess = toupper(guess);

	while (used.find(guess) != string::npos)
	{	cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter another guess: ";
		cin >> guess;
		guess = toupper(guess);
	}
	used += guess;
	return guess;
}
string wordChoice(string THE_WORD)
{
	string guess;
	cout << "\n\n* If entering two words, use '_' between words *";
	cout << "\nEnter your word guess: ";
	cin >> guess;
	for (auto & c: guess)
	{	c = toupper(c);			}
	
	if (guess == THE_WORD)
	{	SoFar = THE_WORD;		}
	
	return SoFar;
}
void wrapUp(string THE_WORD)
{	if  (wrong == MAX_WRONG)
   	{	cout << "\nYou've been hanged!";      }
    else
   	{	cout << "\nYou got it!";          }
    
   	 cout << "\nThe word was " << THE_WORD << endl;
}