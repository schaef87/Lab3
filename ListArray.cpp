/*
 * ListArray.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: schaeferj
 */

#include "ListArray.h"

template < typename DataType>
List<DataType>::List(int maxNumber){
	maxSize = maxNumber;
	size = 0;
	cursor = -1; //If it breaks....John's fault. :)

<<<<<<< HEAD
	dataItems = new DataType[maxNumber];
=======
	dataItems = new DataType[maxSize];
>>>>>>> origin/master
}

template < typename DataType>
List<DataType>::List(const List& source){
	maxSize = source.maxSize;
	size = source.size;
	cursor = source.cursor;

	dataItems = source.dataItems;
}

template < typename DataType>
<<<<<<< HEAD
List<DataType>& List<DataType>::operator= ( const List& source ){
=======
List& List<DataType>::operator= (const List& source){
>>>>>>> origin/master
	if(maxSize != source.maxSize){
		maxSize = source.maxSize;
		size = source.size;
		cursor = source.cursor;
		dataItems = source.dataItems;

		return* this;
	}
}

template < typename DataType>
<<<<<<< HEAD
List<DataType>::~List(){
	maxSize = 0;
	size = 0;
	cursor = 0;
=======
virtual List<DataType>::~List(){
>>>>>>> origin/master
	delete dataItems;
//	maxSize = 0;
//	size = 0;
//	cursor = 0;
}

template < typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
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
<<<<<<< HEAD
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
=======
virtual void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
>>>>>>> origin/master
	if(size == 0){
		throw logic_error("Nothing to replace.");
	} else {
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType>
void List<DataType>::clear(){
<<<<<<< HEAD
	if(size > 0){
		int s = size;

		for(int x = s; x >= 0; x--){
			dataItems[x] = 0;
		}
		size = 0;
		cursor = 0;
	}
=======
	int s = cursor;

	for(int x = s; x <= 0; x--){
		dataItems[x] = 0;
	}
	size = 0;
	cursor = 0;
>>>>>>> origin/master
}
