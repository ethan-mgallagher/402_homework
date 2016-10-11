/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */

#ifndef HOMEWORK2_OOINT_H
#define HOMEWORK2_OOINT_H

#include <iostream>
#include <string>
#include "IComparable.h"

using namespace std;

//class implements the IComparable interface
// wraps an int data member
class OOInt : virtual public IComparable {

private:
    int data;
public:
    OOInt( int d );
    bool isLessThan( IComparable & other );
    int getData() const;
    void print() const; //used for testing

};


#endif //HOMEWORK2_OOINT_H
