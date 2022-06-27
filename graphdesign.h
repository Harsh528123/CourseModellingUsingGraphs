#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>

using namespace std;

/*
  Represents a graph using an adjacency list representation.
  Vertices will be courses' names;
*/
class Directedgraph {
public:

  // return the number of outgoing neighbours of v
  int numNeighbours(string vertex);

  // returns the number of nodes
  int size();

  // return a vector with all vertices
  vector<string> getAllVertices();
  // add a vertex, does nothing if it already exists
  void adding_Vertex(string vertex);

  // adds an edge, creating the vertices if they do not exist
  // if the edge already existed, does nothing
  void adding_Edge(string firstvertex, string secondvertex);

  // returns true if and only if v is a vertex in the graph
  bool isItAVertex(string vertex);


  // returns true if and only if (u,v) is an edge in the graph
  // will certainly return false if neither vertex is in the graph
  bool isItAnEdge(string firstvertex, string secondvertex);

  // returns true if 'path' represents a path on this graph
  // a path is a walk with no repeated vertices
  bool isPathValid(vector<string> path);

  unordered_map<string,string> shortestPath(string vertex1, string vertex2);

private:
  // with this representation the amortized time for 
  // finding or adding a vertex or an edge is O(1)
  unordered_map<string, unordered_set<string>> neighbours;
};

#endif