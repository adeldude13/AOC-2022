#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <limits>

typedef unsigned long long ull;


ull ndirs = 0;

class Node {
	public:
		std::string name;
		ull value;
		std::vector<Node *> nodes;
		Node(std::string p_name, ull p_value) {
			value = p_value;
			name =  p_name;
		}
		void append(Node *n) {
			nodes.push_back(n);
		}
		Node *getNode(std::string p_name) {
			for(int i=0;i<nodes.size();i++) {
				if(nodes[i]->name == p_name) {
					return nodes[i];
				}
			}
			return nullptr;
		}
};

ull calculate(Node *n) {
	ull sum = 0;
	if(n->nodes.size() != 0) {
		for(int i=0;i<n->nodes.size();i++) {
			sum += calculate(n->nodes[i]);
		}
	} else {
		return n->value;
	}
	if(sum <= 100000) {
		ndirs += sum;
	}
	return sum;
}

int main(int argc, char **argv) {
	std::ifstream file(argv[1]);
	std::string line;
	// skip first two lines;
	std::getline(file, line);
	std::getline(file, line);
	Node top("/", 0);
	Node *currNode = &top;
	std::stack<Node *> nodesStack;
	nodesStack.push(currNode);
	while(std::getline(file, line)) {
		if(line[0] == '$' && line[2] == 'c') {
			std::string currName = line.substr(5, line.size()-1);
			if(currName == "..") {
				nodesStack.pop();
				currNode = nodesStack.top();
			} else {
				currNode = currNode->getNode(currName);
				nodesStack.push(currNode);
			}
			
		} else if(line[0] != '$') {
			if(line[0] == 'd') {
				Node *node = new Node(line.substr(4, line.size()-1), 0);
				currNode->append(node);
			} else {
				int i=0;
				std::string number="";
				while(line[i] != ' ') {
					number += line[i];
					i++;
				}
				Node *node = new Node("", stoull(number));
				currNode->append(node); 
			}
		}
	}
	calculate(&top);
	std::cout << ndirs;
}
