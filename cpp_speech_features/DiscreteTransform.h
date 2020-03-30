#pragma once
#include "Vector.h"
namespace cpp_speech_features {
	class DiscreteTransform
	{
	public:		
		static Matrixp dct(Matrixp data);
		static Vectorp dctWithOrtho(Vectorp data);
		static void rfft(accuracy * x, int n);

	};
}

