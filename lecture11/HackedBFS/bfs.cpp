#include <queue>
#include <iostream>
#include "GraphToolkit.h"

using namespace PathFinder;

int breadthFirstSearch(Graph g, Node* startNode, Node* endNode) {
	queue<Node*>* frontier = new queue<Node*>();
	Node* next = nullptr;
	int nNodesVisited = 0;

	reset(g);
	frontier->push(startNode);

	while (!frontier->empty()) {
		Node* current = frontier->front();
		frontier->pop();

		if (current->label.compare(endNode->label) == 0) 
			break;
			
		for (Edge* e : current->neighbors) {
			if (e == nullptr || e->to == nullptr)
				continue;

			Node* n = e->to;
			
			if (n->prev == nullptr) {
				n->prev = current;
				nNodesVisited++;

				// Avoid Segmentation Fault
				Node* discovered = new Node(n->label);
				(*discovered) = (*n);
				frontier->push(discovered);
			}
		}
	}	
	
	return nNodesVisited;
}

int main() {
	Graph graph;
	readNodeList(graph, "BFS.txt");

	createFourWayGrid(graph, 10);
	createWall(graph, 3, 3);
	createWall(graph, 3, 4);
	createWall(graph, 3, 5);
	createWall(graph, 4, 5);
	createWall(graph, 5, 5);
	createWall(graph, 6, 5);
	createWall(graph, 7, 5);

	Node* s = findNode(graph, "[7;2]");
	Node* t = findNode(graph, "[5;6]");

	int nNodesVisited = breadthFirstSearch(graph, s, t);

	cout << "Path:   ";
	printPath(graph, s->label, t->label);

	cout << endl << "Nodes visited: " << nNodesVisited << endl;
	return 0;
}
