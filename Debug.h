#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Debug {
public:
	void pTest(string text) {
		cout << text << endl;
		system("pause");
	}
};

#endif