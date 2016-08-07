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
    wrong_words.clear();
    correct_words.clear();
    choice = BEGIN;
    file.close();
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
    cout << "4. Save flashcards to file\n";
    cout << "5. Delete flashcards from file\n";
    cout << "6. EXIT\n";
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
        case SAVE: SaveToFile(); break;
        //case REMOVE: Remove(); break;
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

    if (!all_words.empty())
    {
        for (map<string, string>::iterator it = all_words.begin(); it != all_words.end(); it++)
        {
            cout << n << ") " << it->first << " " << it->second << endl;
            ++n;
        }
    }
    system("PAUSE");
}
