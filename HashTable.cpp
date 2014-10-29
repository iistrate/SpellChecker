#include "HashTable.h"


void HashTable::insertWord(string word) {
	if (m_full) {
		//insert nodes
		Node* newNode = new Node(word);
		if (m_count == 0) {
			m_head = newNode;
		}
		else if (m_count == 1) {
			m_tail = newNode;
			m_head->setNext(m_tail);
		}
		else { 
			Node* temp = m_tail;
			m_tail = newNode;
			temp->setNext(m_tail);
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
			for (int i = 0; i < dictWord.length(); i++) {
				if (i <= word.length()) {
					if (dictWord[i] == word[i]) {
						count++;
					}
				}
			}
			cout << dictWord << " ";
			if (count >= (word.length() - 2)) {
				//if (m_suggestions.size() < 10) {
					m_suggestions.push_back(dictWord);
				//
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