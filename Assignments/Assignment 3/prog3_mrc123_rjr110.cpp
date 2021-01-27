/*
   File: prog3_mrc123_rjr110.cpp

   Michael Canales and Ricardo Reyna
   C.S.1428.002
   Lab Section: L03 and L02
   Program: #3
   Due Date: 10/19/16

   This program reads a simple expression of the form 'value operator value'
   from the keyboard only using one read statement to "get" the parts of the
   expression entered. The prompt and input expression are kept on one line.
   After the expression is entered at the keyboard and the enter key is hit,
   two blank lines are printed to the screen.

   The expression is evaluated as described below:
   The program checks for addition (+), subtraction (-), multiplication (*),
   and division (/) operators. When the division operator is encountered, a
   check for division by zero is included. A check for an invalid operator
   is included as well. (e.g. 134.6 ! 23.1) A switch statement with a nested
   double-sided alternative for handling the division operator is used to solve
   the problem as these mutually exclusive events suggest.

   The original expression is echoed to an output file along with the
   evaluated result IF the operator is a valid one. If division by zero
   is encountered, the original expression is echoed to the output file
   along with the message 'Division by zero produces an undefined result.'
   (without quotation marks.) If an invalid operator is encountered, the
   original expression is echoed to the output file along with the message
   'Encountered unknown operator.' (without quotation marks.)

   An attempt to avoid repetitive code is made.

   An appropriate message is displayed to the console screen if the output
   file fails to open.

   An appropriate message is written to the console screen informing the
   user of the output file name to which the results have been written.
   Layout and content of the output are shown in the samples below.

   Input (keyboard): expression from keyboard (allowing for real input data)
                     operand1   (double)
                     operator   (char)
                     operand2   (double)

   Constants: none

   Output (console):
      Sample Console Display:

      Enter a binary expression of the form: operand operator operand
           <blank line>
           <blank line>
      Author's Name
      C.S.1428.?         // '?' represents author's lecture section #
      Lab Section: L?    // '?' represents student's lab section #
      --/--/--           // dashes represent due date, month/day/year
           <blank line>
      <Appropriate message indicating the name of the output file.>

   Output (file - prog3_00?out?.txt): // '00?' represents author's lect sec #
      Sample File Output:

      Author's Name
      C.S.1428.?         // '?' represents author's lecture section #
      Lab Section: L?    // '?' represents student's lab section #
      --/--/--           // dashes represent due date, month/day/year
           <blank line>
      198.7 / 0  Division by zero produces an undefined result.

      OR

      Author's Name
      C.S.1428.?         // '?' represents author's lecture section #
      Lab Section: L?    // '?' represents student's lab section #
      --/--/--           // dashes represent due date, month/day/year
           <blank line>
      178.9 - 326.8 = -147.9

      ================================================

      <Output will vary based on actual input values.>
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    double operand1,
           operand2;
    char   operatr;

    ofstream fout;
    fout.open ("answer_text.txt");


    cout << "Enter a binary expression of the form: operand operator operand ";
    cin  >> operand1 >> operatr >> operand2;

    cout << endl << endl
         << "Michael Canales and Ricardo Reyna" << endl
         << "C.S.1428.002" << endl
         << "Lab Section: L03 and L02" << endl
         << "10/19/16" << endl << endl;

    if (!fout)
    {
        cout << "ERROR - Failed to create and/or overwrite the file. Terminating program." << endl;
        return -1;
    }
    else
    {
        cout << "Program results have been written to answer_text.txt" << endl;
    }

    fout << "Michael Canales and Ricardo Reyna" << endl
         << "C.S.1428.002" << endl
         << "Lab Section: L03 and L02" << endl
         << "10/19/16" << endl << endl
         << fixed << setprecision(1);

    switch (operatr)
         {
        case '+':
             fout << operand1 << " " << operatr << " " << operand2
                  << " = " << operand1 + operand2;

             break;

        case '-':
             fout << operand1 << " " << operatr << " " << operand2
                  << " = " << operand1 - operand2;

             break;

        case '*':
             fout << operand1 << " " << operatr << " " << operand2
                  << " = " << operand1 * operand2;

             break;

        case '/':
             if (operand2 == 0)
             {
                 fout << operand1 << " " << operatr << " " << operand2
                      << "           "
                      << "Division by 0 produces an undefined result.";
             }

             else
             {
                 fout << operand1 << " " << operatr << " " << operand2
                      << " = " << operand1 / operand2;

                 break;
             }
         }
    fout.close();
    system ("PAUSE > NUL");

    return 0;
}
