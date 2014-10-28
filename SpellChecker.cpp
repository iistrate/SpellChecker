#include "SpellChecker.h"

void SpellChecker::run(void) {
	//sets up hash table
	setup();
	//test hash function
	//	m_Debugger.pTest("Index is " + std::to_string(hash("aardwolves")));
	//end
}
void SpellChecker::setup(void) {
	std::ifstream in("dict.txt");
	string word;
	int index = 0;
	bool used = false;
	while (in >> word) {
		//get index
		index = hash(word);
		//get is used
		used = m_HT[index].isFull();
		//if the hash table is not used
		if (!used) {
			//insert word
			m_HT[index].insertWord(word);
			//raise used flag
			m_HT[index].setFull(true);
		}
		else {
			//insert word as a node
		}

//test word
//		m_Debugger.pTest("Word is " + word);
//end
	}
}

int SpellChecker::hash(string word) {
	//hash index
	int index = 0;
	for (int i = 0; i < word.length(); i++) {
		//ascii value - 'a', for a = 0
		index += word[i] - 'a';
	}
	return index % m_maxSize;
}