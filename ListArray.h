//--------------------------------------------------------------------
//
//  Laboratory 3                                           ListArray.h
//  **Instructor's Solution**
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType >
class List
{
  public:

    static const int MAX_LIST_SIZE = 10;   // Default maximum list size

    // Constructors
    List ( int maxNumber = MAX_LIST_SIZE );	// Default constructor
    List ( const List& source );		// Copy constructor
    
    // Overloaded assignment operator
    List& operator= ( const List& source );

    // Destructor
    virtual ~List ();

    // List manipulation operations
    virtual void insert ( const DataType& newDataItem )  // Insert after cursor
	throw ( logic_error );  
    void remove () throw ( logic_error );        // Remove data item
    virtual void replace ( const DataType& newDataItem ) // Replace data item
	throw ( logic_error ); 
    void clear ();                               // Clear list

    // List status operations
    bool isEmpty () const;                    // List is empty
    bool isFull () const;                     // List is full

    // List iteration operations
    void gotoBeginning ()                     // Go to beginning
        throw ( logic_error );
    void gotoEnd ()                           // Go to end
        throw ( logic_error );
    bool gotoNext ()                          // Go to next data item
        throw ( logic_error );
    bool gotoPrior ()                         // Go to prior data item
        throw ( logic_error );
    DataType getCursor () const
        throw ( logic_error );                // Return data item

    // Output the list structure -- used in testing/debugging
    virtual void showStructure () const;

    // In-lab operations
    void moveToNth ( int n )                  // Move data item to pos. n
        throw ( logic_error );  
    bool find ( const DataType& searchDataItem )     // Find data item
        throw ( logic_error );  

  protected:

    // Data members
    int maxSize,
        size,             // Actual number of data item in the list
        cursor;           // Cursor array index
    DataType *dataItems;  // Array containing the list data item
};

#endif

