#include "Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{	
	this->correctAnswer = 0;	

	std::ifstream inFile(fileName);

	int _numberOfAnswers = 0;
	std::string _answer = "";
	int _correctAnswer = 0;
	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> _numberOfAnswers;
		inFile.ignore();

		for (size_t i = 0; i < _numberOfAnswers; i++)
		{
			std::getline(inFile, _answer);
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

std::string Puzzle::getAsString()
{
	std::string answers = "";

	for (size_t i = 0; i < answers.size(); i++)
	{
		answers = std::to_string(i) + ": " + this->answers[i] + "\n";
	}

	return this->question + "\n \n" +
		   answers + "\n" +
		   std::to_string(this->correctAnswer) + "\n";		   		   
}