#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int getValue(std::vector<std::string> lines, int index) {
	if(index == 0 || index == lines.size()-1) {
		return lines[index].size();
	}
	int sum = 0;
	for(int i=0;i<lines[index].size();i++) {
		if(i == 0 || i == lines[index].size() - 1) {
			sum++;
		} else {
			bool isBigger = false;
			char v = lines[index][i];
			for(int z=0;z<lines.size();z++) {
				if(z == index) {
					if(!isBigger) {
						break;
					}
					isBigger = false;
				} else {
					if(lines[z][i] >= v) {
						isBigger = true;
					}
					if(z > index && isBigger) break;
				}
			}
			if(!isBigger) {
				sum++;
				goto END;
			}
			isBigger = false;
			for(int z=0;z<lines[index].size();z++) {
				if(z == i) {
					if(!isBigger) {
						break;
					}
					isBigger = false;
				} else {
					if(lines[index][z] >= v) {
						isBigger = true;
					}
					if(z > i && isBigger) break;
				}
			}
			if(!isBigger) {
				sum++;
			}
END:
			isBigger = false;
		}
	}
	return sum;
}


int part1(int argc, char **argv) {
	std::ifstream file(argv[1]);
	std::string line;
	std::vector<std::string> lines;
	while(std::getline(file, line)) {
		lines.push_back(line);
	}
	int count = 0;
	for(int i=0;i<lines.size();i++) {
		count += getValue(lines, i);
	}
	std::cout << count << std::endl;
}

int getMaxDistance(std::vector<std::string> lines, int index) {
	int max = -1;
	for(int i=1;i<lines[index].size()-1;i++) {
		int w = index-1, u=0, d=0, r=0, l=0;
		char v = lines[index][i];
		while(w != -1) {
			u++;
			if(lines[w][i] >= v) {
				break;
			}
			w--;
		}
		w = index+1;
		while(w != lines[index].size()) {
			d++;
			if(lines[w][i] >= v) {
				break;	
			}
			w++;
		}
		w = i-1;
		while(w != -1) {
			l++;
			if(lines[index][w] >= v) {
				break;
			}
			w--;
		}
		w = i+1;
		while(w != lines.size()) {
			r++;
			if(lines[index][w] >= v) {
				break;
			}
			w++;
		}
		if(r*l*u*d > max) {
			max = r*l*u*d;
		}
	}
	return max;
}


int main(int argc, char **argv) {
	std::ifstream file(argv[1]);
	std::string line;
	std::vector<std::string> lines;
	while(std::getline(file, line)) {
		lines.push_back(line);
	}
	int count = 0;
	int max = -1;
	for(int i=1;i<lines.size()-1;i++) {
		count = getMaxDistance(lines, i);
		if(count > max) {
			max = count;
		}
	}
	std::cout << max << std::endl;
}
