#include"Node.h"
#include<iostream>
#include <map>
#include <fstream>
#include <queue>
#include <string>
#include "GraphToolkit.h"
#include <list>
#include <sstream>
#include <vector>

using namespace std;


namespace Graphs
{


	typedef map<string, Node*> GraphMap;
	typedef GraphMap::iterator GraphMapIter;


	void tokenize(const string& str, vector<string>& tokens, const string& delimiters)
	{
		size_t lastPos = str.find_first_not_of(delimiters, 0);
		size_t pos = str.find_first_of(delimiters, lastPos);
		tokens.clear();

		while (string::npos != pos || std::string::npos != lastPos)
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}
	}

	void addEdge(Node*& from, Node*& to, int weight = 1)
	{
		from->neighbors.push_back(new Edge(from, to, weight));
	}


	//===============================================================
	// PRE:		
	// POST:	If a Node with label = lbl is in graph, it is returned. 
	//			Otherwise, nullptr is returned
	//===============================================================
	Node* findNode(Graph& g, string lbl)
	{
		for (GraphIter ix = g.begin(); ix != g.end(); ++ix)
			if ((*ix)->label == lbl) return *ix;
		return nullptr;
	}


	//===============================================================
	// PRE:		
	// POST:	All nodes in 'g' have been printed
	//===============================================================
	void print(Graph& g)
	{
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			cout << **curNode << endl;
		}
	}



	//===============================================================
	// PRE:		File 'filename' contains a definition of a graph of this format:
	//			
	//			// C-style single-line comments allowed
	//			// Definition of A with neighbors B and C
	//			// and B with neighbors D and A
	//			A: B, C
	//			B: D, A
	// POST:	'graph' is read from the file 'filename'. Format of the file:
	//
	//===============================================================
	void readNodeList(Graph& graph, string filename, bool directed)
	{
		GraphMap graphMap;
		string labels, source;

		graph.clear();
		ifstream file(filename);

		if (!file.good()) throw "Bad filename";

		try {
			// Read file line-by-line. For each line, read node and neighbors
			while (!file.eof())
			{
				// Read a single line
				vector<string> tokens;
				vector<string> labelAndWeightTokens;
				string labelAndWeight;
				string label;
				int weight;

				getline(file, labels);

				tokenize(labels, tokens, DELIMITERS);

				// Skip if the line is a comment
				if (tokens.size() > 0 && tokens.begin()->substr(0, COMMENT_PREFIX.size()) != COMMENT_PREFIX)
				{
					for (vector<string>::iterator token = tokens.begin(); token != tokens.end(); ++token)
					{
						labelAndWeight = *token;
						// If this is the first node label on the line, it is the source
						// do not add edge, but remember the label
						if (token == tokens.begin())
						{
							source = labelAndWeight;

							// If node is unknown, add it to the graph(map)
							if (graphMap.count(source) == 0)
							{
								graphMap[source] = new Node(source);
								graph.push_back(graphMap[source]);
							}
						}
						else // Otherwise, add an edge
						{
							labelAndWeightTokens.clear();
							tokenize(labelAndWeight, labelAndWeightTokens, LABEL_WEIGHT_SEPARATOR);
							label = labelAndWeightTokens[0];
							weight = labelAndWeightTokens.size() == 2 ? atoi(labelAndWeightTokens[1].c_str()) : 1;

							// If node is unknown, add it to the graph(map)
							if (graphMap.count(label) == 0)
							{
								graphMap[label] = new Node(label);
								graph.push_back(graphMap[label]);
							}

							// Create an edge and add it to the graph, if it doesn't already exist
							bool neighborExists = false;
							for (auto ix = graphMap[source]->neighbors.begin(); ix != graphMap[source]->neighbors.end(); ++ix)
							{
								if ((*ix)->to == graphMap[label])
								{
									neighborExists = true;
									break;
								}
							}

							if (!neighborExists)
							{
								addEdge(graphMap[source], graphMap[label], weight);
								if (!directed) addEdge(graphMap[label], graphMap[source], weight);
							}
						}
					}
				}
			}
		}
		catch (...) {
			std::cout << "failed to read file" << std::endl;
		}
	}


	void readEdgeList(Graph& graph, string filename, bool directed)
	{
		graph.clear();
		ifstream file(filename);
		GraphMap graphMap;
		string labels, source;

		if (!file.good()) throw "Bad filename";

		// Read file line-by-line. For each line, read from-label, to-label and weight
		while (!file.eof())
		{
			vector<string> tokens;
			string from;
			string to;
			int weight;
			bool weightedGraph;

			// Read a single line
			getline(file, labels);

			// Tokenize
			tokenize(labels, tokens, DELIMITERS);

			// Skip if the line is a comment
			if (tokens.size() > 0 && tokens.begin()->substr(0, COMMENT_PREFIX.size()) != COMMENT_PREFIX)
			{
				switch (tokens.size())
				{
					case 2:		weightedGraph = false; break;
					case 3:		weightedGraph = true; break;
					default:	throw "Malformed edge list";
				}

				for (vector<string>::iterator textIter = tokens.begin(); textIter != tokens.end();)
				{
					from = *textIter++;
					to = *textIter++;

					weight = weightedGraph ? stoi(*textIter++) : 1;

					// If from-node is unknown, add it to the graph(map)
					if (graphMap.count(from) == 0)
					{
						graphMap[from] = new Node(from);
						graph.push_back(graphMap[from]);
					}

					// If to-node is unknown, add it to the graph(map)
					if (graphMap.count(to) == 0)
					{
						graphMap[to] = new Node(to);
						graph.push_back(graphMap[to]);
					}

					// Create an edge and add it to the graph
					bool neighborExists = false;
					for (auto ix = graphMap[from]->neighbors.begin(); ix != graphMap[from]->neighbors.end(); ++ix)
					{
						if ((*ix)->to == graphMap[to])
						{
							neighborExists = true;
							break;
						}
					}
					if (!neighborExists)
					{
						addEdge(graphMap[from], graphMap[to], weight);
						if (!directed) addEdge(graphMap[to], graphMap[from], weight);
					}
				}
			}
		}
	}

	//===============================================================
	// PRE:		
	// POST:	All nodes in 'g' have been reset so that they are 
	//			unmarked and have the defined (default infinite) cost
	//===============================================================
	void resetCost(Graph g, int cost)
	{
		for (GraphIter ix = g.begin(); ix != g.end(); ++ix)
		{
			(*ix)->cost = cost;
		}
	}


	void reset(Graph g, int cost)
	{
		for (GraphIter ix = g.begin(); ix != g.end(); ++ix)
		{
			(*ix)->cost = cost;
			(*ix)->prev = nullptr;
		}
	}


	//===============================================================
	// PRE:		
	// POST:	If Node n is in graph, true is returned
	//			Otherwise, false is returned
	//===============================================================
	//
	/*
	bool isInGraph(Graph g, Node* n)
	{
		return find(g.begin(), g.end(), n) != g.end();
	}
	*/


	//===============================================================
	// PRE:		
	// POST:	Paths from "startLbl" to all other nodes have been printed
	//===============================================================
	void printPaths(Graph& graph, string startNodeLabel)
	{
		// Dump all paths
		for (GraphIter ix = graph.begin(); ix != graph.end(); ++ix)
		{
			if ((*ix)->label != startNodeLabel)
			{
				cout << "Path from " << startNodeLabel.c_str() << " to " << (*ix)->label.c_str() << ": ";
				printPath(graph, startNodeLabel, (*ix)->label);
				cout << endl;
			}
		}
	}


	//===============================================================
	// PRE:		
	// POST:	Path from "from" to "to" has been printed
	//===============================================================
	void printPath(Graph& g, string fromLbl, string toLbl)
	{
		list<Node*> path;
		
		Node* from = findNode(g, fromLbl);
		Node* to = findNode(g, toLbl);
		Node* cursor = to;

		if (from == nullptr || to == nullptr)
		{
			cout << "No path exists from " << fromLbl << " to " << toLbl << endl;
			return;
		}

		while(cursor != from && cursor->prev != nullptr)
		{
			path.push_front(cursor);
			cursor = cursor->prev;
		}
		
		path.push_front(cursor);
		
		for (auto ix = path.begin(); ix != path.end();)
		{
			cout << (*ix)->label;
			if (++ix != path.end()) cout << " -> ";
		}
	}


	enum
	{
		NORTH, EAST, SOUTH, WEST
	};



	//===============================================================
	// PRE:		size >= 2
	// POST:	Graph has been updated to represent a size x size four-way grid
	//
	// NOTE:	Nodes are labeled "[row;col]" for the row-col'th node in the grid.
	//===============================================================
	void createFourWayGrid(Graph& graph, int size)
	{
		if (size < 2) throw "Grid size too small - must be >= 2";

		resetCost(graph);
		Node** nodes = new Node*[size*size];

		// Initialize nodes
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				ostringstream label;
				label << "[" << row << ";" << col << "]";
				nodes[size* row + col] = new Node(label.str());
				nodes[size* row + col]->x = col;
				nodes[size* row + col]->y = row;


				// Initialize neighbors
				for (int i = 0; i < 4; i++)
				{
					nodes[size*row + col]->neighbors.push_back(nullptr);
				}

				graph.push_back(nodes[size*row + col]);
			}
		}

		// (1): Connect corners
		// NW corner
		nodes[0 + 0]->neighbors[EAST] = new Edge(nodes[0 + 0], nodes[0 + 1]);
		nodes[0 + 0]->neighbors[SOUTH] = new Edge(nodes[0 + 0], nodes[size * 1 + 0]);

		// NE corner
		nodes[0 + size - 1]->neighbors[SOUTH] = new Edge(nodes[0 + size - 1], nodes[(size * 1) + size - 1]);
		nodes[0 + size - 1]->neighbors[WEST] = new Edge(nodes[0 + size - 1], nodes[0 + size - 2]);

		// SW corner
		nodes[size*(size - 1) + 0]->neighbors[NORTH] = new Edge(nodes[size*(size - 1) + 0], nodes[size*(size - 2) + 0]);
		nodes[size*(size - 1) + 0]->neighbors[EAST] = new Edge(nodes[size*(size - 1) + 0], nodes[size*(size - 1) + 1]);

		// SE corner
		nodes[size*(size - 1) + size - 1]->neighbors[NORTH] = new Edge(nodes[size*(size - 1) + size - 1], nodes[size*(size - 2) + size - 1]);
		nodes[size*(size - 1) + size - 1]->neighbors[WEST] = new Edge(nodes[size*(size - 1) + size - 1], nodes[size*(size - 1) + size - 2]);


		// (2) Connect edges
		for (int i = 1; i < size - 1; i++)
		{
			// North edge
			nodes[0 + i]->neighbors[EAST] = new Edge(nodes[0 + i], nodes[0 + i + 1]);
			nodes[0 + i]->neighbors[SOUTH] = new Edge(nodes[0 + i], nodes[size * 1 + i]);
			nodes[0 + i]->neighbors[WEST] = new Edge(nodes[0 + i], nodes[0 + i - 1]);

			// North south edge
			nodes[size*(size - 1) + i]->neighbors[EAST] = new Edge(nodes[size*(size - 1) + i], nodes[size*(size - 1) + i + 1]);
			nodes[size*(size - 1) + i]->neighbors[NORTH] = new Edge(nodes[size*(size - 1) + i], nodes[size*(size - 2) + i]);
			nodes[size*(size - 1) + i]->neighbors[WEST] = new Edge(nodes[size*(size - 1) + i], nodes[size*(size - 1) + i - 1]);

			// West edge
			nodes[size*i + 0]->neighbors[NORTH] = new Edge(nodes[size*i + 0], nodes[size*(i - 1) + 0]);
			nodes[size*i + 0]->neighbors[EAST] = new Edge(nodes[size*i + 0], nodes[size*i + 1]);
			nodes[size*i + 0]->neighbors[SOUTH] = new Edge(nodes[size*i + 0], nodes[size*(i + 1) + 0]);

			// East edge
			nodes[size*i + size - 1]->neighbors[NORTH] = new Edge(nodes[size*i + size - 1], nodes[size*(i - 1) + size - 1]);
			nodes[size*i + size - 1]->neighbors[WEST] = new Edge(nodes[size*i + size - 1], nodes[size*i + size - 2]);
			nodes[size*i + size - 1]->neighbors[SOUTH] = new Edge(nodes[size*i + size - 1], nodes[size*(i + 1) + size - 1]);
		}

		// (3) Connect inner nodes
		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 1; j < size - 1; j++)
			{
				nodes[size*i + j]->neighbors[NORTH] = new Edge(nodes[size*i + j], nodes[size*(i - 1) + j]);
				nodes[size*i + j]->neighbors[EAST] = new Edge(nodes[size*i + j], nodes[size*i + j + 1]);
				nodes[size*i + j]->neighbors[SOUTH] = new Edge(nodes[size*i + j], nodes[size*(i + 1) + j]);
				nodes[size*i + j]->neighbors[WEST] = new Edge(nodes[size*i + j], nodes[size*i + j - 1]);
			}
		}
	}


	//===============================================================
	// PRE:		Graph represents a four-way grid see "createGrid()"
	// POST:	A wall has been created at grid[x,y]
	//
	// NOTE:	
	//===============================================================
	void createWall(Graph& graph, int row, int col)
	{
		ostringstream label;
		label << "[" << row << ";" << col << "]";
		
		Node* wall = findNode(graph, label.str());

		if (wall == nullptr) throw "Node not found";

		if (wall->neighbors[NORTH] != nullptr)
		{
			wall->neighbors[NORTH]->to->neighbors[SOUTH] = nullptr;
			wall->neighbors[NORTH] = nullptr;
		}

		if (wall->neighbors[EAST] != nullptr)
		{
			wall->neighbors[EAST]->to->neighbors[WEST] = nullptr;
			wall->neighbors[EAST] = nullptr;
		}

		if (wall->neighbors[SOUTH] != nullptr)
		{
			wall->neighbors[SOUTH]->to->neighbors[NORTH] = nullptr;
			wall->neighbors[SOUTH] = nullptr;
		}

		if (wall->neighbors[WEST] != nullptr)
		{
			wall->neighbors[WEST]->to->neighbors[EAST] = nullptr;
			wall->neighbors[WEST] = nullptr;
		}
	}
}
