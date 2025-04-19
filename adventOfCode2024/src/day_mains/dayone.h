#pragma once

#include <deque>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

void read_file();

void read_file() {
	std::ifstream inputFile("./inputs/day1.txt", std::ifstream::in);
	std::deque<int> first_column;
	std::deque<int> second_column;
	std::string control_str;
	std::string str_one;
	std::string str_two;

	int final_result = 0;
	
	if (!inputFile) {
		std::cout << "Could not read the file" << std::endl;
	}
	else {
		while (std::getline(inputFile, control_str)) {
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
			first_column.emplace_back(std::stoi(str_one));
			second_column.emplace_back(std::stoi(str_two));
			str_one.clear();
			str_two.clear();
		}
	}
	inputFile.close();

	std::sort(first_column.begin(), first_column.end());
	std::sort(second_column.begin(), second_column.end());

	std::cout << first_column.size() << std::endl;
	std::cout << second_column.size() << std::endl;
	for (int i = 0; i < first_column.size(); i++)
	{
		std::cout << i << ' ' << first_column[i] << ' ' << second_column[i] << ' ' << abs(first_column[i] - second_column[i]) << std::endl;

		int loop_result = abs(first_column[i] - second_column[i]);
		final_result += loop_result;
	}
	std::cout << "The final result is: " << final_result << std::endl;
	
}