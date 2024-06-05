#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <string>
using namespace std;

const int Easy = 15;
const int Medium = 10;
const int Hard = 5;
void printMenu()
{
    cout << "___________________________________\n";
    cout << "Welcome To Number The Guessing Game\n";
    cout << "     Guess The Number And Win:     \n";
    cout << "_____________|NOTHING|_____________\n";
}

void printMenuDif()
{
    cout << "___________________________________\n";
    cout << "            Difficulty:            \n";
    cout << "         Easy   = 15 tries         \n";
    cout << "         Medium = 10 tries         \n";
    cout << "         Hard   = 5 tries          \n";
    cout << "___________________________________\n";
}

bool checkGuess(const int guess, const int value)
{
    if (guess < value)
    {
        cout << "___________________________________\n";
        cout << "\n             Go Higher!            \n";
        return true;
    }
    else if (guess > value)
    {
        cout << "__________________________________\n";
        cout << "\n             Go Lower!             \n";
        return true;
    }
    return false;
}

bool errorCondition(string difficulty)
{
    if (difficulty == "easy" || difficulty == "medium" || difficulty == "hard")
    {
        return false;
    }
    return true;
}

bool validGuess(string guess)
{
    for (int i = 0; i < guess.length(); i++)
    {
        if (guess[i] < '0' || guess[i] > '9')
        {
            return true;
        }
    }
    return false;
}

int howDifficult()
{
    string difficulty;
    do
    {
        printMenuDif();
        cout << "\nEnter The Difficulty Level:\n";
        cin >> difficulty;

        for (auto &i : difficulty)
        {
            i = tolower(i);
        }

        if (difficulty == "easy")
        {
            return Easy;
        }
        else if (difficulty == "medium")
        {
            return Medium;
        }
        else if (difficulty == "hard")
        {
            return Hard;
        }
        else
        {
            cout << "\nPlease Enter Valid Difficulty.\n";
        }
    } while (errorCondition(difficulty) || difficulty.empty());
    return 0;
}

int inputGuess()
{
    string guess;
    do
    {
        cin >> guess;
        if (validGuess(guess))
        {
            cout << "\nInvalid! Enter Value From 1-100.\n";
        }
    } while (validGuess(guess));

    return stoi(guess);
}

void guessTheValue(const int value)
{
    int guess, difficulty, count = 0;

    printMenu();
    difficulty = howDifficult();

    do
    {
        cout << "        You Have " << (difficulty - count) << " Tries.        \n";
        cout << "___________________________________\n";
        cout << "\nEnter Your Guess:\n";
        guess = inputGuess();
        count++;
    } while (checkGuess(guess, value) && (count < difficulty));

    if (guess == value)
    {
        cout << "___________________________________\n";
        cout << "\n        CONGRATULATIONS !!!        \n";
        cout << " You Guessed The Value in " << count << "th Try.\n";
        cout << "___________________________________\n";
    }
    else
    {
        cout << "   You Couldn't Guess The Value.   \n";
    }
}

int main()
{
    int value;
    srand(time(0));
    value = rand() % 100 + 1;
    guessTheValue(value);
    cout << "\nPress Any Key To Exit.";
    getch();
    return 0;
}