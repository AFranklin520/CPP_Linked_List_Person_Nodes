//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate a linked list using Person Nodes
//03/15/2022

//ScriptReeader.h


#ifndef _SCRPT_RDR_H
#define _SCRPT_RDR_H


#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class ScriptReader
{
private:
	ifstream in;


public:

	//only constructor, is passed the name of the file
	ScriptReader(string file);

    //destructor for closing the file stream
	~ScriptReader();

	//returns the next integer value it finds 
	int GetNextInt();
	
	//returns the next valid string 
	string GetNextString();
};


#endif
