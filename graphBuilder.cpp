#include "graphDesign.h"
#include <iostream>
#include <string>
#include <queue>

int Directedgraph::numNeighbours(std::string& vertex){
    return neighbours[vertex].size();
}

int Directedgraph::size(){
    // size of the graph is the number of nodes; easiest way to find it is by seeing how many items in unordered_map
    return neighbours.size();
}

std::vector<std::string> Directedgraph::getAllVertices(){
    std::vector<std::string> allVertices;
    for (auto& element: neighbours){
        allVertices.push_back(element.first);
    }
    return allVertices;
}

void Directedgraph::adding_Vertex(std::string& vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        std::cout<<"Vertex already exists" << std::endl;
    } else{
        neighbours[vertex];
    }
}

 void Directedgraph::adding_Edge(std::string& firstvertex, std::string& secondvertex){
    neighbours[firstvertex].insert(secondvertex);
    // adds secondvertex in the set
 }

 bool Directedgraph::isItAVertex(std::string& vertex){
    if (neighbours.find(vertex)!=neighbours.end()){
        return true;
    } else{
        return false; 
    }
 }

bool Directedgraph::isItAnEdge(std::string& firstvertex, std::string& secondvertex){
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

bool Directedgraph::checkExactPath(std::vector<std::string>& path){
    // path is a walk with no repeated vertices. 
    bool Notpathway=true;
    for (long long unsigned int i=0; i<path.size()-1; i++){
        if(isItAVertex(path[i]) && isItAnEdge(path[i],path[i+1])){
            // if it is a neighbour 
            Notpathway=false;
        } else{
            Notpathway=true;
            break;
        }
    }
    // return the opposite
    return (!Notpathway) ;
}

std::vector<std::string> Directedgraph::checkCoursesAfterPrereq(std::string& prerequisite){
    std::vector<std::string> coursesAfterPrereq;
    for (auto itr = neighbours[prerequisite].begin(); itr!=neighbours[prerequisite].end(); itr++){
        // go through all elements in the set which is the value to the key value pair where key is a course 
        coursesAfterPrereq.push_back(*itr);
    }
    return coursesAfterPrereq;
}

bool Directedgraph::checkingForCycle(){

    std::unordered_map<std::string,int> indegree;
    // indegree means the number of arrows pointing to a course so key is course and value is number of arrows pointing to it
    for (auto& course: neighbours){
       for (auto prereq = course.second.begin(); prereq!=course.second.end(); prereq++){
            indegree[*prereq]=indegree[*prereq]+1;
       }
    }


    std::queue<std::string> zeroIndegree; 
    // if a course has zero indegrees we explore it 
    for (auto& it:neighbours){
        if (indegree[it.first]==0){
            zeroIndegree.push(it.first);
        }
    }
    std::vector <std::string> topologicalArr;
    while (!zeroIndegree.empty()){
        std::string theZeroIndegree = zeroIndegree.front();
        zeroIndegree.pop();
        // lets explore the zero indegree course and add it's neighbours 
        topologicalArr.push_back(theZeroIndegree);
        for (auto it = neighbours[theZeroIndegree].begin(); it!=neighbours[theZeroIndegree].end(); it++){
            // for each neighbour decrement it 
            indegree[*it]--;
            if (indegree[*it]==0){
                zeroIndegree.push(*it);
            }
        }
    }
    if (topologicalArr.size()!=indegree.size()){
        return true;
    } else{
        return false;
    }

}

void Directedgraph::deletingCourse(std::string& deletingcourse){
    // delete the course from the unordered_map as a key and from every unordered set it is in
    std::vector<std::string> deletingcourses;
    for (auto& course: neighbours){
        if (course.first==deletingcourse){
            deletingcourses.push_back(course.first);
            continue;
        }
        std::string theCourse=course.first;
        for (auto neighbour = neighbours[theCourse].begin(); neighbour!=neighbours[theCourse].end(); neighbour++){
            if (*neighbour==deletingcourse){
                deletingcourses.push_back(theCourse);
            }
        }
    }
    for (int i=0; i<deletingcourses.size(); i++){
        if (deletingcourses[i]==deletingcourse){
            neighbours.erase(deletingcourse);
        } else {
            neighbours[deletingcourses[i]].erase(deletingcourse);
        }
    }
}










