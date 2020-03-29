#pragma once
#include "Array.h"
#define int_array_get(data, i) *(int*)(*data)[i]
namespace cpp_speech_features {
	class ArrayInt :public Array
	{
	public:
		ArrayInt(void * array, int size);
		~ArrayInt();
		void* operator[](int i);
	private:
		int * pArray;
	};
}

