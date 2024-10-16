#pragma once

class Question
{
	public:
		Question();
		Question(int n1, int n2) : num1(n1), num2(n2) {}
		
		void SetUserAnswer();

		void Display();
		void DisplayCorrectlyAnswered();
		void DisplayWronglyAnswered();
		
		int TrueAnswer();
		bool CompareAnswers();

	protected:
		virtual char GetSymbol() = 0;

	private:
		int num1;
		int num2;
		int userAnswer;
};

