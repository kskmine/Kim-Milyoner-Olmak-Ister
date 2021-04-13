#include "stdafx.h"
#include "Game.h"

using namespace std;

Game::Game()
{
}

Game::Game(vector<Question> questions, vector<Score> scores)
{
	this->questions = questions;
	this->scores = scores;
	level = 1;
	awards.push_back(500);
	awards.push_back(1000);
	awards.push_back(2000);
	awards.push_back(3000);
	awards.push_back(5000);
	awards.push_back(7500);
	awards.push_back(15000);
	awards.push_back(30000);
	awards.push_back(60000);
	awards.push_back(125000);
	awards.push_back(250000);
	awards.push_back(1000000);
}

Game::~Game()
{
}

void Game::Start()
{
	while (true)
	{
		system("cls");
		cout << endl << "===== MAIN MENU =====" << endl << endl;

		WriteScoreList(1);

		cout << endl << endl << endl << "p \t->\tplay game" << endl << "s \t->\tshow score board" << endl << "q \t->\tquit the game" << endl << endl << "Enter a key for: ";

		switch (_getch())
		{
		case 'p':
			PlayGame();
			break;
		case 's':
			ShowScoreBoard();
			break;
		case 'q':
			exit(0);
			break;
		default:
			break;
		}
	}
}

void Game::WriteScoreList(int howMany)
{
	int how = 0;

	if (howMany >= scores.size())
	{
		how = scores.size();
	}
	else {
		how = howMany;
	}

	for (int i = 0; i < how; i++)
	{
		cout << i + 1 << "\t->\t" << scores[i].GetScore() << " | " << scores[i].GetName() << " " << scores[i].GetSurname() << endl;
	}
}

int Game::ShowScoreBoard()
{
	while (true)
	{

		system("cls");
		cout << endl << "===== SCORE BOARD =====" << endl << endl;

		for (int i = 0; i < scores.size(); i++)
		{
			cout << i + 1 << "\t->\t" << scores[i].GetScore() << " | " << scores[i].GetName() << " " << scores[i].GetSurname() << endl;
		}

		cout << endl << endl << endl << "b \t->\tback to main menu" << endl << "q \t->\tquit the game" << endl << endl << "Enter a key for: ";

		switch (_getch())
		{
		case 'b':
			return 1;
		case 'q':
			exit(0);
			break;
		default:
			break;
		}
	}
}

void Game::PlayGame()
{
	jokers.clear();
	jokers.push_back("50/50 Joker");
	jokers.push_back("Double Dip");
	level = 1;
	isQuitGame = false;
	while (true)
	{
		Question *question = GetRandomQuestion(level);
		
		if (question != NULL && !isQuitGame)
		{
			if (AskQuestion(*question))
			{
				level++;
			}
			else {
				GameFailed();
				break;
			}
		}
		else {
			FinishGame();
			break;
		}
	}


}

void Game::FinishGame() {
	isQuitGame = true;
	system("cls");
	cout << endl << endl << "===== FINISH GAME =====" << endl << endl;
	cout << "Your Level: " << level - 2 << endl;
	
	if (level - 3 < 0)
	{
		cout << "Cash: 0";
	}
	else {
		cout << "Cash: " << awards.at(level - 3);
	}

	system("pause");
	
}

void Game::GameFailed() {
	isQuitGame = true;
	cout << endl << endl << "===== FINISH GAME =====" << endl << endl;
	cout << "Your Level: " << level - 1 << endl;
	
	if (level - 1 >= 7)
	{
		cout << "Cash: 15000";
	}
	else if (level - 1 >= 2)
	{
		cout << "Cash: 1000";
	}
	else {
		cout << "Cash: 0";
	}

	system("pause");
}

bool Game::AskQuestion(Question question) {
	int tryCount = 0, maxTryCount = 1;
	Question q = question;
	while (true)
	{
		system("cls");
		WriteQuestion(q);
		cout << "a -> answer the question" << endl;
		cout << "j -> use joker" << endl;
		cout << "q -> quit the game" << endl;
		cout << endl << "What do you want do: ";
		cout << "MAX TRY: " << maxTryCount;
		switch (_getch())
		{
		case 'a':
			if (tryCount < maxTryCount - 1)
			{
				bool isTrue = AnswerTheQuestion(q);
				if (isTrue)
				{
					return isTrue;
				}
				else {
					cout << endl << "Incorrect answer! Last try it!" << endl;
					system("pause");
					return AnswerTheQuestion(q);
				}
			}
			else
			{
				return AnswerTheQuestion(q);
			}
		case 'j':
			q = UseJoker(q, &maxTryCount);
			break;
		case 'q':
			if (maxTryCount - 1 == tryCount)
			{
				isQuitGame = true;
				return true;
			}
			else
			{
				cout << endl << "ERROR: you cannot quit game because you used joker..." << endl;
				system("pause");
			}
		default:
			break;
		}
	}
}


Question Game::UseJoker(Question &que, int *maxTryCount) {
	Question question = que;
	while (true)
	{
		cout << endl << endl << "===== AVAILABLE JOKER =====" << endl << endl;

		for (int i = 0; i < jokers.size(); i++)
		{
			cout << i + 1 << " -> " << jokers.at(i) << endl;
		}

		cout << "choose a joker: ";

		switch (_getch())
		{
		case '1':
			if (jokers.at(0) != "")
			{
				jokers.at(0) = "";
				int howManyDeleteChoice;
				howManyDeleteChoice = 0;
				do
				{
					int rnd = rand() % 4;
					switch (rnd)
					{
					case 0:
						if (question.GetCorrectChoice() != 'A')
						{
							question.removeChoiceA();
							howManyDeleteChoice++;
						}
						break;
					case 1:
						if (question.GetCorrectChoice() != 'B')
						{
							question.removeChoiceB();
							howManyDeleteChoice++;
						}
						break;
					case 2:
						if (question.GetCorrectChoice() != 'C')
						{
							question.removeChoiceC();
							howManyDeleteChoice++;
						}
						break;
					case 3:
						if (question.GetCorrectChoice() != 'D')
						{
							question.removeChoiceD();
							howManyDeleteChoice++;
						}
						break;
					default:
						break;
					}

				} while (howManyDeleteChoice < 2);
			}
			else {
				cout << endl << "ERROR: bu jokeri zaten kullandiniz" << endl;
				system("pause");
			}
			return question;
		case '2':
			if (jokers.at(1) != "")
			{
				jokers.at(1) = "";
				*maxTryCount = 2;
			}
			else {
				cout << endl << "ERROR: bu jokeri zaten kullandiniz" << endl;
				system("pause");
			}
			return question;

		default:
			break;
		}
		return question;
	}
	return question;
}

bool Game::AnswerTheQuestion(Question question) {
	while (true)
	{
		system("cls");
		WriteQuestion(question);
		cout << "correct: " << question.GetCorrectChoice() << endl;
		cout << "What is the correct answer: ";

		switch (_getch())
		{
		case 'a':
			if (question.GetChoiceA() != "")
			{
				if (question.GetCorrectChoice() == 'A')
				{
					return true;
				}
				else {
					return false;
				}
			}
		case 'b':
			if (question.GetChoiceB() != "")
			{
				if (question.GetCorrectChoice() == 'B')
				{
					return true;
				}
				else {
					return false;
				}
			}
		case 'c':
			if (question.GetChoiceC() != "")
			{
				if (question.GetCorrectChoice() == 'C')
				{
					return true;
				}
				else {
					return false;
				}
			}
		case 'd':
			if (question.GetChoiceD() != "")
			{
				if (question.GetCorrectChoice() == 'D')
				{
					return true;
				}
				else {
					return false;
				}
			}
		default:
			break;
		}
	}

}

void Game::WriteQuestion(Question question) {
	cout << "===== QUESTION " << level << " =====" << endl << endl << endl << endl;
	cout << question.GetQuestion() << endl << endl;
	cout << "a -> " << question.GetChoiceA() << endl;
	cout << "b -> " << question.GetChoiceB() << endl;
	cout << "c -> " << question.GetChoiceC() << endl;
	cout << "d -> " << question.GetChoiceD() << endl;
	cout << endl << endl;
}

Question* Game::GetRandomQuestion(int level) {
	
	vector<Question> tempQuestion = QuestionsInLevel(level);
	
	if (tempQuestion.size() != 0)
	{
		int rnd = rand() % tempQuestion.size();

		return &questions.at(rnd);
	}
	else {
		return NULL;
	}
}

vector<Question> Game::QuestionsInLevel(int level) {
	vector<Question> temp;

	for (int i = 0; i < questions.size(); i++)
	{
		if (questions.at(i).GetLevel() == level)
		{
			temp.push_back(questions.at(i));
		}
	}

	return temp;
}