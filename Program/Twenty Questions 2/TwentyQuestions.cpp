#include <iostream>
#include "Question.h"
#include "Addition.h"
#include "Subtraction.h"

using namespace std;

int main() {

	#ifdef _DEBUG
		//_CrtSetBreakAlloc();
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	cout << "Weclome to twenty questions!\n";
	cout << "----------------------------\n";
	cout << "Twenty random addition or subtraction questions with operands between 1 and 20. How many can you get right ?\n\n";

	// Creating an array of 20 questions
	const int NO_OF_QUESTIONS = 20;
	Question* questions[NO_OF_QUESTIONS];

	srand(time(nullptr));
	

	for (int i = 0; i < NO_OF_QUESTIONS; i++) {

		int num1 = rand() % 20 + 1; // Get a random number between 1 and 20
		int num2 = rand() % 20 + 1; // Get a random number between 1 and 20
		int addOrSubtract = rand() % 2; // // Get a random number between 0 and 1
		int userAnswer;

		cout << "Question " << i+1 << ": ";

		switch (addOrSubtract)
		{
		case 0:

			questions[i] = new Addition(num1, num2); 

			break;
		case 1:

			questions[i] = new Subtraction(num1, num2);

			break;
		}

		questions[i]->Display();

		questions[i]->SetUserAnswer();
	}

	cout << "\nCorrectly Answered\n";
	cout << "------------------\n\n";
	
	for (int i = 0; i < NO_OF_QUESTIONS; i++) {
		if (questions[i]->CompareAnswers() == true) questions[i]->DisplayCorrectlyAnswered();
	}

	cout << "\nand the wrong asnwers\n";
	cout << "------------------\n\n";

	for (int i = 0; i < NO_OF_QUESTIONS; i++) {
		if (questions[i]->CompareAnswers() == false) questions[i]->DisplayWronglyAnswered();
	}

	return 0;
}