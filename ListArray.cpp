/*
 * ListArray.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: schaeferj
 */

#include "ListArray.h"

template < typename DataType>

List List<DataType>::List(int maxNumber){
	int maxSize = maxNumber;
	int size = 0;
	int cursor = -1; //If it breaks....John's fault. :)

	DataType* dataItems;
}

template < typename DataType>
List List<DataType>::List(const List& source){
	int maxSize = source.maxSize;
	int size = source.size;
	int cursor = source.cursor;

	DataType* dataItems;
}

template < typename DataType>
List& List<DataType>::operator= ( const List& source ){
	if(maxSize != source.maxSize){
		maxSize = source.maxSize;
		size = source.size;
		cursor = source.cursor;
		dataItems = source.dataItems;

		return* this;
	}
}

template < typename DataType>
virtual List<DataType>::~List(){
	delete maxSize;
	delete size;
	delete cursor;
	delete dataItems;
}

template < typename DataType>
virtual void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
	if(cursor > maxSize){
		throw logic_error("Not enough space");
	}else if(size == 0){
		dataItems[0] = newDataItem;
		cursor++;
		size++;
	} else {
		dataItems[cursor] = newDataItem;
		cursor++;
		size++;
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
virtual void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
	if(size == 0){
		throw logic_error("Nothing to replace.");
	} else {
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType>
void List<DataType>::clear(){
	int s = cursor;

	for(int x = s; x <= 0; x--){
		dataItems[x] = 0;
	}
	size = 0;
	cursor = 0;
}
