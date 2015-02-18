#include "ListArray.h"

template < typename DataType>
List<DataType>::List(int maxNumber){
	maxSize = maxNumber;
	size = 0;
	cursor = -1; //If it breaks....John's fault. :)

	dataItems = new DataType[maxSize];
}

template < typename DataType>
List<DataType>::List(const List& source){
	maxSize = source.maxSize;
	size = source.size;
	cursor = source.cursor;

	dataItems = new DataType[maxSize];
	*dataItems = *source.dataItems;
}

template < typename DataType>
List<DataType>& List<DataType>::operator= ( const List& source ){

	if(maxSize != source.maxSize){
		maxSize = source.maxSize;
		size = source.size;
	}

	return *this;
}

template < typename DataType>
List<DataType>::~List(){
	maxSize = 0;
	size = 0;
	cursor = 0;
	delete dataItems;
}

template < typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
	if(cursor > maxSize){
		throw logic_error("Not Enough Space");
	} else {
		dataItems[cursor] = newDataItem;
		cursor++;
	}
}

template < typename DataType>
void List<DataType>::remove () throw ( logic_error ){

	if(size == 0){
		throw logic_error("Nothing to delete.");
	} else {
		dataItems[cursor] = 0;
		cursor--;
		size--;
	}
}

template < typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
	if(size == 0){
		throw logic_error("Nothing to replace.");
	} else {
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType>
void List<DataType>::clear(){
	if(size > 0){
		int s = size;

		for(int x = s; x >= 0; x--){
			dataItems[x] = 0;
		}
		size = 0;
		cursor = 0;
	}
}

template < typename DataType>
bool List<DataType>::isEmpty() const{  //Member not found???
	if(size > 0){
		return false;
	} else {
		return true;
	}
}

template < typename DataType>
bool List<DataType>::isFull() const{  //Member not found???
	if(size >= maxSize){
		return true;
	} else {
		return false;
	}
}

template < typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
	if(cursor != 0){
		cursor = 0;
	} else {
		throw logic_error("Already at the beginning.");
	}
}

template < typename DataType>
void List<DataType>::gotoEnd() throw (logic_error){
	if(cursor != maxSize){
		cursor = maxSize;
	} else {
		throw logic_error("Already at the end.");
	}
}

template < typename DataType>
bool List<DataType>::gotoNext() throw (logic_error){
	if(cursor == maxSize){
		throw logic_error("Cannot go to next, already at the end.");
		return false;
	} else {
		cursor++;
		return true;
	}
}

template < typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error){
	if(cursor == maxSize){
		throw logic_error("Cannot go back, already at the beginning.");
		return false;
	} else {
		cursor--;
		return true;
	}
}

template < typename DataType>
DataType List<DataType>::getCursor() const throw(logic_error){
	if(dataItems[cursor] == 0){
		throw ("There is nothing to retrieve.");
	} else {
		return dataItems[cursor];
	}
}

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



//template < typename DataType>
//void moveToNth(int n) throw (logic_error){
//	if(n > maxSize || n < 0){
//		throw logic_error("Out of bounds.");
//	} else {
//
//	}
//}
