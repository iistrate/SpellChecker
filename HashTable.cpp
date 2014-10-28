#include "HashTable.h"


int HashTable::hash(string word) {
	//hash index
	int index = 0;

	for (int i = 0; i < word.length(); i++) {
		//ascii value - 'a', for a = 0
		index += word[i] - 'a';
	}
	return index % m_size;
}