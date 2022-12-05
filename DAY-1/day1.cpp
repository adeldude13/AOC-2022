#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	std::ifstream file(argv[1]);
	std::string line;
	int current = 0;
	int max1 = -1;
	int max2 = -1;
	int max3 = -1;
	while(std::getline(file, line)) {
		if(line.size() == 0) {
			if(current > max1) {
				int temp1 = max1;
				int temp2 = max2;
				max1 = current;
				max2 = temp1;
				max3 = temp2;	
			} else if(current > max2) {
				int temp = max2;
				max2 = current;
				max3 = temp;
			} else if(current > max3) {
				max3 = current;
			}
			current = 0;
		} else {
			current += std::stoi(line);
		}
	}
	std::cout << max1 + max2 + max3 << std::endl;
	return 0;
}
