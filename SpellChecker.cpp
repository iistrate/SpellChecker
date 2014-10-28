#include "SpellChecker.h"

void SpellChecker::run(void) {
	int test = m_HT.hash("abc");
	cout << test << endl;
	m_Debugger.pTest("Index is" + test);
}