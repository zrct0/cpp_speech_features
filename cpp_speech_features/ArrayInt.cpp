#include "pch.h"
#include "ArrayInt.h"
#include <iostream>

namespace cpp_speech_features {

	ArrayInt::ArrayInt(void * array, int size):Array(array, size)
	{
		this->pArray = (int*)array;
	}


	ArrayInt::~ArrayInt()
	{
		delete [] pArray;
	}

	void * ArrayInt::operator[](int i)
	{		
		return &pArray[i];
	}
}
