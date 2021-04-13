#pragma once
#include <string>

using namespace std;
class Score
{
public:
	Score(string Name, string Surname, int Score = 0);
	Score();
	~Score();

	int GetScore();
	string GetName();
	string GetSurname();
	
private:
	int score;
	string name;
	string surname;
};

