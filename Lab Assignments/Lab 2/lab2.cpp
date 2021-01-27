// Ricardo Reyna

#include <iostream>

using namespace std;

int main()
{
    double age,
        iq,
        qi,
        saiyan_power_level;

    cout << "What is your qi count?";
    cin  >> qi;
    cout << "What is your age?";
    cin  >> age;
    cout << "What is your IQ?";
    cin  >> iq;

    saiyan_power_level = (qi * 9000) / ((age * 9000)-(iq*iq));

    cout << "Your Saiyan Power Level is: " << saiyan_power_level << endl;

    return 0;

}
