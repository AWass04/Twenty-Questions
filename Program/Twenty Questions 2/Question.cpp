#include "Question.h"
#include <iostream>

using namespace std;

Question::Question() {

	num1;
	num2;
	userAnswer;

}

void Question :: Display() {

	cout << num1 << " " << GetSymbol() << " " << num2 << "? ";

}

void Question :: SetUserAnswer() {

	int answer;

	bool validAnswer = true;
	
	do {
		
		cin >> answer;

		// Error handeling - if answer is not an integar clear the last answer and make user input an int
		if (cin.fail()) { 

			cout << "\nInvalid input! Please enter an integer: ";
			cin.clear();
			cin.ignore();

			validAnswer = false;
		}
		else {
			userAnswer = answer;
			break;
		}
	} while (!validAnswer); 
}

int Question::TrueAnswer() {

	char addOrSubtract = GetSymbol(); // Workout if its supposed to be a add or subtract question

	// Calculate the correct answer
	if (addOrSubtract == '+') return num1 + num2;
	else return num1 - num2;
}

bool Question::CompareAnswers() {

	if (TrueAnswer() == userAnswer) return true;
	else return false;
}

void Question::DisplayCorrectlyAnswered() {

	cout << num1 << " " << GetSymbol() << " " << num2 << " = " << userAnswer << "\n";

}

void Question::DisplayWronglyAnswered() {

	cout << num1 << " " << GetSymbol() << " " << num2 << " = " << TrueAnswer() << " you answered with " << userAnswer << "\n";

}