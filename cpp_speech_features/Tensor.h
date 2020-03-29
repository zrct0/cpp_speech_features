#pragma once
#include "Array.h"
namespace cpp_speech_features
{
	class Tensor
	{

	public:
		Tensor(Array * shape, Array *data);
		~Tensor();
		void toString(char **pp_char);
	private:
		Array *shape;
		Array *data;					
	};
}
