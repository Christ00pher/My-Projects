#include <iostream>
#include "Flashcards.h"

using namespace std;

int main()
{
    Flashcards f;
    while (f.IsRunning())
    {
        f.Menu();
        f.HandleInput();
        //process
    }
    return 0;
}
