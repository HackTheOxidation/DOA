#pragma comment(lib,"../x64/Debug/Toolkit.lib")

#include "../Toolkit/GraphToolkit.h"
#include <queue>
#include <iostream>

using namespace Graphs;
using std::queue;

int bfs(Graph g, Node* startNode, Node* endNode)
{
	queue<Node*> frontier;
	Node* next = nullptr;
	int nNodesVisited = 0;

	// Initialize
	reset(g);
	frontier.push(startNode);

	/* YOUR BFS CODE HERE */
	
	
	return nNodesVisited;
}


int main()
{
	Graph graph;
	readNodeList(graph, "BFS.txt");


	//bfs(graph, findNode(graph, "A"), findNode(graph, "F"));
	//print(graph);


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

	int nNodesVisited = bfs(graph, s, t);

	cout << "Path:   ";
	printPath(graph, s->label, t->label);

	cout << endl << "Nodes visited: " << nNodesVisited << endl;
	return 0;
}
