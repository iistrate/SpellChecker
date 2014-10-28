#include "SpellChecker.h"

void SpellChecker::run(void) {
	int test = m_HT.hash("aardwolves");
	m_Debugger.pTest("Index is " + std::to_string(test));
}