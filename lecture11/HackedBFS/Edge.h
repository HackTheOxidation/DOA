#ifndef EDGE_H
#define EDGE_H
#include <ostream>

using std::ostream;

namespace PathFinder {
	class Node;

	class Edge {
	public:
		Edge(Node* f = nullptr, Node* t = nullptr, int w = 1);

		Node* from;
		Node* to;
		int weight;

		friend ostream& operator<<(ostream& out, Edge& e);
	};
}

#endif
