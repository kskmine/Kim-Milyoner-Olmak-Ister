// KimMilyonerOlmakIster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KimMilyonerOlmakIster.h"

using namespace std;

int main()
{
	string questionFileName = "question.csv";
	string scoreFileName = "score.csv";
	vector<Question> questions;
	vector<Score> scores;
	ScoreLoadFromFileName(scoreFileName, scores);
	QuestionLoadFromFileName(questionFileName, questions);

	Game game(questions, scores);
	game.Start();

    return 0;
}

void ScoreLoadFromFileName(string fileName, vector<Score> &scores) {
	ifstream file;
	file.open(fileName);

	string line;
	while (getline(file, line))
	{
		vector<string> parsedData = ParseStringToVector(line, ',');
		scores.push_back(
			Score(
				ReplaceString(parsedData.at(0)),
				ReplaceString(parsedData.at(1)),
				StringToInteger(parsedData.at(2))
			)
		);
	}

	file.close();

	cout << endl << "Scores are loaded!" << endl;
}

void QuestionLoadFromFileName(string fileName, vector<Question> &questions) {
	ifstream file;
	file.open(fileName);

	string line;
	while (getline(file, line))
	{
		vector<string> parsedData = ParseStringToVector(line, ',');

		questions.push_back(
			Question(
				StringToInteger(
					ReplaceString(parsedData.at(0))
				),
				StringToInteger(
					ReplaceString(parsedData.at(1))
				),
				ReplaceString(parsedData.at(2)),
				ReplaceString(parsedData.at(4)),
				ReplaceString(parsedData.at(5)),
				ReplaceString(parsedData.at(6)),
				ReplaceString(parsedData.at(7)),
				ReplaceString(parsedData.at(8))[0]
			)
		);
	}

	file.close();

	cout << endl << "Questions are loaded!" << endl;
}

vector<string> ParseStringToVector(string rawData, char splitChar) {
	vector<string> temp;
	int i;
	string temptext = "";
	for (i = 0; i < rawData.length(); i++)
	{
		if (rawData[i] == splitChar)
		{
			temp.push_back(temptext);
			temptext = "";
		}
		else {
			temptext += rawData[i];
		}
	}
	temp.push_back(temptext);

	return temp;
}

string ReplaceString(string text, char replaceChar) {
	string temp;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != replaceChar)
		{
			temp.push_back(text[i]);
		}
	}

	return temp;
}

int StringToInteger(string number) {
	return atoi(number.c_str());
}