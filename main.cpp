/*Name: Ethan Gallagher
 * Assignment: Project 2
 * Course: CSC 402
 * Date: 10/4/2016
 */

#include <iostream>
#include "OOStr.h"
#include "OOInt.h"
#include <stdlib.h>
#include <vector>
#include "time.h"
#include "mergeSort.h"
#include "genericWrapper.h"

using namespace std;

//This program tests an object-oriented against a generic programming approach for c++ programming.
//An interface for object implementing a isLessThan method is used to implement two wrapper classes OOInt
/*And OOStr, which wrap ints and strings respectively.
 *
 * A template class, genericWrapper and functor "comparator" are also implemented.
 *
 * Both the Object-oriented and generic approach are then tested with various-sized vectors in an iterative
 * mergesort implementation. The generic approach achieves superior results, due to the extra overhead of
 * dynamic dispatch in the object-oriented approach.
 *
 */

int main() {

    clock_t t; //initialize our clock
    srand( time( NULL)); //initialize our random number generator
    //generate some vectors with random values

    //we will first test our object oriented solution
    //int vector
    vector<IComparable *> * intVec = new vector<IComparable *>;
    vector<IComparable *> * strVec = new vector<IComparable *>;

    //charset for random string generation
    char charset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                      't', 'u', 'v', 'w',
                      'x', 'y', 'z'};

    //the sizes of vectors we will sort
    int vals[] = { 100, 1000, 10000, 100000};
    for ( int j = 0; j < sizeof(vals)/sizeof(*vals) ; j++ ) {
        cout << "OO tests for a size of " + to_string( vals[j]) << endl;
        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) { //push random ints into test vector
                intVec->push_back(new OOInt(rand() % 1000));
            }

            //string vector

            //we will use merge sort to time our implementation

            //sort int vector first
            t = clock();
            mergeSort(*intVec);
            t = clock() - t;


            //verify the sort worked correctly for the int test vector
            if (verifySort(*intVec)) {
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for OOInt, size: " + to_string(vals[j])
                     + " time elapsed: " + to_string(t)
                     << endl;
            }

            intVec->clear();
        }

        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) { //push random strings into test vector
                int length = rand() % 4 + 1; //max length is four
                string str = "";
                for (int j = 0; j < length; j++) {
                    str = str + charset[rand() % sizeof(charset)];
                }
                strVec->push_back(new OOStr(str));
            }

            //now sort string vector
            t = clock();
            mergeSort(*strVec);
            t = clock() - t;


            if (verifySort(*strVec)) { //verify string vector was sorted correctly
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for OOStr, size: " + to_string(vals[j]) +
                     " time elapsed: " + to_string(t)
                     << endl;
            }

            strVec->clear();
        }
    }


    //give us some space
    cout << "\n\n\n";


    //now we will test the generic implementation

    vector< genericWrapper<int> *> * gIntVec = new vector< genericWrapper<int> *>;
    vector< genericWrapper<string> *> * gStrVec = new vector< genericWrapper<string> *>;

    //create functors for sorting int and string genericWrapper objects
    comparator<string> * strComp = new comparator<string>();
    comparator<int> * intComp = new comparator<int>();

    for ( int j = 0; j < sizeof(vals)/sizeof(*vals) ; j++ ) {
        cout << "Generic tests for a size of " + to_string( vals[j]) << endl;

        for ( int k = 0; k < 3 ; k++ ) {
            for (int i = 0; i < vals[j]; i++) {//push random int genericWrappers onto vector
                gIntVec->push_back(new genericWrapper<int>(rand() % 1000));
            }

            //string vector


            //time generic implementation with merge sort on ints
            t = clock();
            mergeSort(*gIntVec, *intComp);
            t = clock() - t;

            if (verifySort(*gIntVec, *intComp)) { //verify genericWrapper<int> sort
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for GenInt, size: " + to_string(vals[j])
                     + " time elapsed: " + to_string(t)
                     << endl;
            }

            gIntVec->clear();

        }

        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) {//push random string genericWrappers onto vector
                int length = rand() % 4 + 1;
                string str = "";
                for (int j = 0; j < length; j++) {
                    str = str + charset[rand() % sizeof(charset)];
                }
                gStrVec->push_back(new genericWrapper<string>(str));
            }

            //test strings
            t = clock();
            mergeSort(*gStrVec, *strComp);
            t = clock() - t;

            if (verifySort(*gStrVec, *strComp)) { //verify genericWrapper<string> sort
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for GenStr, size: " + to_string(vals[j]) +
                     " time elapsed: " + to_string(t)
                     << endl;
            }

            //clean up
            gStrVec->clear();
        }
    }

    delete intVec;
    delete strVec;
    delete gIntVec;
    delete gStrVec;
    delete intComp;
    delete strComp;
}

//for verification of sort
bool verifySort( vector<IComparable *> amISorted ) {
    for ( int i = 1; i < amISorted.size() ; i++ ){
        if ( !amISorted[i-1]->isLessThan( *amISorted[i])) return false;
    }
    return true;
}

//the vector merger is set to result of merging the two vectors vec1 and vec2 in sorted order
void merge( vector<IComparable *> & merger, vector<IComparable *> vec1, vector<IComparable *> vec2 ){
    merger.clear();

    int i, j, k;

    for ( i=0,j=0,k=0 ; i < vec1.size() && j < vec2.size() ; k++ ){
        if ( vec1[i]->isLessThan( *vec2[j]) ){
            merger.push_back( vec1[i]);
            i++;
        }
        else if ( vec2[j]->isLessThan( *vec1[i])){
            merger.push_back( vec2[j]);
            j++;
        }

    }

    while ( i < vec1.size() ){
        merger.push_back( vec1[i] );
        i++;
    }

    while( j < vec2.size() ){
        merger.push_back( vec2[j]);
        j++;
    }

}

void mergeSort( vector<IComparable *> & vec ){
    queue< vector<IComparable *> > * mergeQ = new queue< vector<IComparable *> >;
    vector<IComparable* > * merger = new vector<IComparable*>;

    //push each element of the vector onto the queue
    for (int i = 0; i < vec.size(); i++ ){
        mergeQ->push( vector<IComparable *>( 1, vec[i] ));
    }

    while ( mergeQ->size() > 1 ){
        vector<IComparable *> numOne;
        vector<IComparable *> numTwo;
        numOne = mergeQ->front();
        mergeQ->pop();
        numTwo = mergeQ->front();
        mergeQ->pop();
        merge( *merger, numOne, numTwo );
        mergeQ->push( *merger );
    }

    vec = mergeQ->front();

    merger->clear();
    delete merger;
    delete mergeQ;

}