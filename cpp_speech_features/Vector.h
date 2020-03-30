#pragma once
#include "Matrix.h"
#include <math.h>
namespace cpp_speech_features {
 	
	class Vector : public Matrix
	{
	public:
		Vector(int size);
		Vector(int size, arrtype array);
		Vector(Matrixp m);
		~Vector();
		int getSize();
		static Vectorp arange(accuracy start, accuracy end, accuracy step = 1);
		Vectorp skip(int s);
		Vectorp take(int s);		
		Vectorp multiply(accuracy b);
		Vectorp subtract(Vectorp b);
		Vectorp concatenate(Vectorp b);
		accuracy sum();
		static Vectorp concatenate(accuracy a, Vectorp b);		
	protected:		
		int size;
	private:
		
	};


}

