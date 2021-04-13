#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include "Question.h"
#include "Game.h"

using namespace std;

int main();

void ScoreLoadFromFileName(string scoreFileName, vector<Score> &scores);
void QuestionLoadFromFileName(string questionFileName, vector<Question> &questions);
vector<string> ParseStringToVector(string rawData, char splitChar);
int StringToInteger(string number);
string ReplaceString(string text, char replaceChar = '"');
