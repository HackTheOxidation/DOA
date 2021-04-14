#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Trie
{
	class TrieNode;

	typedef map<char, TrieNode*> TrieMap;
	typedef map<char, TrieNode*>::iterator TrieMapIter;

	// Internal TrieNode class - not relevant outside Trie
	class TrieNode
	{
	public:
		TrieNode(char c = '\0', bool cw = false, TrieNode* p = nullptr) :
			val(c), parent(p), completesWord(cw)
		{
			children.clear();
		}

		char val;
		TrieNode* parent;
		bool completesWord;
		TrieMap children;
	};



public:
	Trie()
	{
		root = new TrieNode('\0', true);
	}


	~Trie()
	{

	}


	void insert(string str) const
	{
		// YOUR CODE GOES HERE
		TrieNode* end;
		int len = findPrefixEnd(str, end);

		for (; len < str.length(); len++) {
			end->children.insert(pair<char, TrieNode*>(str[len], new TrieNode(str[len], false, end)));
			findPrefixEnd(str, end);
		}
		end->completesWord = true;
	}


	bool search(string str) const
	{
		// YOUR CODE GOES HERE
		TrieNode* end;
		unsigned int len = findPrefixEnd(str, end);
		cout << "Searching for: " << str << endl;
		cout << "end.val: " << end->val << endl;
		cout << "cw: " << end->completesWord << endl;
		cout << "len: " << len << endl;

		if (len == str.length() && end->completesWord)
			return true;
		else
			return false;
	}


	void remove(string str) const
	{
		// YOUR CODE GOES HERE
		if (!search(str))
			return;

		TrieNode* cur;
		int len = findPrefixEnd(str, cur);

		if (!cur->children.empty()) {
			cur->completesWord = false;
			return;
		} else {
			TrieNode* parent = cur->parent;

			while (!parent->completesWord) {
				if (parent->children.empty() || parent->children.size() > 1)
					break;
				cout << "Erasing val: " << cur->val << " in \"" << str << "\"" << endl;
				parent->children.erase(cur->val);
				cur = parent;
				parent = parent->parent;
			}

			parent->children.erase(cur->val);
		}
	}

	void findAllWithPrefix(string prefix, vector<string>& strings) const
	{
		// YOUR CODE GOES HERE
	}


private:

	// findPrefixEnd: 
	// Sets the parameter end to the last node in the prefix of str and returns the length of the prefix
	unsigned int findPrefixEnd(string str, TrieNode*& end) const
	{
		TrieNode* cur = root;
		TrieMapIter res;
		unsigned int i = 0;

		// Find (part of) key already in trie
		for (; i < str.length(); i++)
		{
			if ((res = cur->children.find(str[i])) != cur->children.end())
			{
				cur = res->second;
			}
			else break;
		}

		end = cur;
		return i;
	}


	TrieNode* root;
};
