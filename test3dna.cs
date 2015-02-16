//--------------------------------------------------------------------
//
//  Laboratory 3, In-lab Exercise 1                     test3dna.cpp
//
//  Test program for the countbases function
//
//--------------------------------------------------------------------

// Reads a DNA sequence from the keyboard, calls function countBases
// countBases (which uses a list to represent a DNA sequence), and
// outputs the number of times that each base (A, G, C and T) occurs
// in the sequence.

#include <iostream>
#include "ListArray.cpp"

using namespace std;

//--------------------------------------------------------------------
//
//  Function prototype
//

void countBases ( List<char> &dnaSequence,
                  int &aCount,
                  int &cCount,
                  int &tCount,
                  int &gCount              );

//--------------------------------------------------------------------


int main ()
{
    List<char> dnaSequence(25);   // DNA sequence (25 bases max.)
    char base;              // DNA base
    int aCount,             // Number of A's in the sequence
        cCount,             // Number of C's in the sequence
        tCount,             // Number of T's in the sequence
        gCount;             // Number of G's in the sequence

    // Read the DNA sequence from the keyboard.

    cout << endl << "Enter a DNA sequence: ";
    cin.get(base);
    while ( base != '\n' )
    {
        dnaSequence.insert(base);
        cin.get(base);
    }

    // Display the sequence.

    cout << "Sequence: ";

    if( dnaSequence.isEmpty() )
       cout << "list is empty" << endl;
    else
    {
       dnaSequence.gotoBeginning();
       do
       {
         cout << dnaSequence.getCursor() << " ";
       } while ( dnaSequence.gotoNext() );
       cout << endl;
    }

    // Count the number of times that each base occurs.

    countBases(dnaSequence,aCount,cCount,tCount,gCount);

    // Output the totals.

    cout << "Number of A's : " << aCount << endl;
    cout << "Number of C's : " << cCount << endl;
    cout << "Number of T's : " << tCount << endl;
    cout << "Number of G's : " << gCount << endl;

}

//--------------------------------------------------------------------
//
//  Insert your countBases function below.
//

