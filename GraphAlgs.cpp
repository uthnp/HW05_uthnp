/* 
 * @author Nicholas Uth
 *
 * This cpp file satisfies the TSP aspects of the homework (C & D). The results are at least accurate with the testing
 * methods. Since the TSP search works on a recursive pattern (based on depth-first search) it should be faster than the
 * brute force methods (although, it's still somewhat slow, over 2 seconds each analysis when more than 100 nodes are involved).
 *
 */

#include "GraphAlgs.h"
#include <queue>
#include "Graph.h"


// searches a vector object (like those used in the graph classes) for an item. If the item is inside the vector, returns true.
// returns false otherwise
bool existsInVector(std::vector<NodeID>* vector, NodeID item)
{
	std::vector<NodeID>* clone = new std::vector<NodeID>(*vector);

	while (clone->size() > 0)
	{
		if (clone->back() == item)
		{
			delete clone;
			return true;
		}
		clone->pop_back();
	}

	delete clone;
	return false;
}

std::pair<std::vector<NodeID>, EdgeWeight> recurseDepth(Graph* G, NodeID currentNode, std::vector<NodeID>* path, EdgeWeight weight)
{
	//conditional clauses
	if (currentNode < 0) {return std::pair<std::vector<NodeID>, EdgeWeight> (NULL, 0);}
	if (path->size() == G->size()) {return std::pair<std::vector<NodeID>, EdgeWeight> (*path, weight);}
	//if (existsInVector(path, currentNode)) {return std::pair<std::vector<NodeID>, EdgeWeight> (NULL, 0);}

	//update the path and weight
	if (path->size() > 0)
		weight += G->weight(path->back(),currentNode);
	path->push_back(currentNode);

	//get the list of adjacent nodes
	std::list<NWPair> adj = G->getAdj(currentNode);
	//remove visited pairs

	// create placeholder that will hold the info about the path with the smallest weight
	std::pair<std::vector<NodeID>, EdgeWeight> minPair;
	std::pair<std::vector<NodeID>, EdgeWeight> tempPair;

	std::list<NWPair>::iterator iter = adj.begin(); //iterator for the list
	
	bool key = true;
	while (key)
	{
		if (iter == adj.end())
		{
			return std::pair<std::vector<NodeID>, EdgeWeight> (*path, weight);
		}
		if(existsInVector(path, iter->first)) //get a base path for comparison
			iter++;
		else
			key = false;
	}
	
	minPair = recurseDepth(G, iter->first, path, weight);
	iter++;

	//loop through all option paths and recurse down each... compare each recursion to it's competetors, one with the shortest path stays
	for (iter; iter != adj.end(); iter++)
	{
		if (!existsInVector(path, iter->first)) //get a base path for comparison
		{
			tempPair = recurseDepth(G, iter->first, path, weight);
			if (tempPair.second < minPair.second)
			{
				minPair = tempPair;
			}
		}
	}

	return minPair;
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	//attempting a recursive method
	NodeID startNode = 0;
	std::vector<NodeID>* vect = new std::vector<NodeID>();
	EdgeWeight dist = 0;

	std::pair<std::vector<NodeID>, EdgeWeight> results;
	results = recurseDepth(G, startNode, vect, dist);
	results.second += G->weight(startNode, vect->back()); //to get the distance required to get back to the first location

	return results;
}