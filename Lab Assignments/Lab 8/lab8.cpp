#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int SIZE = 7;
    const string WEEK[] = {"Sunday",
                        "Monday",
                        "Tuesday",
                        "Wednesday",
                        "Thursday",
                        "Friday",
                        "Saturday"};

    double distances[SIZE];
    double total = 0,
        average;
    int longest_index = 0,
        shortest_index = 0;

    cout << "Please enter the distance your ran." << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << WEEK[i] << "  : ";
        cin >> distances[i];
    }

    for(int i = 0; i < SIZE; i++)
    {
        total += distances[i];
    }
    average = total/SIZE;

    for(int i = 1; i < SIZE; i++)
    {
        if(distances[longest_index] < distances[i])
        {
            longest_index = i;
        }
    }

    for(int i = 1; i < SIZE; i++)
    {
        if(distances[shortest_index] > distances[i])
        {
            shortest_index = i;
        }
    }


    cout << fixed << setprecision(2)
         << "Total distance  : " << total << endl
         << "Average distance : " << average << endl
         << "Farthest distance : " << distances[longest_index] << " miles on " << WEEK[longest_index] << endl
         << "Shortest distance : " << distances[shortest_index] << " miles on " << WEEK[shortest_index] << endl;

    return 0;
}
