#include "pch.h"
#include "Array.h"
#include <iostream>

namespace cpp_speech_features {
		
	Array::Array(int size):Matrix(size, 1)
	{
		if (size <= 0) {
			throw std::exception("size <= 0");
		}		
		this->size = size;		
	}

	Array::Array(int size, arrtype array) :Matrix(size, 1, array)
	{		
		if (size <= 0) {
			throw std::exception("size <= 0");
		}		
		this->size = size;		
	}

	Array::Array(Matzix m) :Matrix(m->getColumn(), 1) { 

		if (m == nullptr) {
			throw std::exception("Array construction m == nullptr");
		}		
		if (m->getRow() != 1) {
			throw std::exception("Array 's row must be 1");
		}
		this->size = m->getColumn() * m->getRow();		
		for (int i = 0; i < this->size; i++) {
			set(i, m->get(i));
		}
	}

	Array::~Array()
	{
		//std::cout << "realse Array " << this << std::endl;
	}


	int Array::getSize()
	{
		return this->size;
	}

	Azzay Array::arange(accuracy start, accuracy end, accuracy step)
	{		
		int length = (int)((end - start) / step);
		Azzay narray = create_azzay(length);
		int index = 0;
		for (accuracy i = start; i <= end; i += step) {
			narray->set(index++, i);
		}
		return narray;
	}

	Azzay Array::skip(int s)
	{
		int abss = abs(s);
		if (abss >= size) {
			throw std::exception("skip size >= array size");
		}
		Azzay narray = create_azzay(size - abss);
		if (s > 0) {			
			int index = 0;
			for (int i = abss; i < size; i++) {
				narray->set(index++, get(i));
			}			
		}
		else {			
			for (int i = 0; i < size - abss; i++) {
				narray->set(i, get(i));
			}			
		}
		return narray;
	}

	Azzay Array::take(int s)
	{
		int abss = abs(s);
		if (abss >= size) {
			throw std::exception("take size >= array size");
		}
		Azzay narray = create_azzay(abss);
		if (s > 0) {
			for (int i = 0; i < s; i++) {
				narray->set(i, get(i));
			}
		}
		else {
			int index = 0;
			for (int i = size - abss; i < size; i++) {
				narray->set(index++, get(i));
			}
		}
		return narray;
	}	

	Azzay Array::multiply(accuracy b)
	{
		return create_azzay(Matrix::multiply(b));
	}

	Azzay Array::subtract(Azzay b)
	{
		return create_azzay(Matrix::subtract(b));
	}

	
	Azzay Array::concatenate(Azzay b)
	{
		return create_azzay(Matrix::concatenate(b));
	}

	Azzay Array::concatenate(accuracy a, Azzay b)
	{
		if (b == nullptr) {
			throw std::exception("concatenate b == nullptr");
		}
		int new_size = b->getSize() + 1;
		Azzay narray = create_azzay(new_size);
		narray->set(0, a);
		for (int i = 1; i < new_size; i++) {
			narray->set(i, b->get(i - 1));
		}
		return narray;
	}

	void Array::print()
	{
		int p_char_size = 100;
		char *p_char = new char[p_char_size];		
		strcpy_s(p_char, p_char_size, "size:");
		sprintf_s(p_char, p_char_size, "%s%d[", p_char, size);
		for (int i = 0; i < size - 1; ++i) {
			if (size < (display_accuracy * 2) || i < display_accuracy || i > size - (display_accuracy + 1)) {
				sprintf_s(p_char, p_char_size, "%s%.2lf, ", p_char, get(i));
				if (i == display_accuracy - 1) {
					strcat_s(p_char, p_char_size, "... , ");
				}
			}
		}
		sprintf_s(p_char, p_char_size, "%s%.2lf]", p_char, get(size - 1));
		std::cout << p_char;
		delete p_char;
	}
}