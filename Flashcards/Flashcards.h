#pragma once
#include <map>
#include <string>

class Flashcards
{
private:
    std::map<std::string, std::string> all_words; //contains all words
    std::map<std::string, std::string> correct_words; //contains correct answers
    std::map<std::string, std::string> wrong_words; //contains wrong answers
public:
    Flashcards(); //Constructor
    ~Flashcards(); //Destructor
    void Add(); //Adds new words to maps
    void Clear(); //Clears all maps
    void Question(); //Starts questioning user RANDOMLY
    void Check(); //Checks if user's answer was correct
    void Assign(); //Assigns the answer to 'correct' or 'wrong' map
    void SaveToFile(); //Saves 'all_words' map to file
    void Search(); //Compares user's answer to answers in maps
    void Remove(); //Removes files from 'wrong' map if it already contains user's good answer
    void HandleInput(); //in this function are other functions REMEMBER
    void ShowMenu(); //shows Menu
};
