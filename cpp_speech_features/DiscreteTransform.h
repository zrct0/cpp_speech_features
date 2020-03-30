#pragma once
#include "Vector.h"
#define M_PI 3.14159265358979323846
namespace cpp_speech_features {
	class DiscreteTransform
	{
	public:		
		static Matrixp dct(Matrixp data);
		static Vectorp dctWithOrtho(Vectorp data, accuracy scale);
		static void rfft(accuracy * x, int n);

	};
}

