#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Debug.h"
#include <vector>
using std::vector;

class HashTable {
private:
	class Node {
	private:
		string m_value;
		Node* m_next;
	public:
		Node() : m_value(0), m_next(0) {}
		Node(string value) :m_value(value), m_next(0) {}

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
	Node* m_tail;
	bool m_full;
	int m_count;
	vector < string > m_suggestions;
public:
	HashTable() : m_head(0), m_tail(0), m_full(false), m_count(0) {}
	void insertWord(string word);

	bool findWord(string word);

	int getCount(void) {
		return m_count;
	}

	bool isFull(void) {
		return m_full;
	}
	void setFull(bool b) {
		m_full = b;
	}
	void print(void);

	vector < string > getSuggestions(void) {
		vector < string > returned = m_suggestions;
		m_suggestions.clear();
		return m_suggestions;
	}
};



#endif //end HashTable.h