#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

Node::Node(int data = 0): data(data);

Graph::Graph() : verticies(0) {}

Graph::~Graph(){

}

Graph& Graph::operator=(const Graph&);

Graph::Graph(const Graph&);

bool Graph::inGraph(int num) const {
	return(find(verticies.begin(),verticies.end(),val) 
		== verticies.end());
}

Node* Graph::findNode(int num) const {
	Node* currNode;

	for(size_t i = 0; i < adjacencyList.size(); ++i){
		if(adjacencyList[i][0].data == num){
			currNode = adjacencyList[i][0]
		}else if(adjacencyList[i][1].data == num){
			currNode = adjacencyList[i][1];
		}
	}
	return currNode;
}

void Graph::addEdge(int num1,int num2){
	if(inGraph(num1) && inGraph(num2)){
		verticies.insert(num1);
		verticies.insert(num2);

		Node* node1 = new Node(num1);
		Node* node2 = new Node(num2);

		vector<Node*> newEdge{node1,node2};
		adjacencyList.push_back(newEdge);
	}else if(inGraph(num1) && !inGraph(num2)){
		verticies.insert(num2);

		Node* newNode = new Node(num2);

		//Locate Other Node;
		Node* currNode = findNode(num1);

		vector<Node*> newEdge{currNode, newNode};

		adjacencyList.push_back(newEdge);


	}else if(!inGraph(num1) && inGraph(num2)){
		verticies.insert(num1);
		Node* newNode = new Node(num1);

		//Locate Other Node;
		Node* currNode = findNode(num2);

		vector<Node*> newEdge{currNode,newNode};

		adjacencyList.push_back(newEdge);

	}

}




















