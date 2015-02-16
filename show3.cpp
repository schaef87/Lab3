//--------------------------------------------------------------------
//
//  Laboratory 3                                          show3.cpp
//
//  Array implementation of the showStructure operation for the
//  List ADT
//
//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: showStructure () const

// outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
    int j;   // loop counter

    if ( size == 0 )
       cout << "empty list" << endl;
// The Ordered List code blows up below. Since this is just debugging
// code, we check for whether the OrderedList is defined, and if so,
// print out the key value. If not, we try printing out the entire item.
// Note: This assumes that you have used the double-inclusion protection
// in your OrderedList.cpp file by doing a "#ifndef ORDEREDLIST_CPP", etc.
// If not, you will need to comment out the code in the section under 
// the "else", otherwise the compiler will go crazy in lab 4.
// The alternative is to overload operator<< for all data types used in
// the ordered list.
    else
    {
       cout << "size = " << size
            <<  "   cursor = " << cursor << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ ) {
	   if( j == cursor ) {
	      cout << "[";
              cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
	      .getKey()
#endif
	      ;
	      cout << "]";
 	      cout << "\t";
	   }
	   else
	      cout << dataItems[j] 
#ifdef ORDEREDLIST_CPP
	      .getKey()
#endif
	      << "\t";
       }
       cout << endl;
    }
}

