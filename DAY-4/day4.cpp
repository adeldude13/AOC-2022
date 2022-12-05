#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int max(int a, int b) { return (a > b ? a : b); }

int min(int a, int b) { return (a < b ? a : b); }

std::vector<int> parseLine(std::string line) {
	std::vector<int> nums(3);
	int i = 0, index = 0;
	for(int j=0;j<2;j++) {
		std::string number = "";
		while(line[i]!='-') {
			number += line[i];
			i++;
		}
		i++;
		nums[index++] = std::stoi(number);
		number = "";
		while( ( j == 0 ? (line[i] != ',') : (i != line.size()) ) ) {
			number += line[i];
			i++;
		}
		nums[index++] = std::stoi(number);
		i++;
	}
	return nums;
}

int part1(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::string line;
	std::ifstream file(argv[1]);
	int count = 0;
	while(std::getline(file, line)) {
		std::vector<int> nums = parseLine(line);
		if( (nums[0] <= nums[2] && nums[1] >= nums[3]) || (nums[0] >= nums[2] && nums[1] <= nums[3])) {
			count++;	
		}
	}
	std::cout << count << std::endl;
	return 0;
}

int part2(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::string line;
	std::ifstream file(argv[1]);
	int count = 0;
	while(std::getline(file, line)) {
		std::vector<int> nums = parseLine(line);
		if(max(nums[0], nums[2]) <= min(nums[1], nums[3])) {
			count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}

int main(int argc, char **argv) {
	part1(argc, argv);
	part2(argc, argv);
}
