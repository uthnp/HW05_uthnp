#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int numNodes)
{
	// single vector that points to lists w/ respect to each node
	// lists contain edge info for that particular node:
		// which node the edge connects to
		// the weight of the edge
	EList* temp;

	for (int i = 0; i < numNodes; i++)
	{
		temp = new EList();
		edgeList.push_back(*temp);
	}

	this->num_edges = 0; //initialize as 0 for easy incrementation later
}

ListGraph::~ListGraph()
{
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	/* Hard way... will add in later
	for (int i = 0; i < edgeList.at(u).size(); i++)
	{
		if (edgeList.at
	}*/
	//easy way, doesnt check for doubles
	edgeList.at(u).push_back(*(new NWPair(v,weight)));
	this->num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	/*
	NWPair temp;
	std::list<NWPair>::iterator iter;
	iter = (edgeList.at(u)).begin();
	//to cycle, have to check, then pop... need to retain the data, so we have to put it back in somewhere
	for (iter; iter != edgeList.at(u).end(); iter++)
	{
		if ((*iter).first == v)
		{
			return temp.second;
		}
	}
	*/

	return -1;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	return edgeList.at(u);
}

unsigned ListGraph::degree(NodeID u)const
{
	return (edgeList.at(u)).size();
}

unsigned ListGraph::size() const
{
	return edgeList.size(); //return size of edgelist because it has 1 list for each node
}

unsigned ListGraph::numEdges() const
{
	return this->num_edges;
}