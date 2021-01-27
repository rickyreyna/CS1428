#include <iostream>
#include <iomanip>
using namespace std;

void getGrades(double [], const int);
void findDropInfo(double [], const int, int &, double &);
double getAverage(double [], const int);
void printData(double [], int, double, double);

int main()
{
    const int SIZE = 5;
    double grades[SIZE];
    int lowest;
    double avg,
           avgBeforeDrop;
    getGrades(grades, SIZE);
    findDropInfo(grades, SIZE, lowest, avg);
    avgBeforeDrop = getAverage(grades, SIZE);
    printData(grades, lowest, avg, avgBeforeDrop);

    return 0;
}

void getGrades(double g[], const int SIZE)
{
    cout << "Please enter " << SIZE << " grades:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cin >> g[i];
    }
}

void findDropInfo(double g[], const int SIZE, int &lowest, double &average)
{
    lowest = 0;
    for(int i = 1; i < SIZE; i++)
    {
        if(g[lowest] > g[i])
        {
            lowest = i;
        }
    }

    double total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(i != lowest)
        {
            total += g[i];
        }
    }
    average = total/(SIZE-1);
}

double getAverage(double g[], const int SIZE)
{
    int total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        total += g[i];
    }
    return total/SIZE;
}

void printData(double g[], int lowestIndex, double average, double average_before)
{
    cout << "Grade dropped: " << g[lowestIndex] << endl
         << fixed << setprecision(2) << "Final Average: " << average << endl
         << "Average Before Dropped Grade: " << average_before;
}
