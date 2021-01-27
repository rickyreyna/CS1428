#include <iostream>
#include <iomanip>

using namespace std;

bool validHours(int);
float calcPay(int, float);
float calcAveragePay(float, int);

int main()
{
    int num_employees,
        hours;
    float total_pay = 0,
          pay_rate,
          avg_pay,
          pay;
    cout << "Enter the number of employees: ";
    cin >> num_employees;
    while(num_employees < 1)
    {
        cout << "ERROR: Number of Employees must be at least 1." << endl
             << "Enter the number of employees: ";
        cin >> num_employees;
    }

    for(int i = 1; i <= num_employees; i++)
    {
        cout << "\n\nEnter number of hours worked by Employee " << i << ": ";
        cin >> hours;

        while(!validHours(hours))
        {
            cout << "ERROR: Hours must be between 1 and 40." << endl
                 << "Enter number of hours worked by Employee " << i << ": ";
            cin >> hours;
        }

        cout << "Enter the pay rate for Employee " << i << ": ";
        cin >> pay_rate;

        pay = calcPay(hours, pay_rate);

        total_pay += pay;

        cout << fixed << setprecision(2);
        cout << "\nWeekly Salary of Employee " << i << ": $" << pay << endl;
    }

    avg_pay = calcAveragePay(total_pay, num_employees);

    cout << "\n\nThe Average Weekly Salary for the Company is $" << avg_pay;

    return 0;
}

bool validHours(int h)
{
    return h >= 1 && h <= 40;
}

float calcPay(int hrs, float rate)
{
    return hrs * rate;
}

float calcAveragePay(float total, int num_emp)
{
    return total/num_emp;
}

