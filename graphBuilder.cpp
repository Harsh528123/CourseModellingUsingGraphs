#include "graphDesign.h"
#include <iostream>
using namespace std;
#include <queue>
#include <string>

int Directedgraph::numNeighbours(string vertex){
    return neighbours[vertex].size();
}

int Directedgraph::size(){
    // size of the graph is the number of nodes; easiest way to find it is by seeing how many items in unordered_map
    return neighbours.size();
}

vector<string> Directedgraph::getAllVertices(){
    vector<string> allVertices;
    for (pair<string, unordered_set<string>> element: neighbours){
        allVertices.push_back(element.first);
    }
    return allVertices;
}

void Directedgraph::adding_Vertex(string vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        cout<<"Vertex already exists" << endl;
    }
    else{
        neighbours[vertex];
    }
}

 void Directedgraph::adding_Edge(string firstvertex, string secondvertex){
    neighbours[firstvertex].insert(secondvertex);
    // adds secondvertex in the set
 }

 bool Directedgraph::isItAVertex(string vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        return true;
    }
    else{
        return false; 
    }
 }

bool Directedgraph::isItAnEdge(string firstvertex, string secondvertex){
    if (isItAVertex(firstvertex) && isItAVertex(secondvertex)){
        if (neighbours[firstvertex].find(secondvertex) != neighbours[firstvertex].end()){
        return true;
        }
        else{
            return false;
        }
    }
    else {
        cout<<"One of the vertices does not exist in the graph"<< endl;
        return false; 
    }
}

bool Directedgraph::isPathValid(vector<string> path){
    // path is a walk with no repeated vertices. 
    bool pathway=false;
    for (int i=0; i<path.size()-1; i++){
        if(isItAVertex(path[i]) && isItAnEdge(path[i],path[i+1])){
            // if it is a neighbour 
            pathway=true;
        }
        else{
            pathway=false;
        }
    }
    return pathway;
}










