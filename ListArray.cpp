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
