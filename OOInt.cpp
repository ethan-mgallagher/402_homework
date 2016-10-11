/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */


#include "OOInt.h"
#include <iostream>


OOInt::OOInt(int d) : data(d) {};

bool OOInt::isLessThan( IComparable & comp ) {
    OOInt & other = dynamic_cast<OOInt &>(comp);
   return other.getData() >= data;
}

int OOInt::getData() const {
    return data;
}

void OOInt::print() const {
    cout << to_string(data) << endl;
}
