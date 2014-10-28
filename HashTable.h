#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Debug.h"

class HashTable {
private:
	const int m_size;
	class Node {
	private:
		int m_key;
		string m_value;
		Node* m_next;
	public:
		Node() : m_key(0), m_value(0), m_next(0) {}
		Node(int key) : m_key(key), m_value(0), m_next(0) {}
		Node(int key, string value) : m_key(key), m_value(value), m_next(0) {}

		void setNext(Node* next) {
			m_next = next;
		}
		void setIndex(int key) {
			m_key = key;
		}
		void setValue(string value) {
			m_value = value;
		}

		Node* getNext(void) {
			return m_next;
		}
		int getIndex(void) {
			return m_key;
		}
		string getValue(void) {
			return m_value;
		}
	};
public:
	HashTable() : m_size(25) {}
	int hash(string value);
};



#endif //end HashTable.h