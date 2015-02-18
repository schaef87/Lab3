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

	dataItems = source.dataItems;
}

template < typename DataType>
List<DataType>& List<DataType>::operator= ( const List& source ){

	if(maxSize != source.maxSize){
		maxSize = source.maxSize;
		size = source.size;
	}
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
		throw logic_error("Not enough space");
	}else if(size == 0){
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

template < typename DataType>
void List<DataType>::showStructure () const{
	cout << "Max size: " << maxSize << endl;
	cout << "Actual size: " << size << endl;
	cout << "Cursor position: " << cursor << endl;
	cout << "Data: " << endl;

	for(int x = 0; 0 <= size; x++){
		cout << dataItems[x] << endl;
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
