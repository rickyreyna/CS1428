//Created by Mike Luster

#include <iostream>
#include <iomanip>
using namespace std;

bool validChoice(char);
float calcTotal(int, float);
float calcChange(float, float);

int main()
{

    char choice;
    int quantity;
    float total, payment_amount, change;
    cout << "Welcome to the Vend-o-matic! Here are your choices:" << endl
         << "a)Ice Cream - $2.75" << endl
         << "b)Candy - $1.25" << endl
         << "c)Soda - $1.50" << endl
         << "d)Gum - $0.50" << endl
         << "Please select an item: ";
    cin >> choice;
    while(!validChoice(choice))
    {
        cout << "Error: Invalid choice. Please select a valid item: ";
        cin >> choice;
    }

    float item_cost;
    if(choice == 'a')
    {
        item_cost = 2.75;
    }
    else if(choice == 'b')
    {
        item_cost = 1.25;
    }
    else if(choice == 'c')
    {
        item_cost = 1.50;
    }
    else if(choice == 'd')
    {
        item_cost = 0.50;
    }

    cout << endl << "Enter Quantity: ";
    cin >> quantity;
    while(quantity < 1 || quantity > 20)
    {
        cout << "ERROR: Invalid Quantity. Please reenter: ";
        cin >> quantity;
    }

    total = calcTotal(quantity, item_cost);

    cout << fixed << setprecision(2) << "Total with tax: $" << total << endl;

    cout << "Enter Payment Amount: $";
    cin >> payment_amount;

    while(payment_amount < total)
    {
        cout << "ERROR: Insufficient funds. Please reenter payment: $";
        cin >> payment_amount;
    }

    change = calcChange(total, payment_amount);

    cout << "Your change is: $" << change;

    return 0;
}

bool validChoice(char c)
{
    return (c == 'a' || c == 'b' || c == 'c' || c == 'd');
}

float calcTotal(int quant, float cost)
{
    float total = quant * cost;
    float tax = total * 0.0825;

    return total + tax;
}

float calcChange(float total, float pay)
{
    return pay - total;
}
