#include "graphDesign.h"
#include <iostream>
using namespace std;
#include <string>
//g++ -o graphUser -std=c++11 graphUser.cpp
void printingIntro();

void printingIntro(){
    cout<< "\n\n\n"<<endl;
    cout<< "\t \t \t \t \t Welcome to the Course Modelling Application \n\n\n"<<endl;
    
    cout<<"Here are the Instructions" <<endl;

    const char * instructions = "This application is designed to allow someone to input courses as vertices of a directed graph and enable prerequisites using edges.\n\n\
To create a course type \"Create course\" and then press enter and then type the course name \n\
To make a course a prerequisite for another course type \"Generate a prerequisite relation\", press enter, type course 1 and then course 2. This means course 1 is required for course 2 \n\
To see if the course exists type \"Check course\" and then press enter and then type the course name\n\
To see if the prerequisite existgit s type \"Check prerequisite\" and then press enter and then type the prereq course and then with a space type the second course\n\
To view all courses type \"View courses\" and then press enter and then you will see each course along with the courses it is a prerequisite to\n\
To know the number of courses that have a specific course as a prerequisite type \"View number of courses after prerequisite\" and then press enter and then the prereuisite course name\n\
To know the total number of courses type \"How many courses in total\" and then press enter and then you will see a number \n";
    printf("%s\n", instructions);
}

int main(){
    printingIntro();
}


