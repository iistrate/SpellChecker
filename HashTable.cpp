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
		if (dictWord[0] == word[0]) {
			m_suggestions.push_back(dictWord);
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