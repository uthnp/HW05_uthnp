#include "GraphAlgs.h"
#include <queue>
#include "Graph.h"

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
	NodeID s = 0; //starting node
	std::queue<NodeID> openList;
	int* seenList;
	openList.push(s);
	seenList[s] = s;
	
	NodeID u;
	while(!openList.empty())
	{
		u = openList.front(); openList.pop();
		//for loop... use iterator to go through all neighbors of u
		for(int v = 0; v < G->size(); v++)
		{
			if (seenList[v] < 0)
			{
				seenList[v] = u;
				openList.push(v);
			}
		}
	}
}*/

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
}