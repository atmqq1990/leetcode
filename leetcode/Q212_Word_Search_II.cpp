#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	
	unordered_set<string> wordset;
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		if (board.size() == 0)
			return res;
		for (int i = 0; i < words.size(); i++)
			insert(words[i]);
		int m = board.size();
		int n = board[0].size();
		bool **visited = new bool*[m];
		for (int i = 0; i < m; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n;j++)
				visited[i][j] = false;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				string temp;
				find(board,temp,visited,i,j);
			}
		res.assign(wordset.begin(),wordset.end());
		return res;
	}

	void find(vector<vector<char>>& board, string& pre, bool** visited ,int rowid, int colid)
	{
		int m = board.size();
		int n = board[0].size();
		if (rowid < 0 || rowid >= m || colid < 0 || colid >= n)
			return;
		if (visited[rowid][colid])
			return;
		pre.push_back(board[rowid][colid]);
		if (!startsWith(pre))
		{
			pre.pop_back();
			return;
		}
		if (search(pre))
		{
			wordset.insert(pre);
		}
		visited[rowid][colid] = true;
		find(board,pre,visited,rowid+1,colid);
		find(board,pre,visited,rowid-1,colid);
		find(board,pre,visited,rowid,colid+1);
		find(board,pre,visited,rowid,colid-1);
		visited[rowid][colid] = false;
		pre.pop_back();

	}


private:

	struct TrieNode {
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

	TrieNode *root = new TrieNode();
	
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

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<vector<char>> board;
	vector<char> v1 = { 'o','a','a','n' };
	vector<char> v2 = { 'e','t','a','e' };
	vector<char> v3 = { 'i','h','k','r' };
	vector<char> v4 = { 'i','f','l','v' };
	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	vector<string> words = { "oath","pea","eat","rain" };
	vector<string> res = so.findWords(board,words);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	system("pause");
	return 0;
} 
*/