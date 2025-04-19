#pragma once

#include <deque>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void day1part1();
void day1part2();

void day1part1() {
	std::ifstream inputFile("./inputs/day1.txt", std::ifstream::in);
	std::vector<int> first_column;
	std::vector<int> second_column;
	std::string control_str;
	std::string str_one;
	std::string str_two;

	int final_result1 = 0;
	int final_result2 = 0;
	
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
			first_column.push_back(std::stoi(str_one));
			second_column.push_back(std::stoi(str_two));
			str_one.clear();
			str_two.clear();
		}
	}
	inputFile.close();

	std::sort(first_column.begin(), first_column.end());
	std::sort(second_column.begin(), second_column.end());

	for (int i = 0; i < first_column.size(); i++)
	{
		std::cout << i << ' ' << first_column[i] << ' ' << second_column[i] << ' ' << abs(first_column[i] - second_column[i]) << std::endl;

		int loop_result = abs(first_column[i] - second_column[i]);
		final_result1 += loop_result;
	}
	std::cout << "The final result of part 1 is: " << final_result1 << std::endl;
	
	for (int i = 0; i < first_column.size(); i++)
	{
		int curr_element = first_column[i];
		int curr_freq = std::count(second_column.begin(), second_column.end(), curr_element);
		final_result2 += curr_element * curr_freq;
	}
	std::cout << "The final result of part 2 is: " << final_result2 << std::endl;
}
