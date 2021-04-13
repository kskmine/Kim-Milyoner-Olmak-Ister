#include "stdafx.h"
#include "Question.h"

Question::Question()
{
}

Question::Question(int QuestionId, int Level, string question, string ChoiceA, string ChoiceB, string ChoiceC, string ChoiceD, char CorrectChoice)
{
	questionId = QuestionId;
	level = Level;
	this->question = question;
	choiceA = ChoiceA;
	choiceB = ChoiceB;
	choiceC = ChoiceC;
	choiceD = ChoiceD;
	correctChoice = CorrectChoice;
}

Question::~Question()
{
}

string Question::GetQuestion()
{
	return question;
}

int Question::GetLevel()
{
	return level;
}

string Question::GetChoiceA()
{
	return choiceA;
}

string Question::GetChoiceB()
{
	return choiceB;
}

string Question::GetChoiceC()
{
	return choiceC;
}

string Question::GetChoiceD()
{
	return choiceD;
}

char Question::GetCorrectChoice()
{
	return correctChoice;
}

void Question::removeChoiceA() {
	choiceA = "";
}

void Question::removeChoiceB() {
	choiceB = "";
}

void Question::removeChoiceC() {
	choiceC = "";
}

void Question::removeChoiceD() {
	choiceD = "";
}