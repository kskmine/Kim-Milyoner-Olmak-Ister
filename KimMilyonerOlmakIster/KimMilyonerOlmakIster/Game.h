#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Question.h"
#include "Score.h"

using namespace std;

class Game
{
public:
	Game();
	Game(vector<Question> questions, vector<Score> scores);
	~Game();

	void Start();
	void WriteScoreList(int howMany);
	void PlayGame();
	int ShowScoreBoard();
	Question* GetRandomQuestion(int level);
	vector<Question> QuestionsInLevel(int level);
	bool AskQuestion(Question question);
	void WriteQuestion(Question question);
	bool AnswerTheQuestion(Question question);
	Question UseJoker(Question &question, int *maxTryCount);
	void GameFailed();
	void FinishGame();

private:
	vector<Question> questions;
	vector<Score> scores;
	int level;
	vector<string> jokers;
	vector<int> awards;
	bool isQuitGame = false;
};

