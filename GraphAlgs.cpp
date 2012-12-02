#include "GraphAlgs.h"
#include <queue>


/* 
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 *  vists every node exactly once (with exception of the first node, which is repeated as the 
 *  last node in the cycle.)
 *
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting them of weight > 0.
 */


/*std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	//attempting the naieve version that just follows the shortest distance for the most immediate edge available

	std::vector<NodeID> pathVect;
	pathVect.push_back(0); //start at node 0
	EdgeWeight distance = 0;

	NodeID currentNext;
	EdgeWeight minWeight;

	int iter = 1; //keeps track of number of moves

	while (iter < G->size())
	{
		pathVect.push_back(u);
		for (int v = 0; v < (G->size()-1); v++)
		{

		}

		iter++;
	}
	
	return std::pair<std::vector<NodeID>, EdgeWeight>(pathVect, distance);
}*/

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	//pick first node to start from
	NodeID s = 0;

	//data for results
	std::vector<NodeID> pathVect;
	EdgeWeight distance = 0;

	//Based on the Breadth First Search algorithm we covered in class (CSE 274) on 11/29/12
	std::queue<int> openList;
	int* seenList;
	openList.push(s);
	seenList[s] = s;
	int u;
	while(!openList.empty())
	{
		u = openList.front(); openList.pop();
		//use iterator to go through all values of v (neighbors of u)
		for (int v = 0; v < G->degree(u); v++)
		{
			if (seenList[v] == -1)
			{
				seenList[v] = u;
				openList.push(v);
			}
		}
	}

	return std::pair<std::vector<NodeID>, EdgeWeight>(pathVect, distance); 
}