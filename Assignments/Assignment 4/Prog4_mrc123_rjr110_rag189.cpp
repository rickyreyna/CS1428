/*
   File: prog4_mrc123_rjr110_rag189.cpp

   Author: Michael Canales, Ricardo Reyna, and Roy Grady
   C.S.1428.002
   Lab Section: L03, L02, and L07
   Program: #04
   Due Date: 11/09/16

   This program prompts the user for the number of items purchased. If no
   items were purchased, the program terminates after printing an appropriate
   message to the screen; otherwise, the program repeatedly prompts the
   user for the price of the specified number of items and calculates the
   total of all purchased items. It then calculates the shipping charge,
   discounted total, tax on the discounted total, and the total amount due.

   After all calculations are performed, the program prints the author's
   identifying information followed by the total of all purchased items,
   the discounted total, the tax rate, the tax on the discounted total,
   shipping charges and the total amount due as shown below. Output is
   written in receipt form to both the console and to an output file.

   With the exception of the tax rate, the numeric data is formatted to
   two decimal places. The tax rate is formatted to four decimal places.

   Input (keyboard): number of items purchased, integer
                     item price, double

   Constants:        discount amount, double
                     cut off amount for free shipping, double
                     shipping charge, double
                     tax rate, double

   Output (console):
          Sample Console Output
          (This sample does not reflect prompts.)

          Author's Name
          C.S.1428.?         // '?' represents author's lecture section #
          Lab Section: L?    // '?' represents student's lab section #
          --/--/--           // dashes represent due date, month/day/year
               <blank line>
          Total Purchases:    $ ??.??
          Discounted Total:     ??.??
          Tax Rate:              ?.????
          Tax:                   ?.??
          Shipping:              ?.??
               <blank line>
          Total Amount Due:   $ ??.??
               <blank line>
               <blank line>
          A copy for your records can be found in prog4_00?out.txt.

   Output (file - prog4_00?out.txt):

          Author's Name
          C.S.1428.?         // '?' represents author's lecture section #
          Lab Section: L?    // '?' represents student's lab section #
          --/--/--           // dashes represent due date, month/day/year
               <blank line>
          Total Purchases:    $ ??.??
          Discounted Total:     ??.??
          Tax Rate:              ?.????
          Tax:                   ?.??
          Shipping:              ?.??
               <blank line>
          Total Amount Due:   $ ??.??

          ================================================
        cout << "A copy for your records can be found in prog4_002inp.txt"
             << endl;
          <Output will vary based on actual input values.>
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    const double DISC_AMT = 0.25,
                 SHP_CHRG = 8.5,
                 TAX_RATE = .0825,
                 FREE_SHP_LIMIT = 150;

    double item_price,
           disc_total,
           total,
           total_amount,
           tax;

    int item_number;

    total = 0;
    total_amount = 0;

    ofstream fout;
    fout.open ( "prog4_002out.txt" );

    if ( !fout )
    {
        cout << "ERROR - Failed to create and/or overwrite the file."
             << "Terminating program." << endl;

        system("PAUSE>NUL");

        return 2;
    }

        cout << "Enter the number of items ordered: ";
        cin  >> item_number;
        cout << endl;

        if ( item_number == 0 )
        {
            cout << "Come back again soon!";
        }

        for ( int i = 0; i < item_number; i++ )
        {
        cout << "Enter the item price: ";
        cin  >> item_price;

        total += item_price;
        }


        cout << endl << endl
             << "Michael Canales, Ricardo Reyna, and Roy Grady" << endl
             << "C.S.1428.002" << endl
             << "Lab Section: L03, L02, and L07" << endl
             << "11/09/16" << endl << endl;

        fout << "Michael Canales, Ricardo Reyna, and Roy Grady" << endl
             << "C.S.1428.002" << endl
             << "Lab Section: L03, L02, and L07" << endl
             << "11/09/16" << endl << endl;


        if ( disc_total >= FREE_SHP_LIMIT )
        {
        total_amount -= SHP_CHRG;
        }

        disc_total = total - ( total * DISC_AMT );
        total_amount += ( disc_total + (disc_total * TAX_RATE) + SHP_CHRG);
        tax = disc_total * TAX_RATE;

        cout << fixed << setprecision(2)
             << "Total Purchases:    $ " << setw(5) << total << endl
             << "Discounted Total:     " << setw(5) << disc_total << endl
             << setprecision(4)
             << "Tax Rate:             " << setw(7) << TAX_RATE << endl
             << setprecision(2)
             << "Tax:                  " << setw(5) << tax << endl
             << "Shipping:             " << setw(5) << SHP_CHRG << endl
             << endl
             << "Total Amount Due:   $ " << setw(5) << total_amount << endl
             << endl << endl
             << "A copy for your records can be found in prog4_002out.txt"
             << endl;

        fout << fixed << setprecision(2)
             << "Total Purchases:    $ " << setw(5) << total << endl
             << "Discounted Total:     " << setw(5) << disc_total << endl
             << setprecision(4)
             << "Tax Rate:             " << setw(7) << TAX_RATE << endl
             << setprecision(2)
             << "Tax:                  " << setw(5) << tax << endl
             << "Shipping:             " << setw(5) << SHP_CHRG << endl
             << endl
             << "Total Amount Due:   $ " << setw(5) << total_amount << endl
             << endl << endl;

        fout.close();

        system ( "PAUSE>NUL" );

        return 0;
}
