#include "stdafx.h"
#include "Score.h"




Score::Score(string Name, string Surname, int Score)
{
	name = Name;
	surname = Surname;
	score = Score;
}

Score::~Score()
{
}

int Score::GetScore()
{
	return score;
}

string Score::GetName()
{
	return name;
}

string Score::GetSurname()
{
	return surname;
}


