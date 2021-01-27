#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
   int current_money = 1000;
   int computer_roll = rand() % 6+1;
   int user_roll = rand() % 6+1;
   int money_bet;
   char continue_playing;

    cout << "Gambling is an addiction..." << endl
         << "You currently have $" << current_money<< endl;

do
{

        cout << "How much would you like to bet?" << endl;
         cin >> money_bet;


    if ( money_bet <= current_money && money_bet >= 1 )
    {

        cout << "You rolled " << user_roll << endl
             << "Your opponet rolled " << computer_roll << endl;

        if ( user_roll <= computer_roll )

        {
            cout << "You loose $" << money_bet <<endl ;
            current_money -= money_bet;
        }

        else if ( user_roll > computer_roll )

        {
            cout << "You won $" << money_bet << endl;
            current_money += money_bet;
        }

        cout << "Would you like to continue? (Y or N):" << endl;
         cin >> continue_playing;
         if(continue_playing = 'N' || 'n')
         {
             cout << "You ended with $" << current_money << endl;
             return -1;
         }
    }

    else
    {
        cout << "ERROR: Invalid bet amount." << endl;
    }
}while(continue_playing == 'Y' || 'y');

    return 0;

}
