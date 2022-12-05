#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void day1(int argc, char **argv) {
	if(argc != 2) {
		return;
	}
	std::fstream file(argv[1]);
	std::string line;
	int v = 0;
	while(std::getline(file, line)) {
		char a = line[0], b = line[2];
		v += (((a =='A'&&b =='Y')||(a=='B'&&b== 'Z')||(a=='C' && b=='X'))?6:((a == (char)(b-23)) ? 3 : 0)) + (int)(b-87);
	}
	std::cout << v << std::endl;
}

void day2(int argc, char **argv) {
	if(argc != 2) {
		return;
	}
	std::fstream file(argv[1]);
	std::string line;
	int v = 0;
	while(std::getline(file, line)) {
		bool win = false;
		char a = line[0], b = line[2];
		if(b == 'Y') {b=a+23;v+=3;}
		else if(b == 'X') { b = (a == 'B' || a == 'C') ? (a + 22 ) : 'Z'; }
		else if(b == 'Z') {
			win = true;
			if(a == 'B') {
				b = 'Z';
			} else if(a == 'A') {
				b = 'Y';
			} else {
				b = 'X';	
			}
		}
		v += (int)(b-87) + (win ? 6 : 0);
	}
	std::cout << v << std::endl;
}

int main(int argc, char **argv) {
	day1(argc, argv);
	day2(argc, argv);
}
