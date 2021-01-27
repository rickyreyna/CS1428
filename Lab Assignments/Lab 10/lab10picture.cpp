#include <iostream>

using namespace std;

int getArea(int, int);
int getPerimeter(int, int);
void printPicture(int, int, char);
bool validSideLength(int);

int main()
{
    int width,
        height,
        perim,
        area;
    char symbol,
         cont;

    do{
        cout << "Please enter the following" << endl;
        cout << "Width: ";
        cin >> width;

        while(!validSideLength(width))
        {
            cout << "ERROR: Sides must be between 1 and 10." << endl
                 << "Enter the width: ";
            cin >> width;
        }

        cout << "Height: ";
        cin >> height;

        while(!validSideLength(height))
        {
            cout << "ERROR: Sides must be between 1 and 10." << endl
                 << "Enter the height: ";
            cin >> height;
        }

        cout << "Desired symbol for picture: ";
        cin >> symbol;

        perim = getPerimeter(width, height);
        area = getArea(width, height);
        cout << "\nPerimeter: " << perim << endl
             << "Area: " << area << endl
             << "Picture of your rectangle: " << endl;
        printPicture(width, height, symbol);

        cout << "\nWould you like to print another picture? (Y or N): ";
        cin >> cont;

    }while(cont == 'Y' || cont == 'y');

    return 0;
}

bool validSideLength(int s)
{
    return s >= 1 && s <= 10;
}

int getPerimeter(int l, int w)
{
    return (2*l) + (2*w);
}

int getArea(int l, int w)
{
    return l * w;
}

void printPicture(int width, int height, char sym)
{
    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            cout << sym;
        }
        cout << endl;
    }
}
