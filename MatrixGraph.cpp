/*
 * @author Nicholas Uth
 * 
 * Satisfies the Adjacency Matrix requirement for the homework (B). The class passes the built in testing methods.
 */

#include "MatrixGraph.h"
#include <vector>

 MatrixGraph::MatrixGraph(unsigned num_nodes)
 {
	 //num nodes = length of 2D array's sides... use 1D array, but it wraps
	 //each space in the array refers to the weight of the edge between node x and y
	 // if there is no edge between the two, put -1

	 //create a vector for each node, set all it's internal values to -1 and put it into M
	 M = std::vector<std::vector<EdgeWeight>>(num_nodes);
	 std::vector<EdgeWeight>* temp;

	 for (int i = 0; i < num_nodes; i++)
	 {
		temp = new std::vector<EdgeWeight>(num_nodes, 0);
		this->M.at(i) = *temp;
		delete temp;
	 }

	 //initialize the number of edges to 0 so we can easily increment it later
	 this->num_edges = 0;
 }

 MatrixGraph::~MatrixGraph()
 {
 }

 void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
 {
	 (M.at(u)).at(v) = weight;
	 (M.at(v)).at(u) = weight; //since it's a symetric matrix
	 this->num_edges++;
 }

 EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
 {
	 //std::vector<EdgeWeight> clone = (M.at(u));
	 //double d = t.at(v);
	 return (M.at(u)).at(v);
 }

 std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
 {
	 std::vector<EdgeWeight> clone = M.at(u);
	 //return a list of pairs (node# and weight of edge between it and u)
	 std::list<NWPair> results;
	 NWPair temp;
	 for (int i = 0; i < clone.size(); i++)
	 {
		 if(clone.at(i) > 0)
		 {
			results.push_front( NWPair(i, clone.at(i)));
		 }
	 }
	 return results;
 }

 unsigned MatrixGraph::degree(NodeID u) const
 {
	 //gets the number of edges that u shares with other nodes
	 int numAdj = 0;
	 for (int i = 0; i < M.size(); i++)
	 {
		 if ((M.at(u)).at(i) > -1) { numAdj++; }
	 }
	 return numAdj;
 }

 unsigned MatrixGraph::size() const
 {
	 return M.size();
 }

 unsigned MatrixGraph::numEdges() const
 {
	 return this->num_edges;
 }