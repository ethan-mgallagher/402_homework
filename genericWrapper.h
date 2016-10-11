/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */

#ifndef HOMEWORK2_GENERICWRAPPER_H
#define HOMEWORK2_GENERICWRAPPER_H
#include <iostream>
#include <string>

using namespace std;

//generic wrapper class
//must implement >
template < typename T >
class genericWrapper {
private:
    T data;
public:
    explicit genericWrapper( T initvalue = T() ) : data( initvalue ) {};
    T getData() const{
        return data;
    };
    void print() const{
        cout << to_string(data) << endl;
    };

};

//functor for genericWrapper objects
// assumes the data type T from genericWrapper<T>
// are correctly compared with the > operator
template < typename T >
class comparator {
public:
    bool operator()( genericWrapper<T> & rhs, genericWrapper<T> & lhs ){
        return !(lhs.getData() > rhs.getData());
    };
};


#endif //HOMEWORK2_GENERICWRAPPER_H
