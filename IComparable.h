/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */

#ifndef HOMEWORK2_ICOMPARABLE_H
#define HOMEWORK2_ICOMPARABLE_H

//interface for OO solution for sorting
class IComparable {

public:

    //pure virtual method, must be implemented for use in sorting
    virtual bool isLessThan( IComparable & other ) = 0;


};


#endif //HOMEWORK2_ICOMPARABLE_H
