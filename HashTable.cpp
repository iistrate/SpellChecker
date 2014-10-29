#include "HashTable.h"


void HashTable::insertWord(string word) {
	if (m_full) {
		//insert nodes
		Node* newNode = new Node(word);
		if (m_count == 0) {
			m_head = newNode;
		}
		else {
			Node* navigator = m_head;
			//go to end
			while (navigator->getNext() != 0) {
				navigator = navigator->getNext();
			}
			navigator->setNext(newNode);
		}
		m_count++;
	}
	else {
		m_value = word;
	}
}
bool HashTable::findWord(string word) {
	Node* navigator = m_head;
	string dictWord;
	while (navigator != 0) {
		dictWord = navigator->getValue();
		if (dictWord == word) {
			return true;
		}
		//check for omissions
		if (dictWord.length() <= word.length() + 1 || dictWord.length() <= word.length() - 1) {
			int count = 0;
			//check for misplaced letter
			for (int i = 0; i < dictWord.length() && i < word.length(); i++) {
				if (dictWord[i] == word[i]) {
					count++;
				}
			}
			if (count >= (word.length() - 1)) {
				//if (m_suggestions.size() < 10) {
					m_suggestions.push_back(dictWord);
				//}
			}
		}
		navigator = navigator->getNext();
	}
	return false;
}
void HashTable::print(void) {
	Node* navigator = m_head;
	while (navigator != 0) {
		cout << navigator->getValue() << endl;
		navigator = navigator->getNext();
	}
}