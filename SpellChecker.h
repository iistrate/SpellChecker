#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <fstream>
#include <vector>

#include "Globals.h"
#include "HashTable.h"

using std::vector;

class SpellChecker {
private:
	Debug m_Debugger;
	HashTable m_HT[25];
	int m_maxSize;
public:
	SpellChecker() : m_maxSize(25) {}
	void run(void);
	void setup(void);
	
	//my hash function
	int hash(string word);
};

#endif // end SpellChecker.h