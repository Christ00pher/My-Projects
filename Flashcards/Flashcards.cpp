#include "Flashcards.h"
#include <map>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::map;
using std::endl;
using std::ofstream;
using std::ios;


Flashcards::Flashcards() {}

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
}
