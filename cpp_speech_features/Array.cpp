#include "pch.h"
#include "Array.h"

namespace cpp_speech_features {
	template<typename... T>
	Array::Array(T... args)
	{
		int size = sizeof...(args);
		pArray = new accuracy[size];
		int index = 0;
		for (auto x : { args... }) {
			pArray[index++] = x;
		}
	}

	void Array::release()
	{
	}

	Array::~Array()
	{
		delete[] pArray;
	}
}
