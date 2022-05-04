//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate a linked list using Person Nodes
//03/15/2022

//ScriptReeader.cpp

#include "ScriptReader.h"

ScriptReader::ScriptReader(string file)
{
	in.open(file);
	if (in.is_open())
	{
		cout << "\nScript file open; everything ok!\n";
	}
	else
	{
		cout << "\n\nOops, something is wrong with " << file << "; please try again!";
	}
}

ScriptReader::~ScriptReader()
{
	cout << "\nClosing input file ";
	in.close();

}


int ScriptReader::GetNextInt()
{
	while (!in.eof())
	{
		int c = in.peek();
		if (isdigit(c))
		{
			string line;
			getline(in, line);
			return stoi(line);
		}
		else in.ignore(numeric_limits<streamsize>::max(), in.widen('\n'));
	}
}

string ScriptReader::GetNextString()
{
	while (!in.eof())
	{
		char c = in.peek();
		if (!isdigit(c) && c != '#' && c != ' ')
		{
			string line;
			getline(in, line);
			return line;
		}
		else in.ignore(numeric_limits<streamsize>::max(), in.widen('\n'));
	}
}
