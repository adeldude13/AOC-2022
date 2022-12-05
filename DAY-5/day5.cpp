#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>

std::vector<int> parseNums(std::string line) {
	std::vector<int> ret;
	for(int i=0;i<line.size();i++) {
		if((int)(line[i]) >= 48 && (int)(line[i]) <= 57) {
			std::string number = "";
			while((int)line[i] >= 48 && (int)line[i] <= 57) {
				number += line[i];
				i++;
			}
			ret.push_back(std::stoi(number)-1);
		}
	}
	return ret;
}

std::stack<char> reverseStack(std::stack<char> current) {
	std::stack<char> ret;
	while(!current.empty()) {
		ret.push(current.top());
		current.pop();
	}
	return ret;
}

int day1(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::ifstream file(argv[1]);
	std::string line;
	std::vector<std::stack<char>> crates(9);
	while(std::getline(file, line)) {
		int index = 0;
 		if(line.size() == 0) {
			for(int i=0;i<9;i++) {
				crates[i] = reverseStack(crates[i]);
			}
 		} else if (line[0] != 'm' && line[1] != '1') {
			for(int i=0;i<line.size();i++) {
				if(i % 4 == 1) {
					if(line[i] != ' ') {
						crates[index].push(line[i]);
					}
					index++;
				}
			} 
		} else if(line[0] == 'm') {
			std::vector<int> nums = parseNums(line);
			for(int i=0;i<nums[0]+1;i++) {
				crates[nums[2]].push(crates[nums[1]].top());
				crates[nums[1]].pop();
			}
		}
	}
	for(int i=0;i<crates.size();i++) {
		std::cout << crates[i].top();
	}
	std::cout << std::endl;
	return 0;
}

int day2(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::ifstream file(argv[1]);
	std::string line;
	std::vector<std::stack<char>> crates(9);
	while(std::getline(file, line)) {
		int index = 0;
 		if(line.size() == 0) {
			for(int i=0;i<9;i++) {
				crates[i] = reverseStack(crates[i]);
			}
 		} else if (line[0] != 'm' && line[1] != '1') {
			for(int i=0;i<line.size();i++) {
				if(i % 4 == 1) {
					if(line[i] != ' ') {
						crates[index].push(line[i]);
					}
					index++;
				}
			} 
		} else if(line[0] == 'm') {
			std::vector<int> nums = parseNums(line);
			if(nums[0] == 0) {	
				crates[nums[2]].push(crates[nums[1]].top());
				crates[nums[1]].pop();
			} else {
				int i=0;
				std::stack<char> newStack;
				while(i < nums[0]+1) {
					newStack.push(crates[nums[1]].top());
					crates[nums[1]].pop();
					i++;
				}
				while(!newStack.empty()) {
					crates[nums[2]].push(newStack.top());
					newStack.pop();
				}
			}
		}
	}
	for(int i=0;i<crates.size();i++) {
		std::cout << crates[i].top();
	}
	std::cout << std::endl;
	return 0;
}

int main(int argc, char **argv) {
	day1(argc, argv);
	day2(argc, argv);
}
