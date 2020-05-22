#pragma once

#include<string>
#include<vector>
#include<fstream>

class Puzzle {
	public:
		Puzzle(std::string fileName);
		virtual ~Puzzle();

	private:
		std::string question;
		std::vector<std::string>answers;
		int correctAnswer;

};