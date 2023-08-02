#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#define AMOUNT_OF_KNOWN_LETTERS_IN_THE_WORD 2
using namespace std;

int Intoduction()
{
    int difficulty;

    while (true)
    {
        try
        {
            cout << "Hello! Choose the game difficulty:\n 1. easy \n 2. average \n 3. hard" << endl;
            cout << "Chosen difficulty -- ";
            cin >> difficulty;

            if (cin.fail())
                throw runtime_error("Invalid input. Please enter a valid number.");

            if (difficulty < 1 || difficulty > 3)
                throw runtime_error("Invalid input. Please choose a valid difficulty (1, 2, or 3).");

            break;
        }
        catch (const exception& e)
        {
            system("cls");
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
   
    return difficulty;
}

vector<string> EasyWords;
vector<string> AveWords;
vector<string> HardWords;

string easy(int number)
{
    EasyWords = { "apple", "pineapple", "impose", "strife", "disrupt", "gamut", "booth"};
    return EasyWords[number];
}

string average(int number)
{
    AveWords = { "pyramid", "triangle", "enlighten", "genuinely", "benevolent", "guesstimate"};
    return AveWords[number];
}

string hard(int number)
{
    HardWords = { "Tremendous", "polymorphism", "particularly", "appalling", "baffle", "divination"};
    return HardWords[number];
}

string distribution(int difficulty)
{
    int number;
    switch (difficulty)
    {
    case 1:
         number = rand() % 6;
        return easy(number);
        break;
    case 2:
         number = rand() % 6;
        return average(number);
        break;
    case 3:
         number = rand() % 6;
        return hard(number);
        break;
    }
}

int main()
{
    srand(time(nullptr));
    string word = distribution(Intoduction());
    system("cls");
    cout << "Guess the word!" << endl;
    int size = word.size();
    vector<string> unknown(word.size(), "-");

    for (int i = 0; i < AMOUNT_OF_KNOWN_LETTERS_IN_THE_WORD; ++i)
    {
        int RandomKnownLetter = rand() % word.size();
        unknown[RandomKnownLetter] = word[RandomKnownLetter];
    }    

    for (int i = 0; i < size; ++i)
        cout << unknown[i];
    cout << endl;

    cout << endl;
    int t = 0;
    int amount_of_lifes = 10;
    do
    {
        if (amount_of_lifes <= 0)
        {
            system("cls");
            cout << "Ran out of lifes! Game over! Press any key to exit" << endl;
            system("pause");
            exit(0);
        }
       
        char ch;
        cout << "Inputed letter -- ";
        cin >> ch;

        for (int i = 0; i < size; ++i)
        {
            if (word[i] == ch)
            {
                system("cls");
                unknown[i] = ch;
                ++t;
                word[i] = ' ';
                break;
            }   
            else
            {
               if(i == size - 1)
                   --amount_of_lifes;
                system("cls");
            }
        }

        cout << "'" << ch << "' last letters: "<< word.size() - t << " remaining number of lives: " << amount_of_lifes << endl;
        for (int i = 0; i < size; ++i)
            cout << unknown[i];
        cout << endl;
        
    } while (t < word.size() - AMOUNT_OF_KNOWN_LETTERS_IN_THE_WORD);

    system("cls");
    cout << "Congratulation!" << endl;
    return 0;
}
