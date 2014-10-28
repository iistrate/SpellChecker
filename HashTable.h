#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Debug.h"

class HashTable {
private:
	const int m_size;
	struct Node {
		int m_key;
		string m_value;
		Node* m_next;
	};
public:
	HashTable() : m_size(100) {}
	int hash(string value);
};



#endif //end HashTable.h