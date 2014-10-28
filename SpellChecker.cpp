#include "SpellChecker.h"

void SpellChecker::run(void) {
	//sets up hash table
	setup();
	//test hash function
	//	m_Debugger.pTest("Index is " + std::to_string(hash("aardwolves")));
	//end
	//test hashtable sizes
	//for (int i = 0; i < m_maxSize; i++) {
	//	cout << m_HT[i].getCount() << endl;
	//}
	//system("pause");
	//end
	string uInput;
	using std::cin;
	int lookIn = 0;
	while (m_running) {
		cout << "Please enter word: ";
		cin >> uInput;
		//get where to look
		lookIn = hash((uInput));
		if (m_HT[lookIn].findWord(uInput)) {
			cout << "Found word!" << endl;
		}
		//suggestions
		else {
			cout << "Did you mean: ";
			//get suggestions
			vector < string > suggestions = m_HT[lookIn].getSuggestions();
			for (int i = 0; i < suggestions.size(); i++) {
				cout << suggestions[i] << " ";
			}
			cout << endl;
		}
	}
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
		//if index of ht is not used
		if (!used) {
			//raise used flag
			m_HT[index].setFull(true);
		}
		//insert word
		m_HT[index].insertWord(word);

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