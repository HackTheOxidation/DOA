#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//-------------------------------------------------
// Class  : FileTokenizer
//
// Methods:
// read(filename, max_words) - Reads a comma separated 
//             file and stores content in a std::vector
//             Returns nbr of items in file
// next()    - Returns next value from vector
// getSize() - Returns vector size
// restart() - Sets next back to item zero
//-------------------------------------------------
class FileTokenizer
{
public:
	FileTokenizer() : nextWord(0)
	{
	}

	size_t read(string filename, int nWords)
	{	
		string tempstr;
		in.open(filename.c_str());
		if(!in) 
		{
			cout << "Error: File does not exist: " << filename << endl;
			throw exception();
		}

		while(!in.eof())
		{
			in >> tempstr;
			tokenize(tempstr, tokens, " .,!:", nWords);
		}
		in.close();

		random_shuffle(tokens.begin(), tokens.end());
		return tokens.size();
	}

	string next()
	{
		string retVal;
		if(tokens.size() > 0)
		{ 
			retVal = tokens[nextWord];
			nextWord = (nextWord+1)%tokens.size();
		}
		return retVal;
	}

	void restart() { nextWord = 0; }

	size_t getSize() { return tokens.size(); }
private:

	int tokenize(const string& str, vector<string>& tokens, const string& delimiters, int nWords)
	{
		size_t lastPos = str.find_first_not_of(delimiters, 0);
		size_t pos     = str.find_first_of(delimiters, lastPos);
		int nWordsRead = 0;
		while ((string::npos != pos || string::npos != lastPos) && nWordsRead < nWords)
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			++nWordsRead;
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}

		

		return nWordsRead;
	}
	size_t nextWord;
	ifstream in;
	vector<string> tokens;
};

