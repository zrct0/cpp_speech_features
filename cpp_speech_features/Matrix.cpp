#include "pch.h"
#include "Array.h"
#include <iostream>

namespace cpp_speech_features {
	
	Matrix::Matrix(int col, int row)
	{
		if (col <= 0 || row <= 0) {
			throw std::exception("col <= 0 || row <= 0");
		}		
		this->column = col;
		this->row = row;
		createZerosArray(col * row);
		AutoGC::insert(this);
	}

	Matrix::Matrix(int col, int row, arrtype data)
	{
		if (col <= 0 || row <= 0) {
			throw std::exception("col <= 0 || row <= 0");
		}		
		
		this->column = col;
		this->row = row;	
		pArray = data;
	}

	void Matrix::createZerosArray(int size)
	{		
		pArray = std::shared_ptr<accuracy>(new accuracy[size], [](accuracy *p) {delete[] p; });
	}

	Matrix::~Matrix()
	{
		std::cout << "realse Matrix " << pArray << std::endl;		
	}

	accuracy Matrix::get(int x)
	{
		return pArray.get()[x];
	}

	accuracy Matrix::get(int y, int x) {
		return pArray.get()[y * column + x];
	}

	void Matrix::set(int x, accuracy v)
	{
		pArray.get()[x] = v;
	}

	void Matrix::set(int y, int x, accuracy v) {
		pArray.get()[y * column + x] = v;
	}

	int Matrix::getColumn()
	{
		return column;
	}

	int Matrix::getRow()
	{
		return row;
	}

	arrtype Matrix::getData()
	{
		return pArray;
	}

	Azzay Matrix::getRow(int row)
	{
		Azzay narray = create_azzay(column);
		for (int i = 0; i < column; ++i) {
			narray->set(i, get(row, i));
		}
		return narray;
	}
		
	Matzix Matrix::multiply(Matzix b) {
		if (b == nullptr) {
			throw std::exception("multiply b == nullptr");
		}
		if (column != b->row) {
			throw std::exception("A's column do not match and B's row");
		}
		Matzix nm = create_matzix(b->column, row);
		accuracy cellValue;
		for (int x = 0; x < b->column; ++x) {
			for (int y = 0; y < row; ++y) {
				cellValue = 0;
				for (int i = 0; i < column; ++i) {
					cellValue += get(y, i) * b->get(i, x);
				}
				nm->set(y, x, cellValue);
			}
		}
		return nm;
	}

	
	Matzix Matrix::multiply(accuracy b)
	{
		Matzix nm = create_matzix(column, row);
		for (int x = 0; x < column; ++x) {
			for (int y = 0; y < row; ++y) {						
				nm->set(y, x, get(y, x) * b);
			}
		}
		return nm;
	}

	
	Matzix Matrix::subtract(Matzix b)
	{
		if (b == nullptr) {
			throw std::exception("subtract b == nullptr");
		}
		if (row != b->row && column != b->column) {
			throw std::exception("A's dimension do not match and B's dimension");
		}

		Matzix nm = create_matzix(column, row);
		for (int x = 0; x < column; ++x) {
			for (int y = 0; y < row; ++y) {
				nm->set(y, x, get(y, x) - b->get(y, x));
			}
		}
		return nm;
	}

	Matzix Matrix::add(Matzix b)
	{
		if (b == nullptr) {
			throw std::exception("add b == nullptr");
		}
		if (row != b->row && column != b->column) {
			throw std::exception("A's dimension do not match and B's dimension");
		}

		Matzix nm = create_matzix(column, row);
		for (int x = 0; x < column; ++x) {
			for (int y = 0; y < row; ++y) {
				nm->set(y, x, get(y, x) + b->get(y, x));
			}
		}
		return nm;
	}
	
	Matzix Matrix::concatenate(Matzix b)
	{
		if (b == nullptr) {
			throw std::exception("concatenate b == nullptr");
		}
		if (row != b->row ) {
			throw std::exception("the matrix must have the same row");
		}
		int newColumn = column + b->column;
		Matzix nm = create_matzix(newColumn, row);
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < newColumn; ++x) {
				if (x < column) {
					nm->set(y, x, get(y, x));
				}
				else
				{
					nm->set(y, x, b->get(y, x - column));
				}
			}
		}
		return nm;
	}

	Matzix Matrix::reshape(int col, int row)
	{		
		Matzix nm = create_matzix(col, row);
		arrtype data = nm->getData();
		for (int i = 0; i < col * row; ++i) {
			set(i, nm->get(i));
		}
		return nm;
	}

	Matzix Matrix::T()
	{
		Matzix nm = create_matzix(row, column);
		for (int x = 0; x < column; ++x) {
			for (int y = 0; y < row; ++y) {
				nm->set(x, y, get(y, x));
			}
		}
		return nm;
	}

	void Matrix::print()
	{
		int p_char_size = column * row * 10;
		char * p_char = new char[p_char_size];		
		strcpy_s(p_char, p_char_size, "");		
		int dataIndex = 0;
		for (int y = 0; y < row; ++y) {
			sprintf_s(p_char, p_char_size, "%s[%5.2lf, ", p_char, get(dataIndex++));
			for (int x = 1; x < column - 1; ++x) {
				if (column < (display_accuracy * 2) || x < (display_accuracy) || x > column - (display_accuracy + 1)) {					
					sprintf_s(p_char, p_char_size, "%s%5.2lf, ", p_char, get(dataIndex));
					if (x == display_accuracy - 1 && column >= (display_accuracy * 2)) {
						strcat_s(p_char, p_char_size, "... , ");
					}
				}
				++dataIndex;
			}
			sprintf_s(p_char, p_char_size, "%s%5.2lf]\n", p_char, get(dataIndex++));
		}
		sprintf_s(p_char, p_char_size, "%ssize:%d x %d \n", p_char, row, column);
		std::cout << p_char;
		delete[] p_char;
	}
	
}