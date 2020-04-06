#include <iostream>
#include <vector>
#include <set>

struct Node{
	Node(int data = 0);
	int data;
	std::vector<Node*>;
};

class Graph{
private:
	size_t numVerticies;
	std::set<int> verticies;
	std::vector< std::vector<Node*>> adjacenyList;
public:
	Graph();

	~Graph();

	Graph& operator=(const Graph&);

	Graph(const Graph&);

	size_t size();

	//checks if a number is already in our set of verticies
	bool inGraph(int) const;

	Node* findNode(int) const;

	void addEdge(int,int);

	printGraph();
}