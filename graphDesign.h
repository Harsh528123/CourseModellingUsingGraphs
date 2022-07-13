#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>

/*
  Represents a graph using an adjacency list representation.
  Vertices will be courses' names;
*/
class Directedgraph {
public:

  // return the number of outgoing neighbours of v
  int numNeighbours(std::string& vertex);

  // returns the number of nodes
  int size();

  // return a vector with all vertices
  std::vector<std::string> getAllVertices();
  // add a vertex, does nothing if it already exists
  void adding_Vertex(std::string& vertex);

  // adds an edge, creating the vertices if they do not exist
  // if the edge already existed, does nothing
  void adding_Edge(std::string& firstvertex, std::string& secondvertex);

  // returns true if and only if v is a vertex in the graph
  bool isItAVertex(std::string& vertex);


  // returns true if and only if (u,v) is an edge in the graph
  // will certainly return false if neither vertex is in the graph
  bool isItAnEdge(std::string& firstvertex, std::string& secondvertex);

  // returns true if 'path' represents a path on this graph
  // a path is a walk with no repeated vertices
  bool checkExactPath(std::vector<std::string>& path);

  // will find the shortest path between two courses 
  std::unordered_map<std::string,std::string> shortestPath(std::string& vertex1, std::string& vertex2);


  // will return all courses that require a certain prereq course 
  std::vector<std::string> checkCoursesAfterPrereq(std::string& prerequisite);

  bool checkingForCycle();

  void deletingCourse(std::string& deletingcourse);

  void deletingPrerequisite(std::string& course1, std::string& course2);

private:
  // with this representation the amortized time for 
  // finding or adding a vertex or an edge is O(1)
  std::unordered_map<std::string, std::unordered_set<std::string>> neighbours;
};

#endif