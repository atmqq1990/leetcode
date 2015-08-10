#include<iostream>
#include<string>
using namespace std;

class TrieNode {
public:
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

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
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

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *cur = root;
		int len = word.size();
		for (int i = 0; i<len; i++)
		{
			char c = word[i];
			int chid = c - 'a';
			if (cur->children[chid] == NULL)
				return false;
			cur = cur->children[chid];
		}
		if (cur->isword == true)
			return true;

		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *cur = root;
		int len = prefix.size();
		for (int i = 0; i<len; i++)
		{
			char c = prefix[i];
			int chid = c - 'a';
			if (cur->children[chid] == NULL)
				return false;
			cur = cur->children[chid];
		}

		return true;

	}

private:
	TrieNode* root;
};