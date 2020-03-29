#include "pch.h"
#include "Array.h"
#include <iostream>

namespace cpp_speech_features {

	int AutoGC::survivalCount = 0;
	bool AutoGC::GC_Enable = false;
	int AutoGC::GC_pIndex = 0;
	gctype * AutoGC::GC_pArray[gcmax] = { nullptr };

	void AutoGC::startGC()
	{
		GC_Enable = true;		
	}

	void AutoGC::insert(gctype * p)
	{
		if (!GC_Enable) {
			return;
		}
		bool insertSuccessed = false;
		for (int i = 0; i < gcmax; ++i) {
			if (GC_pArray[i] == nullptr) {
				if (i == 10) {
					std::cout << i << std::endl;
				}
				GC_pArray[i] = p;
				++survivalCount;
				insertSuccessed = true;
				break;
			}
		}
		if (!insertSuccessed) {
			throw "AutoGC insert object fail";
		}
	}

	int AutoGC::releaseAllWithout(gctype * p)
	{
		int p_char_size = 100;
		char * p_char = new char[p_char_size];
		strcpy_s(p_char, p_char_size, ">>>释放内存：\n>>>释放前");
		sprintf_s(p_char, p_char_size, "%s：%d", p_char, survivalCount);

		int releaseCount = 0;
		int skipCount = 0;
		for (int i = 0; i < gcmax; ++i) {
			if (GC_pArray[i] != nullptr) {
				gctype *c = GC_pArray[i];
				if (c != p) {
					delete c;
					GC_pArray[i] = nullptr;
					++releaseCount;
				}
				else {
					++skipCount;
				}
			}
		}		
		survivalCount -= releaseCount;
		GC_Enable = false;
		
		sprintf_s(p_char, p_char_size, "%s, 释放后：%d", p_char, survivalCount);
		sprintf_s(p_char, p_char_size, "%s, 本次释放：%d个对象", p_char, releaseCount);
		std::cout << p_char << std::endl;

		return releaseCount;
	}
	void AutoGC::print(const char * tag)
	{
		int p_char_size = 500;
		char * p_char = new char[p_char_size];		
		if (tag != nullptr) {
			strcpy_s(p_char, p_char_size, tag);
		}
		sprintf_s(p_char, p_char_size, " 当前存活对象：%d",survivalCount);
		std::cout << p_char << std::endl;
	}


}
