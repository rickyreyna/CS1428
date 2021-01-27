/*
   File: prog1_ads146_rjr110_.cpp

   Author: Alex Sanchez, Ricardo Reyna
   C.S.1428.002
   Lab Section: L07, L02
   Program: #01
   Due Date: 09/21/2016

   Prix fixe (pronounced "prefix") menus are common in Europe. A prix fixe
   menu typically includes a number of pre-determined items presented as a
   multi-course meal at a set price. For example, one evening, a restaurant
   may offer a four course prix fixe menu of escargot for the first course,
   beef bourguignon (boor-geen-yuhn) for the second, a cheese platter for
   the third, and creme brulee for dessert. The prix fixe menu for the
   evening, along with its cost, is typically posted on a message board
   outside the restaurant.

   =======================================================================

   This program prompts the user for the number of prix fixe meals ordered
   by the customer(s). The program calculates the total cost of the meal(s),
   the sales tax, the tip, and the total amount due. The program then prints
   in receipt form the individual price of a prix fixe meal, the number of
   prix fixe meals ordered, the total for all prix fixe meals ordered, the
   sales tax, the tip and the total amount due. Sample layout of a receipt
   is shown below.

   Input (keyboard): meals_ordered      (integer)
   Constants:
          Sample Values:
              PRIX_FIXE = 50.00         (double)
              SALES_TAX_RATE = .0825    (double)
              TIP_PERCENTAGE = .15      (double)
   Output (console):
          Sample Layout:

              Author's Name
              C.S.1428.?         // '?' represents author's lecture section #
              Lab Section: L?    // '?' represents student's lab section #
              --/--/--           // dashes represent due date, month/day/year
                   <blank line>
              Prix Fixe Price:    $   50.00
                                    x     8
              Total for 8 meals:     400.00
              Sales Tax @8.25%        33.00
              15% Tip                 64.95
              Total Due:          $  497.95

   =======================================================================

   <Output will vary based on actual input and values used for constants.>
*/


#include <iostream>

#include <cstdlib>

#include <iomanip>

using namespace std;

int main()
{
    const double PRIX_FIXE = 65.95,
                 SALES_TAX_RATE = 0.095,
                 TIP_PERCENTAGE = 0.15;

    int meals_ordered = 2;

    double sales_tax = (PRIX_FIXE * meals_ordered)* SALES_TAX_RATE;
    double total = ((PRIX_FIXE * meals_ordered) + (sales_tax)) +
                   (((PRIX_FIXE * meals_ordered) + sales_tax) * TIP_PERCENTAGE);

    cout << endl << "Alex Sanchez, Ricardo Reyna" << endl
         << "C.S. 1428.002" << endl
         << "Lab Section: 07, 02" << endl
         << "09/19/2016" << endl << endl;

    cout << fixed << setprecision(2);

    cout << "Prix Fixe Price:   $ " << setw(6) << PRIX_FIXE << endl

         << "                    x" << setw(6) << meals_ordered << endl

         << "Total for 2 meals:   " << setw(6) << PRIX_FIXE * meals_ordered
         << endl

         << "Sales Tax @" << SALES_TAX_RATE * 100 << "%     " << setw(6)
         << sales_tax << endl

                 << setprecision(0);

    cout << TIP_PERCENTAGE * 100 << "% Tip              " << setw(6)
                 << setprecision(2);
    cout << ((PRIX_FIXE * meals_ordered) + sales_tax) * TIP_PERCENTAGE << endl

         << "Total Due:         $ " << setw(6) << total << endl;


    system("PAUSE > NUL");

    return 0;

}




