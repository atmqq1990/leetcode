#include<iostream>
#include<string>
using namespace std;

class WordDictionary {
public:

	WordDictionary()
	{
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *cur = root;
		int len = word.size();
		if (len == 0)
			return;
		for (int i = 0; i<len; i++)
		{
			char c = word[i];
			int chid = c - 'a';
			if (cur->children[chid] == NULL)
			{
				cur->children[chid] = new TrieNode();
				cur->haschild = true;
			}
			cur = cur->children[chid];
		}
		cur->isword = true;

	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return seh(root, word);
	}

private:

	struct TrieNode {
		// Initialize your data structure here.
		bool isword;
		bool haschild;
		TrieNode *children[26];

		TrieNode() {
			isword = false;
			haschild = false;
			for (int i = 0; i<26; i++)
				children[i] = NULL;
		}
	};

	TrieNode* root;

	bool seh(TrieNode *cur, string word)
	{
		int len = word.size();
		for (int i = 0; i<len; i++)
		{
			char c = word[i];
			if (c != '.')
			{
				int chid = c - 'a';
				if (cur->children[chid] == NULL)
					return false;
				cur = cur->children[chid];
			}
			else
			{
				if (cur->haschild == false)
					return false;

				bool tempres = false;
				for (int j = 0; j<26; j++)
					if (cur->children[j] != NULL)
					{
						if (i == len - 1 && cur->children[j]->isword == true)
							return true;
						tempres |= seh(cur->children[j], word.substr(i + 1));
						if (tempres)
							return true;
					}

				return false;
			}

		}

		if (cur->isword == true)
			return true;

		return false;
	}

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


/*
int main()
{
	WordDictionary wordDictionary;
	wordDictionary.addWord("at");
	wordDictionary.addWord("and");
	wordDictionary.addWord("an");
	wordDictionary.addWord("add");
	cout<<wordDictionary.search("a")<<endl;
	cout<<wordDictionary.search(".at")<<endl;
	wordDictionary.addWord("bat");
	cout<<wordDictionary.search(".at")<<endl;
	cout<<wordDictionary.search("an.")<<endl;
	cout<<wordDictionary.search("a.d.")<<endl;
	cout<<wordDictionary.search("b.")<<endl;
	cout<<wordDictionary.search("a.d")<<endl;
	cout<<wordDictionary.search(".")<<endl;

	system("pause");
	return 0;
}
*/