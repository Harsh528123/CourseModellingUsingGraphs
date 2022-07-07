#include "graphDesign.h"
#include <iostream>
#include <string>
//g++ -o graphUser -std=c++11 graphUser.cpp
using namespace std;
void printingIntro();
void userInput();
void parseUserInput(Directedgraph& , string& , bool&);

void printingIntro(){
    cout<< "\n\n\n"<<endl;
    cout<< "\t \t \t \t \t Welcome to the Course Modelling Application \n\n\n"<<endl;
    
    cout<<"Here are the Instructions" <<endl;

    const char * instructions = "This application is designed to allow someone to input courses as vertices of a directed graph and enable prerequisites using edges.\n\n\
To create a course type \"Create_C\" and then press enter and then type the course name \n\
To make a course a prerequisite for another course type \"GenerateP\", press enter, type course 1 and then course 2. This means course 1 is required for course 2 \n\
To see if the course exists type \"CheckC\" and then press enter and then type the course name\n\
To see if the prerequisite exists type \"CheckP\" and then press enter and then type the prereq course and then with a space type the second course\n\
To view all courses type \"ViewC\" and then press enter and then you will see each course along with the courses it is a prerequisite to\n\
To know the number of courses that have a specific course as a prerequisite type \"ViewC_AfterPrereq\" and then press enter and then the prereuisite course name\n\
To check if an exact path exists type \"ExactPath?\", press enter and then type all the courses necessary and press enter again to stop\n\
To know the total number of courses type \"HowManyCourses\" and then press enter and then you will see a number \n\
To know if there is sort of cycle which means there is an endless loop of following prerequisities type \"CheckForCycle\" \n\
To quit type \"Quit\" and press enter \n";
    printf("%s\n", instructions);
}

void userInput(){
     /*
    Description: takes in userInput until user specifies exist 
    Arguments: nothing
    Returns: nothing
    */
    bool keepGoing=true;
    string input="";
    Directedgraph userGraph;
    while(keepGoing){
        cin>>input;
        parseUserInput(userGraph,input, keepGoing);
        
    }

}
void parseUserInput(Directedgraph& graphOfUser, string& inputOfUser,bool& keepGoing2){
     /*
    Description: updates graph, operates all commands necessary and signals an exit 
    Arguments: reference of graph, input and boolean for while loop
    Returns: returns nothing
    */
    if (inputOfUser=="Create_C"){
        string courseName="";
        cin>>courseName;
        graphOfUser.adding_Vertex(courseName);
        // adds vertex in the graph
        cout<<"Course created!"<<endl;

    } else if (inputOfUser=="GenerateP"){
        string courseName1="";
        string courseName2="";
        cin>>courseName1>>courseName2;
        graphOfUser.adding_Edge(courseName1,courseName2);
        // adds course1 as prereq to course2 using directed edge; 
        cout<<"Prerequisite relation made"<<endl;
    } else if (inputOfUser=="Quit"){
        keepGoing2=false;

    } else if (inputOfUser=="CheckC"){
        string course="";
        cin>>course;
        if(graphOfUser.isItAVertex(course)){
            cout<<"Yes it exists :)"<<endl;
        } else {
            cout<<"No, it does not exist :("<<endl;
        }

    } else if (inputOfUser=="CheckP"){
        string courseName1="";
        string courseName2="";
        cin>>courseName1>>courseName2;
        if (graphOfUser.isItAnEdge(courseName1,courseName2)){
            cout<<"Yes it exists :)"<<endl;
        } else {
            cout<<"No, it does not exist :("<<endl;
        }

    } else if (inputOfUser=="ViewC"){
        vector<string> courses= graphOfUser.getAllVertices();
        for (long long unsigned int i=0; i<courses.size()-1; i++){
            cout<<courses[i]<<" ";
        }
        cout<<courses[courses.size()-1]<<endl;

    } else if (inputOfUser=="ViewC_AfterPrereq"){
        string prereqcourse="";
        cin>>prereqcourse;
        const vector<string>& courses= graphOfUser.checkCoursesAfterPrereq(prereqcourse);
        string total_courses="";
        for (string course: courses){
            total_courses+= course +" ";
        }
        cout << total_courses ;

    } else if (inputOfUser=="ExactPath?"){
        string inputCourse = ""; 
        vector<string> allegedPath;
        // this is the path user wants to check if it exists
        while (inputCourse!="end"){
            cin>> inputCourse;
            if (inputCourse=="end"){
                continue;
            }
            allegedPath.push_back(inputCourse);
        }
        if (graphOfUser.checkExactPath(allegedPath)){
            cout<<"Success"<<endl;
        } else{
            cout<< "Exact Path does not exist" << endl;
        }

    } else if (inputOfUser=="HowManyCourses"){
        cout<<graphOfUser.size()<<endl;

    } else if (inputOfUser=="CheckForCycle"){
        bool isThereACycle= graphOfUser.checkingForCycle();
        if (isThereACycle){
            cout<<"There is a cycle"<<endl;
        }
        else {
            cout<<"There is not a cycle" <<endl;
        }
    }

}
int main(){
    printingIntro();
    userInput();
    return 0;
}


