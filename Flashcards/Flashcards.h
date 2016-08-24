#pragma once
#include <map>
#include <string>
#include <windows.h>


enum option
{
    BEGIN,
    SHOW,
    ADD,
    ASK,
    LOAD,
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
    std::map<std::string, std::string> asked_words; //contains already asked words
    int points;
    int choice; //user's choice
    HANDLE hOut; //handle used to manipulate console output
    void ClearHelpers();
    void ClearAll();
    void HandleAnswer(std::string, std::pair<std::string, std::string>);
public:
    std::pair<std::string, std::string> Random(); //Randoms a question to ask
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
    bool CheckAsked(std::map<std::string, std::string>::iterator);
    void ShowFlashcards(); //shows flashcards
    bool IsRunning(); //returns boolean value and says if the loop is supposed to iterate again
    void End(); //sets 'choice' value to END
    void ClearFile(); //Removing all data from the file
    void LoadFromFile(); //Loads existing flashcards from the file
    void isFull(); //checks if asked.size() == all.size()
};
