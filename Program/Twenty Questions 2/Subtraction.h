#pragma once
#include "Question.h"

class Subtraction : public Question
{
	public:
		Subtraction(int num1, int num2) : Question(num1, num2) {}

	protected:
		virtual char GetSymbol();


	private:


};

