#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Debug.h"

class HashTable {
private:
	class Node {
	private:
		string m_value;
		Node* m_next;
	public:
		Node() : m_value(0), m_next(0) {}
		Node(int key) : m_value(0), m_next(0) {}
		Node(int key, string value) :m_value(value), m_next(0) {}

		void setNext(Node* next) {
			m_next = next;
		}
		void setValue(string value) {
			m_value = value;
		}

		Node* getNext(void) {
			return m_next;
		}
		string getValue(void) {
			return m_value;
		}
	};
	string m_value;
	Node* m_head;
	bool m_full;
public:
	HashTable() : m_head(0) {}
	void insertWord(string word);

	bool isFull(void) {
		return m_full;
	}
	void setFull(bool b) {
		m_full = b;
	}

};



#endif //end HashTable.h