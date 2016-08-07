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
    string s1,s2; //auxiliary variables to store words from the file
    file.open("flashcards.txt", ios::in);
    while (!file.eof())
    {
        s1 = s2 = "";
        file >> s1;
        file >> s2;
        all_words.insert(pair<string, string>(s1,s2));
    }
    wrong_words.clear();
    correct_words.clear();
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
    case (char)SHOW: ShowFlashcards(); break;
    case (char)ADD: Add(); break;
    }
}


bool Flashcards::IsRunning()
{
    if (choice == '0')
        return false;
    else
        return true;
}

void Flashcards::ShowFlashcards() {}
