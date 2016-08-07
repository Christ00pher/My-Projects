#pragma once
#include <map>
#include <string>

enum option //add enum CHAR
{
    SHOW = 1,
    ADD,
    ASK,
    SAVE,
    REMOVE,
    END
};

class Flashcards
{
private:
    std::map<std::string, std::string> all_words; //contains all words
    std::map<std::string, std::string> correct_words; //contains correct answers
    std::map<std::string, std::string> wrong_words; //contains wrong answers
    char choice; //user's choice
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
    void Menu(); //shows Menu
    void ShowFlashcards(); //shows flashcards
    bool IsRunning();
};
