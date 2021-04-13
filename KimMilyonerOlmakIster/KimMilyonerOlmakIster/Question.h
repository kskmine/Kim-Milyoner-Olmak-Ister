#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;
class Question
{
public:
	Question();
	Question(int questionId, int level, string question, string choiceA, string choiceB, string choiceC, string choiceD, char correctChoice);
	~Question();

	string GetQuestion();
	int GetLevel();
	string GetChoiceA();
	string GetChoiceB();
	string GetChoiceC();
	string GetChoiceD();
	char GetCorrectChoice();
	void removeChoiceA();
	void removeChoiceB();
	void removeChoiceC();
	void removeChoiceD();

private:
	int questionId;
	int level;
	string question;
	string choiceA;
	string choiceB;
	string choiceC;
	string choiceD;
	char correctChoice;
};

