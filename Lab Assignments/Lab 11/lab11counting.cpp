// Written by Sherman Thompson

#include<iostream>
using namespace std;

double getAverage(double grades[], const int SIZE)
{
    double total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        total += grades[i];
    }
    return total / SIZE;
}

void getGrades(double grades[], const int SIZE)
{
    cout << "Please enter 5 grades:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cin >> grades[i];
    }
}

void countLetterGrades(double grades[], const int SIZE, int& numberOfAs, int& numberOfBs,
                       int& numberOfCs, int& numberOfDs, int& numberOfFs)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(grades[i] >= 90)
            numberOfAs++;
        else if(grades[i] >= 80)
            numberOfBs++;
        else if(grades[i] >= 70)
            numberOfCs++;
        else if(grades[i] >= 60)
            numberOfDs++;
        else
            numberOfFs++;
    }
}

void printData(double average, int numberOfAs, int numberOfBs, int numberOfCs,
               int numberOfDs, int numberOfFs)
{
    cout << "Class average : " << average << endl;
    cout << "Number of A's: " << numberOfAs << endl;
    cout << "Number of B's: " << numberOfBs << endl;
    cout << "Number of C's: " << numberOfCs << endl;
    cout << "Number of D's: " << numberOfDs << endl;
    cout << "Number of F's: " << numberOfFs << endl;
}

int main()
{
    const int SIZE = 5;
    double grades[SIZE],
           average;
    int numberOfAs = 0,
        numberOfBs = 0,
        numberOfCs = 0,
        numberOfDs = 0,
        numberOfFs = 0;

    getGrades(grades, SIZE);
    average = getAverage(grades, SIZE);
    countLetterGrades(grades, SIZE, numberOfAs, numberOfBs,
                       numberOfCs, numberOfDs, numberOfFs);
    printData(average, numberOfAs, numberOfBs, numberOfCs,
               numberOfDs, numberOfFs);
}
