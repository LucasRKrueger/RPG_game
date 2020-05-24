#include "Puzzle.h"

Puzzle::Puzzle(string fileName)
{	
	this->correctAnswer = 0;	

	ifstream inFile(fileName);

	int _numberOfAnswers = 0;
	string _answer = "";
	int _correctAnswer = 0;
	if (inFile.is_open())
	{
		getline(inFile, this->question);
		inFile >> _numberOfAnswers;
		inFile.ignore();

		for (size_t i = 0; i < _numberOfAnswers; i++)
		{
			getline(inFile, _answer);
			this->answers.push_back(_answer);
		}
		inFile >> _correctAnswer;
		this->correctAnswer = _correctAnswer;
		inFile.ignore();
	}
	else
		throw("Couldn't open the puzzle");
	inFile.close();
}

Puzzle::~Puzzle()
{

}

string Puzzle::getAsString()
{
	string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += to_string(i) + ": " + this->answers[i] + "\n";
	}
	return this->question + "\n \n" + answers + "\n";
}