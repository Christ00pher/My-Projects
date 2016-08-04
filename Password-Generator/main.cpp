#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    enum Sign{letter};
    enum Letter{great};
    int n; //number of signs in password
    vector <char> password;
    ofstream file;

    cout << "Number of characters in password: ";
    cin >> n;
    for (int i = 0; i < n; i++) //add an option to choose to create a number of passwords at one time
    {
        if (rand() % 2 == letter)
        {
            if (rand() % 2 == great)
                password.push_back(char(rand() % 26 + 65));
            else
                password.push_back(char(rand() % 26 + 97));
        }
        else //generate and put down a number
            password.push_back(rand() % 11 + 48);
    }
    file.open("password.txt", ios::out);
    for (auto x : password)
        file << x;

    file << endl;
    file.close();
    cout << "Generated password is: "; //add an option to enable the user to generate the password again
                                        //if the generated one is not good for him
    for (auto x : password)
        cout << x;
    return 0;
}
