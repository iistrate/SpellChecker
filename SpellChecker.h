#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include "Globals.h"
#include "HashTable.h"


class SpellChecker {
private:
	Debug m_Debugger;
	HashTable m_HT;
public:
	void run(void);
};

#endif // end SpellChecker.h