#pragma once

#include <deque>
#include <fstream>
#include <sstream>
#include <iostream>

void read_file();

void read_file() {
	std::ifstream inputFile("dayone.txt");
	std::deque<std::string> first_column;
	std::deque<std::string> second_column;
	std::string control_str;
	std::string str_one;
	std::string str_two;
	
	if (!inputFile) {
		std::cout << "Could not read the file" << std::endl;
	}
	else {
		while (inputFile) {
			std::cout << 'test' << std::endl;
			std::getline(inputFile, control_str);
			bool is_second = false;
			for (char c : control_str) {
				if (c != ' ' && !is_second) {
					str_one += c;
				}
				if (c != ' ' && is_second) {
					str_two += c;
				}
				if (c == ' ') {
					is_second = true;
				}
			}
			//first_column.emplace_back(std::stoi(str_one));
			//second_column.emplace_back(std::stoi(str_two));
			std::cout << str_one << ' ' << str_two << std::endl;
			str_one.clear();
			str_two.clear();
		}
	}
	inputFile.close();
}