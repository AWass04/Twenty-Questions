#pragma once
#include "Question.h"

class Addition : public Question
{
	public:
		Addition(int n1, int n2) : Question(n1, n2) {}
	
	protected:	
		virtual char GetSymbol();


	private:
};

