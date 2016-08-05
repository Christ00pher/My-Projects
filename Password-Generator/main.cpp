#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

enum Sign{letter};
enum Letter{great};

//shows generated password
void show_password(vector <char> &password)
{
    cout << "Generated password is: ";
    for (auto x : password)
        cout << x;
}

//returns length of the password
int get_number()
{
    int x;
    system("CLS");
    cout << "Number of characters in password: ";
    cin >> x;
    return x;
}

//generate a password
void create_password(vector <char> &password, int n)
{
    for (int i = 0; i < n; i++)
    {
        //if random number == 0, then we generate a letter
        //in other way a number is generated
        if (rand() % 2 == letter)
        {
            //here we choose to generate a great or small letter
            if (rand() % 2 == great)
                password.push_back(char(rand() % 26 + 65));
            else
                password.push_back(char(rand() % 26 + 97));
        }
        else //generate and put down a number
            password.push_back(rand() % 10 + 48);
    }
}

//checks if repetition of the main loop is needed
bool toRepeat()
{
    char repeat;
    cout << "\nCreate other password (y/n): ";
    cin >> repeat;
    return (repeat == 'y');
}

//saves password to file
void SaveToFile(vector <char> &password)
{
    ofstream file;
    file.open("password.txt", ios::out);
    for (auto x : password)
        file << x;
    file << endl;
    file.close();
    cout << "Password was succesfully saved to file.\n";
    password.clear();
}

int main()
{
    srand(time(NULL));
    int n; //number of signs in password
    vector <char> password;

    do
    {
        password.clear();
        n = get_number();
        create_password(password,n);
        show_password(password);
    } while (toRepeat());
    SaveToFile(password);
    return 0;
}
