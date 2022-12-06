#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

int part1(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::unordered_map<char,int> chars;
	std::ifstream file(argv[1]);
	int number;
	std::string line;
	while(std::getline(file, line)) {
		for(int i=0;i<line.size();i++) {
			for(int j=i;j<i+4;j++) {
				if(chars.find(line[j]) != chars.end()) {
					break;
				}
				chars[line[j]] = (int)'l'+(int)'o'+(int)'l'; 
				if(j == i+3) {
					number = j+1;
					goto END;
				}
			}
			chars.clear();
		}
	}
END:
	std::cout << number << std::endl;
	return 0;
}

int part2(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::unordered_map<char,int> chars;
	std::ifstream file(argv[1]);
	int number;
	std::string line;
	while(std::getline(file, line)) {
		for(int i=0;i<line.size();i++) {
			for(int j=i;j<i+14;j++) {
				if(chars.find(line[j]) != chars.end()) {
					break;
				}
				chars[line[j]] = (int)'l'+(int)'o'+(int)'l'; 
				if(j == i+13) {
					number = j+1;
					goto END;
				}
			}
			chars.clear();
		}
	}
END:
	std::cout << number << std::endl;
	return 0;
}

int main(int argc, char **argv) {
	part1(argc, argv);
	part2(argc, argv);
}
