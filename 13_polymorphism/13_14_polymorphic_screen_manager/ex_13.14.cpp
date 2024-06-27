// Exercise 13.14: ex_13.14.cpp
// test shape hierarchy
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <limits>
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

int getConsoleWidth(); // function declaration

int main(){
    int consoleWidth = getConsoleWidth(); // get the console's width
    int length = 0;
    string position, figure;
    char fill;
    int startPosition;

    // create vector with five base-class pointers
    vector <Shape *> shapes(5);

    // get the information for the shapes
    // should validate inputs
    for (size_t i{0}; i<shapes.size(); ++i){
        cout << "\nPlease enter the information of the shape: \n"
             << "Shape: ";
        cin >> figure;
        cout << "Length: ";
        cin >> length;
        cout << "Position: ";
        cin >> position;
        cout << "Character to draw: ";
        cin >> fill;

        // set the start position to draw
        if (position == "right")
            startPosition = consoleWidth;
        else if (position == "center")
            startPosition = consoleWidth/2;
        else
            startPosition = 0;

        // initialize vector shapes
        if (figure == "circle")
            shapes[i] = new Circle(length, fill, startPosition);
        else if (figure == "square")
            shapes[i] = new Square(length, fill, startPosition);
        else if ( figure == "triangle")
            shapes[i] = new Triangle(length, fill, startPosition);

        cin.get();
        system("cls");
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    cout << "Shapes processed polymorphically via dynamic binding:\n";
    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";

    for (size_t i=0; i<shapes.size(); ++i) {
        shapes[i]->draw();
        cout << "\n\n";
    }

} // end main

// function to get the console width
int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left+1;

    return columns;
}