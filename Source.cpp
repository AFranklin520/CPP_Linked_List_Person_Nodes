//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate a linked list using Person Nodes
//03/15/2022

//Source.cpp

#include "ListMgr.h"
#include "ScriptReader.h"
#include "FranklinPersonGen/PersonGen.h"

using namespace std;

int main()
{
	ListMgr* lm = new ListMgr;
	PersonGen* pg = new PersonGen;
	ScriptReader* sr = new ScriptReader("P5TestScript.txt");
	cout << "\n\nAnthony Franklin\nafranklin18@cnm.edu\nProgram to demonstrate a linked list using Person Nodes\n\n";
	string logName;
	cout << "\n\nPlease enter the name of the log file you would like to create (eg. \'log\' for log.txt): " << endl;
	getline(cin, logName);

	////Replacing Illegal Filename chars in input
	string illegalChars = "*\\/:?\"<>|";
	string::iterator it;
	for (it = logName.begin(); it < logName.end(); ++it) {
		bool found = illegalChars.find(*it) != string::npos;
		if (found) {
			*it = '_';
		}
	}
	logName += ".txt";
	ofstream outputFile;
	outputFile.open(logName);
	if (pg->UseFile("P5LinkedListPeopleNov6.txt"))
	{
		Date today;
		outputFile << today.GetFormattedDate() << "\nAnthony Franklin\nafranklin18@cnm.edu\nProgram to emulate a linked list using Person Nodes\n\n";;
		outputFile << lm->ShowString();
		cout << lm->ShowString();
		int options[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
		string menu = "\n1. Show List\n2. Add Person to Front of List\n3. Add Person to Back of List\n4. Remove Person from Front of List\n5. Remove Person from Back of List\n6. Remove Persons with Selected Substring in their Name";
		menu += "\n7. First Person in the List\n8. Last Person in the List\n9. Delete Person at Index Position\n10. Clear the List\n11. Size of List\n12. Exit Program";




		int scriptInput{ 0 };
		while (scriptInput != 12)
		{
			string subS;
			int erase;
			scriptInput = sr->GetNextInt();
			Person* p;
			switch (scriptInput)
			{
			case 1:
				lm->Show();
				outputFile << lm->ShowString() << "\n";

				continue;
			case 2:
				outputFile << "\nAdding new person to the front of the list: \n";
				p = pg->GetNewPerson();
				lm->Push_back(p);
				outputFile << lm->ShowString() << "\n";
				continue;
			case 3:
				outputFile << "\nAdding new person to the end of the list: \n";
				p = pg->GetNewPerson();
				lm->Push_back(p);
				outputFile << lm->ShowString() << "\n";
				continue;
			case 4:
				outputFile << "\nTrying to remove first person from the list: \n";
				lm->Pop_front();
				outputFile << lm->ShowString() << "\n";
				continue;
			case 5:
				outputFile << "\nTrying to remove last person from the list: \n";
				lm->Pop_back();
				outputFile << lm->ShowString() << "\n";
				continue;
			case 6:
				subS = sr->GetNextString();
				outputFile << "\nTrying to remove names containing the following from the list: " << subS << "\n";
				lm->Remove(subS);
				outputFile << lm->ShowString() << "\n";
				continue;
			case 7:
				if (lm->Front())
				{
					outputFile << "\nThe first person in the list is: " << lm->Front()->GetName() << "\n";
					continue;
				}
				else
				{
					outputFile << "\n\nThe list is empty, unable to retrieve first person!\n";
					continue;
				}

			case 8:
				if (lm->Back())
				{
					outputFile << "\nThe last person in the list is: " << lm->Back()->GetName() << "\n";;
					continue;
				}
				else
				{
					outputFile << "\n\nThe list is empty, unable to retrieve last person!\n";
					continue;
				}
			case 9:
				erase = sr->GetNextInt();
				outputFile << "\n\nDeleting person at index position: " << to_string(erase) << "\n";
				lm->Erase(erase);
				outputFile << "\n" << lm->ShowString() << "\n";
				continue;
			case 10:
				outputFile << "\nClearing the list now: \n";
				lm->Clear();
				outputFile << lm->ShowString() << "\n";
				continue;
			case 11:
				cout << "\nThe size of the list: " << to_string(lm->Size()) << "\n";
				outputFile << "\nThe size of the list: " << to_string(lm->Size()) << "\n";
				continue;
			}
		}

		outputFile << "\n\nExiting Program Now! \n\n";
		delete sr;
		delete lm;
		delete pg;
		cout << "\n\nClosing output file" << logName;
		outputFile.close();

	}
	
	cout << "\n\nThank you for using my program goodbye!\n\n";


	return 0;
}