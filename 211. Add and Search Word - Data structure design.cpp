class TrieNode {
public:
	// Initialize your data structure here.
	//    string value;    // if value is ""
	bool isValue;
	TrieNode*  children[26];

	TrieNode() : isValue(false) {
		memset(children, 0, sizeof(children));      //Memset is more efficent than resize() function in vector
	}
};

class WordDictionary {
public:
	WordDictionary()  {
		root = new TrieNode();
	}
 
	void addWord(string word) {
		auto node = root;

		for (int i = 0; i < word.size(); i++) {
			int index = getIndex(word[i]);
			if (node->children[index] == nullptr) {
				node->children[index] = new TrieNode;
			}
			node = node->children[index];
		}

		if (node != root) {
			node->isValue = true;
		}
	}

	bool search(TrieNode* node, string&& word) {
		if (word.empty()) {
			return node->isValue;
		}
		else {
			for (int i = 0; node && i < word.size(); i++) {
			    
				if (word[i] == '.') {
					bool founded = false;
					int k = 0;
					while (!founded && k < 26) {
						if (node->children[k])
							founded = search(node->children[k], word.substr(i + 1, word.size() - i - 1));
						k++;
					}
					if (!founded) {
						return false;
					}
					else {
						node = node->children[--k];
						continue;
					}
				}

				int index = getIndex(word[i]);
				node = node->children[index];
			}
			return (node && node->isValue) ? true : false;
		}
		 
	}

	bool search(string word) {
		return search(root, move(word));    
	}

private:
	TrieNode* root;

	inline int getIndex(char ch) {
		return ch - 'a';
	}
};
 