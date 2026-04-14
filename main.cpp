#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// ============================================================================== //
// function declarations
// function prototypes
void Userguess(int& x, int& y, int& z);
int random3digit(int& x, int& y, int& z);
string isgreen(int num1, int num2);
string isyellow(int num1, int num2, int num3);

int main()
{
	int attempt = 0;

	while (attempt < 5 ) {
    int usercode1, usercode2, usercode3;
    int secretCode1 = 0, secretCode2 = 0, secretCode3 = 0;
    string hint = "";
    random3digit(secretCode1, secretCode2, secretCode3);
    cout << secretCode1 << secretCode2 << secretCode3 << endl;

    cout << "Welcome to Mastermind!" << endl;

    Userguess(usercode1, usercode2, usercode3);
    cout << usercode1 << usercode2 << usercode3 << endl;

    hint += isgreen(secretCode1, usercode1);
    hint += isgreen(secretCode2, usercode2);
    hint += isgreen(secretCode3, usercode3);

    hint += isyellow(usercode1, secretCode2, secretCode3);
    hint += isyellow(usercode2, secretCode1, secretCode3);
    hint += isyellow(usercode3, secretCode1, secretCode2);

    if (hint == "") cout << "red";

    cout << hint << endl;
	attempt++;
	if ( usercode1 == secretCode1 && usercode2 == secretCode2 && usercode3 == secretCode3 ) {
		cout << "\n You cracked the code! In: " << attempt << " attempts" << endl;
 }
    return 0;
}

// ============================================================================== //
// function definitions


//
//
int random3digit(int& x, int& y, int& z)
{
    srand(time(NULL));
    x = rand() % 10;
    y = rand() % 10;
    while (y == x)
    {
        y = rand() % 10;
    }

    z = rand() % 10;
    while (z == x || z == y)
    {
        z = rand() % 10;
    }

    return 0;
}


//
//
void Userguess(int& x, int& y, int& z)
{
    cout << "Please enter your guess: (ex: 1 4 5) ";
    cin >> x >> y >> z;
}

//
string isgreen(int num1, int num2)
{
    if (num1 == num2)
    {
        return "Green ";
    }
    return "";
}
string isyellow(int num1, int num2, int num3)
{
    if (num1 == num2 || num1 == num3)
    {
        return "Yellow";
    }
    return "";
}