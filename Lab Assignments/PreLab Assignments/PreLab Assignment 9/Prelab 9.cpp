// Ricardo Reyna
// 10/31/2016
// Lab 9 Pre-Lab Assignment

#include <iostream>

using namespace std;

int main()
{

    double jedi_level;

    int age;
    int weight;
    int mcc;

    void printOut();
    {
    cout << "Welcome to my fabulous Jedi power level calculator!" << endl;
    cout << "This program will take your age, weight, and" << endl;
    cout << "midichlorean count and return your Jedi power level!"
         << endl << endl;
    }


    void promptUserAndJediLvl( int age, int weight, int mcc, double jedi_level);
    {
    cout << "please enter your age : ";
    cin >> age;
    cout << "please enter your weight : ";
    cin >> weight;
    cout << "please enter your midicholrean count : ";
    cin >> mcc;
    jedi_level = static_cast <double>(mcc * age) / (weight * weight);
    }

    cout << "Your Jedi Level is : " << jedi_level;

    return 0;

}

