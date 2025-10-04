#pragma once

#include <iostream>

template <typename T>
class MutantStack
{
	protected:
		
	public:
		MutantStack() {};
		//recopie
		//surcharge
		~MutantStack() {};

		void push(const T &x) {(void)x;};
};