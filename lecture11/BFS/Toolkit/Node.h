#pragma once

#include<vector>
#include"Edge.h"

using std::string;
using namespace std;


namespace Graphs
{
	class Node
	{
	public:
		Node(string d = "");

		string label;
		vector<Edge*> neighbors;
		size_t cost;
		Node* prev;
		int x;
		int y;
		
		friend ostream& operator<<(ostream& out, Node& g);
	};
}



