#pragma once
#include "AutoGC.h"
#include <memory>
#define accuracy float
#define arrtype std::shared_ptr<accuracy>
#define create_shared_ptr(size, ...) std::shared_ptr<accuracy>(new accuracy[size] {__VA_ARGS__} , [](accuracy *p) {delete[] p; })
#define Matzix std::shared_ptr<Matrix>
#define create_matzix(...) std::shared_ptr<Matrix> (new Matrix( __VA_ARGS__ ))
#define Azzay std::shared_ptr<Array>
#define create_azzay(...) std::shared_ptr<Array> (new Array( __VA_ARGS__ ))
#define create_azzay_by_array(size, ...) std::shared_ptr<Array> (new Array(size, create_shared_ptr(size, __VA_ARGS__ )))
#define display_accuracy 3
namespace cpp_speech_features {
	class Array;
	class Matrix 
	{
	public:
		Matrix(int col, int row);
		Matrix(int col, int row, arrtype data);
		~Matrix();
		accuracy get(int x);
		accuracy get(int y, int x);		
		void set(int x, accuracy v);
		void set(int y, int x, accuracy v);
		int getColumn();
		int getRow();
		arrtype getData();
		Azzay getRow(int row);
		Matzix multiply(Matzix b);
		Matzix multiply(accuracy b);
		Matzix subtract(Matzix b);
		Matzix add(Matzix b);
		Matzix concatenate(Matzix b);		
		Matzix reshape(int col, int row);
		Matzix T();		
		void print();
	protected:
		arrtype pArray;
		void createZerosArray(int size);
	private:	
		int column;
		int row;
		
	};
}

