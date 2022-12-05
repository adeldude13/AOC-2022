#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>

typedef std::unordered_map<char, int> hash_map;

int getValue(char c) {
	if((int)c >= 97) {
		return (int)(c-96);	
	} else if(c >= 65) {
		return (int)(c-38);
	}
	return 0;
}

int part1(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::ifstream file(argv[1]);
	hash_map chars;
	std::string line;
	int value = 0;
	while(std::getline(file, line)) {
		int halfLen = line.size()/2;
		for(int i=0;i<halfLen;i++) {
			chars[line[i]] = 1;
		}
		for(int i=halfLen;i<line.size();i++) {
			if(chars.find(line[i]) != chars.end() && chars[line[i]] != -1) {
				chars[line[i]] = -1;
				value += getValue(line[i]);	
			}
		}
		chars.clear();
	}
	std::cout << value << std::endl;
	return 1;
}


int part2(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::ifstream file(argv[1]);
	hash_map chars;
	std::vector<std::string> lines(3);
	std::string line;
	int count = 1;
	int value = 0;
	while(std::getline(file, line)) {
			lines[count-1] = line;
			count++;
			if(count == 4) {
				count = 1;
				for(int i=0;i<lines.size();i++) {
					for(int j=0;j<lines[i].size();j++) {
						if(chars.find(lines[i][j]) == chars.end() && i == 0) {
							chars[lines[i][j]] = i+1;
						} else if(chars.find(lines[i][j]) != chars.end() && i != 0){
							if(i == 1) {
								chars[lines[i][j]] = 2;
							}
							if(i == 2) {
								if(chars[lines[i][j]] == 2) {
									chars.clear();
									value += getValue(lines[i][j]);
									break;
								}
							}
						}
					}
				}
			}
	}
	std::cout << value << std::endl;
	return 0;
}

int main(int argc, char **argv) {
	part1(argc, argv);
	part2(argc, argv);
}
