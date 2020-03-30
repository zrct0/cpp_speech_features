#pragma once
#define accuracy float
namespace cpp_speech_features {
	class Array
	{
	public:
		template<typename... T>
		Array(T ...args);
		void release();
	private:
		accuracy * pArray[];		
		~Array();
	};
}

