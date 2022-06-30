#include "graphDesign.h"
#include <iostream>
#include <string>

int Directedgraph::numNeighbours(std::string vertex){
    return neighbours[vertex].size();
}

int Directedgraph::size(){
    // size of the graph is the number of nodes; easiest way to find it is by seeing how many items in unordered_map
    return neighbours.size();
}

std::vector<std::string> Directedgraph::getAllVertices(){
    std::vector<std::string> allVertices;
    for (std::pair<std::string, std::unordered_set<std::string>> element: neighbours){
        allVertices.push_back(element.first);
    }
    return allVertices;
}

void Directedgraph::adding_Vertex(std::string vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        std::cout<<"Vertex already exists" << std::endl;
    } else{
        neighbours[vertex];
    }
}

 void Directedgraph::adding_Edge(std::string firstvertex, std::string secondvertex){
    neighbours[firstvertex].insert(secondvertex);
    // adds secondvertex in the set
 }

 bool Directedgraph::isItAVertex(std::string vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        return true;
    } else{
        return false; 
    }
 }

bool Directedgraph::isItAnEdge(std::string firstvertex, std::string secondvertex){
    if (isItAVertex(firstvertex) && isItAVertex(secondvertex)){
        if (neighbours[firstvertex].find(secondvertex) != neighbours[firstvertex].end()){
        return true;
        } else {
            return false;
        }
    }
    else {
        std::cout<<"One of the vertices does not exist in the graph"<< std::endl;
        return false; 
    }
}

bool Directedgraph::isPathValid(std::vector<std::string> path){
    // path is a walk with no repeated vertices. 
    bool pathway=false;
    for (int i=0; i<path.size()-1; i++){
        if(isItAVertex(path[i]) && isItAnEdge(path[i],path[i+1])){
            // if it is a neighbour 
            pathway=true;
        } else{
            pathway=false;
        }
    }
    return pathway;
}










