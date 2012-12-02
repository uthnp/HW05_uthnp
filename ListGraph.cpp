#include "ListGraph.h"

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
	NWPair temp;

	//to cycle, have to check, then pop... need to retain the data, so we have to put it back in somewhere
	for (int i = 0; i < edgeList.at(u).size(); i++)
	{
		temp = edgeList.at(u).front(); //copy the first item in the list
		if (temp.first == v)
		{
			return temp.second;
		}
		edgeList.at(u).pop_front(); //take item off main list
		edgeList.at(u).push_back(temp); //put copy of item back on back-end of list
	}

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