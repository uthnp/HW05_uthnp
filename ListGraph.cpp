#include "ListGraph.h"

ListGraph::ListGraph(int numNodes)
{
	// single vector that points to lists w/ respect to each node
	// lists contain edge info for that particular node:
		// which node the edge connects to
		// the weight of the edge

	//edgeList = 
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
}

unsigned ListGraph::degree(NodeID u)const
{
}

unsigned ListGraph::size() const
{
}

unsigned ListGraph::numEdges() const
{
}