/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */
#ifndef HOMEWORK2_MERGESORT_H
#define HOMEWORK2_MERGESORT_H
#include "IComparable.h"
#include <vector>
#include <queue>

using namespace std;

//prototypes for object-oriented sorting methods, defined in main.cpp

//takes a vector of IComparable * and returns true if they are in sorted min-order
bool verifySort( vector<IComparable *> amISorted );

//Takes two vectors of IComparable * and merges them in sorted order
void merge( vector<IComparable *> & merger, vector<IComparable *> vec1, vector<IComparable *> vec2 );

//Iterative mergesort for vectors of IComparable *
void mergeSort( vector<IComparable *> & vec );

//template versions

//helper method for iterative mergesort
//Comparator must be a functor that returns true if lhs <= rhs
template < typename T, typename Comparator  >
void merge( vector<T *> & merger, vector<T *> vec1, vector<T *> vec2, Comparator & comp ){
    merger.clear();

    int i, j, k;

    for ( i=0,j=0,k=0; i < vec1.size() && j < vec2.size() ; k++ ){
        if ( comp( *vec1[i], *vec2[j] )){ //if vec1[i] < vec2[j]
            merger.push_back( vec1[i] );
            i++;
        }
        else if ( comp( *vec2[j], *vec1[i])){ //if vec2[j] < vec1[j]
            merger.push_back( vec2[j]);
            j++;
        }

    }

    while ( i < vec1.size() ){
        merger.push_back( vec1[i] );
        i++;
    }

    while ( j < vec2.size() ){
        merger.push_back( vec2[j]);
        j++;
    }
}

//Comparator must be a functor that returns a true if lhs <= rhs
template < typename T, typename Comparator >
void mergeSort( vector<T *> & vec, Comparator & comp ){
    queue< vector<T *> > * mergeQ = new queue< vector<T *> >;
    vector<T * > * merger = new vector<T *>;

    //push each element of the vector onto the queue
    for (int i = 0; i < vec.size(); i++ ){
        mergeQ->push( vector<T *>( 1, vec[i] ));
    }

    while ( mergeQ->size() > 1 ){
        vector<T *> numOne;
        vector<T *> numTwo;
        numOne = mergeQ->front();
        mergeQ->pop();
        numTwo = mergeQ->front();
        mergeQ->pop();
        merge( *merger, numOne, numTwo, comp );
        mergeQ->push( *merger );
    }

    vec = mergeQ->front();

    merger->clear();
    delete merger;

    delete mergeQ;

}

//comparator must be a functor that returns true if lhs <= rhs
template < typename T , typename Comparator >
bool verifySort( vector<T *> & amISorted, Comparator & comp ) {
    for ( int i = 1; i < amISorted.size() ; i++ ){
        if ( !comp( *amISorted[i-1], *amISorted[i])) return false;
    }
    return true;
}



#endif //HOMEWORK2_MERGESORT_H
