#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// ============================================================================== //
// function declarations
// function prototypes
void Userguess(int &x, int &y, int &z);
// pulls tne user guess
int random3digit(int &x, int &y, int &z);
// makes 3 random numbers
string isgreen(int num1, int num2);
// checks if the number is green which means its in the right spot and the right number
string isyellow(int num1, int num2, int num3);
// checks is yellow, right number wrong spot
int main() {
    int attempt = 0;
int usercode1, usercode2, usercode3;
        int secretCode1 = 0, secretCode2 = 0, secretCode3 = 0;
    random3digit(secretCode1, secretCode2, secretCode3);
        //cout << secretCode1 << secretCode2 << secretCode3 << endl;
    cout << "Welcome to Mastermind!" << endl;
    // this whole chunk of code makes the hints for green and yellow
    while (attempt < 5) {

        string hint = "";

        Userguess(usercode1, usercode2, usercode3);
        cout << usercode1 << usercode2 << usercode3 << endl;

        hint += isgreen(secretCode1, usercode1);
        hint += isgreen(secretCode2, usercode2);
        hint += isgreen(secretCode3, usercode3);

        hint += isyellow(usercode1, secretCode2, secretCode3);
        hint += isyellow(usercode2, secretCode1, secretCode3);
        hint += isyellow(usercode3, secretCode1, secretCode2);

        if (hint == "") cout << "red";
        // this one line is red hints
        cout << hint << endl;
        attempt++;

        if (usercode1 == secretCode1 && usercode2 == secretCode2 && usercode3 == secretCode3) {
            cout << "\n You cracked the code! In: " << attempt << " attempts" << endl;
            break;
        }
    }


    return 0;
}

// ============================================================================== //
// function definitions


//
// this makes it so it will keep the same digits regardless of attempts
int random3digit(int &x, int &y, int &z) {
    srand(time(NULL));
    x = rand() % 10;
    y = rand() % 10;
    while (y == x) {
        y = rand() % 10;
    }

    z = rand() % 10;
    while (z == x || z == y) {
        z = rand() % 10;
    }

    return 0;
}


//
// return code for green yellow and red
void Userguess(int &x, int &y, int &z) {
    cout << "Please enter your guess: (ex: 1 4 5) ";
    cin >> x >> y >> z;
}

//
string isgreen(int num1, int num2) {
    if (num1 == num2) {
        return "Green ";
    }
    return "";
}

string isyellow(int num1, int num2, int num3) {
    if (num1 == num2 || num1 == num3) {
        return "Yellow";
    }
    return "";
}
