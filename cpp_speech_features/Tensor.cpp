#include "pch.h"
#include "Tensor.h"
#include <iostream>

namespace cpp_speech_features {

	Tensor::Tensor(Array * shape, Array *data)
	{
		if (shape == nullptr) {
			throw "shape == nullptr";
		}
		if (data == nullptr) {
			throw "data == nullptr";
		}		
		if (data->getSize() != shape->insideEleMul()) {
			throw "Array length and dimension do not match";
		}
		this->shape = shape;
		this->data = data;	
	}

	

	Tensor::~Tensor()
	{		
		delete shape;
		delete data;	
	}

	void Tensor::toString(char **pp_char)
	{				
		int p_char_size = data->getSize() * 10;
		char * p_char = new char[p_char_size];
		*pp_char = p_char;
		int shapeSize = shape->getSize();
		int dataSize = data->getSize();
		int dataIndex = 0;
		int lastDimSize = (int)(*shape)[shapeSize - 1];
		int dataShape;
		strcpy_s(p_char, p_char_size, "shape:");
		char *pshapeStr;
		shape->toString(&pshapeStr);
		sprintf_s(p_char, p_char_size, "%s%s\n", p_char, pshapeStr);		
		for (int i = 0; i < shapeSize; i++) {		
			dataShape = (int)(*shape)[i];
			strcat_s(p_char, p_char_size, "[");
			for (int j = 0; j < dataShape - 1; j++) {				
				for (int k = 0; k < lastDimSize - 1; k++) {
					sprintf_s(p_char, p_char_size, "%s%.2lf, ", p_char, (*data)[dataIndex]);
					++dataIndex;
				}
				sprintf_s(p_char, p_char_size, "%s%.2lf]\n", p_char, (*data)[dataIndex]);
				++dataIndex;
			}				
		}		
	}
	
}
