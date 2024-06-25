// Exercise 13.13: ex_13.13.cpp
// test shape hierarchy
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Cube.h"
#include "Sphere.h"
#include "Tetrahedron.h"
using namespace std;


int main(){
    // create objects
    Square square(5);
    Circle circle(23);
    Triangle triangle(7);
    Cube cube(32);
    Sphere sphere(3);
    Tetrahedron tetrahedron(13);

    // create vector with six base-class pointers
    vector <Shape *> shapes(6);

    // initialize vector with shapes
    shapes[0] = &square;
    shapes[1] = &circle;
    shapes[2] = &triangle;
    shapes[3] = &cube;
    shapes[4] = &sphere;
    shapes[5] = &tetrahedron;

    cout << "Shapes processed polymorphically via dynamic binding:\n";
    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";

    for (size_t i=0; i<shapes.size(); ++i) {
        shapes[i]->print();
        cout << endl;
    }

    return 0;
}