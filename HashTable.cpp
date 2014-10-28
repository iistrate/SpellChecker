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
			while (navigator != 0) {
				navigator = m_head->getNext();
			}
			navigator = newNode;
		}
		m_count++;
	}
	else {
		m_value = word;
	}
}
