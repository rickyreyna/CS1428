#include <iostream>
#include <iomanip>
using namespace std;

double getAverage(double [], const int);
void applyCurve(double [], const int, double);
void findCurveInfo(double [], const int, int &, double &);
void printData(double [], const int, int, double, double);

int main()
{
    const int SIZE = 5;
    int highest;
    double average,
           curve;
    double grades[SIZE];

    cout << "Enter " << SIZE << " grades: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cin >> grades[i];
    }

    findCurveInfo(grades, SIZE, highest, curve);
    applyCurve(grades, SIZE, curve);
    average = getAverage(grades, SIZE);
    printData(grades, SIZE, highest, average, curve);
    return 0;
}

double getAverage(double g[], const int SIZE)
{
    double total = 0;

    for(int i = 0; i < SIZE; i++)
    {
        total += g[i];
    }

    return total/SIZE;
}

void applyCurve(double g[], const int SIZE, double curve)
{
    for(int i = 0; i < SIZE; i++)
    {
        g[i] += curve;
    }
}

void findCurveInfo(double g[], const int SIZE, int &highest, double &curve)
{
    highest = 0;
    for(int i = 1; i < SIZE; i++)
    {
        if(g[highest] < g[i])
        {
            highest = i;
        }
    }

    curve = (100 - g[highest])/2;
}

void printData(double g[], const int SIZE, int highest, double avg, double curve)
{
    cout << fixed << setprecision(1) << "Grades after curve: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << g[i] << endl;
    }

    cout << "Average after curve: " << avg << endl;
    cout << "Highest grade after curve: " << g[highest] << endl;
    cout << "Curve amount applied: " << curve << endl;
}
