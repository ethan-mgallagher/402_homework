/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */

#ifndef HOMEWORK2_OOSTR_H
#define HOMEWORK2_OOSTR_H


#include "IComparable.h"
#include <string>
#include <iostream>

//class implements the IComparable interface
// wraps a string private data member
using namespace std;

class OOStr : virtual public IComparable {
private:
    string data;
public:
    OOStr( string s );
    bool isLessThan(IComparable &comp);
    string getData() const;
    void print() const; //for testing
};


#endif //HOMEWORK2_OOSTR_H
