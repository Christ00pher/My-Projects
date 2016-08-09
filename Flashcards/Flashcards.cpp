#include "Flashcards.h"
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::map;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::pair;


Flashcards::Flashcards()
{
    wrong_words.clear();
    correct_words.clear();
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    choice = BEGIN;
}

Flashcards::~Flashcards()
{
    all_words.clear();
    correct_words.clear();
    wrong_words.clear();
}

void Flashcards::Add()
{
    string polish, english; //word containers
    system("CLS");
    cout << "INSTRUCTION:\n";
    cout << "Polish word [SPACE] English word [ENTER]\n";
    cout << "Write 'end' to stop the loop\n\n";
    while (true)
    {
        polish = english = "";
        cin >> polish;

        if (polish == "end")
            break;

        cin >> english;
        all_words.insert(pair<string, string>(polish,english));
    }
}

void Flashcards::SaveToFile()
{
    ofstream file;
    file.open("flashcards.txt", ios::out);

    for (map<string, string>::iterator it = all_words.begin(); it != all_words.end(); it++)
        file << it->first << " " << it->second << endl;

    file.close();
}

void Flashcards::Menu()
{
    system("CLS");
    cout << "1. Show flashcards\n";
    cout << "2. Add new flashcards\n";
    cout << "3. Start asking\n";
    cout << "4. Load flashcards from file\n";
    cout << "5. Save flashcards to file\n";
    cout << "6. Delete flashcards from file\n";
    cout << "7. EXIT\n";
    cout << "Choice: ";
    cin >> choice;
}

void Flashcards::HandleInput()
{
    switch (choice)
    {
        case SHOW: ShowFlashcards(); break;
        case ADD: Add(); break;
        //case ASK: Question(); break;
        case LOAD: LoadFromFile(); break;
        case SAVE: SaveToFile(); break;
        case REMOVE: ClearFile(); break;
        case END: End(); break;
    }
}

void Flashcards::End() { choice = END; }


bool Flashcards::IsRunning()
{
    if (choice == END)
        return false;
    else
        return true;
}

void Flashcards::ShowFlashcards()
{
    int n = 1; //number of flashcards
    system("CLS");

    if (all_words.empty())
        cout << "There are no flashcards to show!\n\n";

    else
    {
        for (map<string, string>::iterator it = all_words.begin(); it != all_words.end(); it++)
        {
            cout << n << ") " << it->first << " " << it->second << endl;
            ++n;
        }
    }
    system("PAUSE");
}

void Flashcards::Question()
{

}

void Flashcards::Clear()
{
    system("CLS");
    char x;
    cout << "1. Remove flashcards from helper sets (correct, wrong)\n";
    cout << "2. Remove flashcards from all 3 sets (all, correct, wrong)\n";
    cin >> x;


}

void Flashcards::LoadFromFile()
{
    ifstream file;
    string polish,english; //auxiliary variables to store words from the file
    file.open("flashcards.txt", ios::in);
    while (!file.eof())
    {
        polish = english = "";
        file >> polish;
        file >> english;
        if (polish != "" && english != "")
            all_words.insert(pair<string, string>(polish,english));
    }
    file.close();
}

void Flashcards::ClearFile()
{
    ofstream file;
    file.open("flashcards.txt", ios::out);
    file << "";
    file.close();
}
