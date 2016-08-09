#include <iostream>
#include "Flashcards.h"

using namespace std;

int main()
{
    Flashcards f;
    while (f.IsRunning())
    {
        f.Menu(); //shows MENU and gets user's choice
        f.HandleInput(); //calls functions according to the user's choice
    }
    return 0;
}
