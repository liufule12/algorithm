#include <iostream>
#include <string.h>

using namespace std;


class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode (): isWord(false) { memset(next, NULL, sizeof(next)); }
};


class WordDictionary {
public:
    WordDictionary () {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!(p->next[word[i] - 'a']))
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* p) {
        for (int i = 0; word[i]; ++i) {
            if (p && word[i] != '.')
                p = p->next[word[i] - 'a'];
            else if (p && word[i] == '.') {
                TrieNode* tmp = p;
                for (int j = 0; j < 26; ++j) {
                    p = tmp->next[j];
                    if (query(word + i + 1, p))
                        return true;
                }
            } else
                break;
        }
        return p && p->isWord;
    }

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("aa");
    if (wordDictionary.search(".b"))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
