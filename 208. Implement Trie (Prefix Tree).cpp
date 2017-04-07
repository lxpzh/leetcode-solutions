class TrieNode {
public:
    // Initialize your data structure here.
 //    string value;    // if value is ""
     bool isValue;
     TrieNode*  children[26];

     TrieNode() : isValue(false) {
        memset(children, 0, sizeof(children));      //Memset时间复杂度很低，小于vector
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        auto node = root;

        int i=0;
        for (; node && i < word.size(); i++) {
            int index = getIndex(word[i]);
            node = node->children[index];
        }

       return (node && node->isValue) ? true : false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto node = root;

        for (auto i=0;node && i < prefix.size(); i++) {
            int index = getIndex(prefix[i]);
            node = node->children[index];
        }

        return (!node || node == root) ? false : true;
    }

private:
    TrieNode* root;

    inline int getIndex(char ch) {
        return ch - 'a';
    }
};