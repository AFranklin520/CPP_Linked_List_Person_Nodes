//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate a linked list using Person Nodes
//03/15/2022

//ListMgr.cpp


#include "ListMgr.h"

//ListMgr::ListMgr(): first{nullptr}, last{nullptr}
//{
//
//}

void ListMgr::Push_front(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);
	if (count == 0)
	{
		first = np;
		last = np;
	}
	else
	{
		np->SetNext(first); //NP's next is the current first
		first->SetPrev(np); //Current first's previous is now NP
		first = np; //First now points at NP's location
		first->SetPrev(nullptr);
	}
	count++;
}


void ListMgr::Push_back(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);
	if (count == 0)
	{
		first = np;
		last = np;
	}
	else
	{
		PersonNode* temp = last;
		np->SetPrev(temp);
		temp->SetNext(np);
		last = np;
		last->SetNext(nullptr);
	}
	++count;
}

void ListMgr::Pop_front()
{
	if (Empty()) return;
	PersonNode* np = first->GetNext();
	delete first;
	if(count == 1 )
	{
		count = 0;
		return;
	}
	first = np;
	first->SetPrev(nullptr);
	--count;
}

void ListMgr::Pop_back()
{
	if (Empty()) return;
	PersonNode* np = last;
	np = last->GetPrev();
	delete last;
	if (count == 1)
	{
		count = 0;
		return;
	}
	last = np;
	last->SetNext(nullptr);
	--count;
}

Person* ListMgr::Front()
{ 
	//if (Empty()) return 0;
	return first->GetPerson();
}

Person* ListMgr::Back()
{
	//if (count == 0) return 0;
	return last->GetPerson();
}

void ListMgr::Remove(string n)
{
	transform(n.begin(), n.end(), n.begin(), ::toupper); //Need to match the case the names come in.
	PersonNode* np = first;
	if (count == 0) return;
	for (int i{ 0 }; i < count; i++)
	{
		if (np->GetPerson()->GetName().find(n) != string::npos)
		{
			if (i == 0)
			{
				Pop_front();
				i--; //Count will not advance if first item was removed.
			}
			else if (i == count - 1)
			{
				Pop_back();
			}
			else
			{
				PersonNode* before = np->GetPrev();
				PersonNode* after = np->GetNext();
				before->SetNext(after);
				after->SetPrev(before);
				delete np;
				np = after;
				--i; //Item at this position was deleted, so we need to check the current item at this position.
				--count;
			}
		}
		else
		{
			np = np->GetNext();
		}
	}
}

void ListMgr::Erase(int pos)
{
	if (pos > count || pos < 1 || Empty()) return;
	PersonNode* np = first;

	for (int i{ 0 }; i < count; i++)
	{
		if (i == pos - 1)
		{
			
			if (i == 0)
			{
				Pop_front();
			}
			else if (i == count - 1)
			{
				Pop_back();
			}
			else
			{
				PersonNode* before = np->GetPrev();
				PersonNode* after = np->GetNext();
				before->SetNext(after);
				after->SetPrev(before);
				delete np;
				--count;
			}
			break;
		}
		else
		{
			np = np->GetNext();
		}
	}
}

void ListMgr::Clear()
{
	
	if (Empty()) return;
	while (count != 0)
	{
		Pop_front();
	}
}

void ListMgr::Show()
{
	int entries{ 0 };
	PersonNode* np = first;
	if (count == 0)
	{
		cout << "\nThis list is empty!";
		return;
	}
	cout << "\nNumber of persons in the link list: " << to_string(count) + "\n";
	while (np -> GetNext() != nullptr)
	{
		cout << np->GetPerson()->GetName() << " --> ";
		np = np->GetNext();
		entries++;
		if (entries == 4)
		{
			cout << "\n";
			entries = 0;
		}
	}
	cout << np->GetPerson()->GetName();
}

string ListMgr::ShowString()
{
	int entries{ 0 };
	string output;
	if (!(count >= 0))
	{
		output = "\nThis list doesn't exist anymore, if, in fact, it ever did!";
		return output;
	}
	if (Empty())
	{
		output = "\nThis list is already empty, unable to clear it!";
		return output;
	}
	output += "\nNumber of persons in the link list: " + to_string(count) + "\n";
	PersonNode* np = first;
	while (np->GetNext() != nullptr)
	{
		output += np->GetPerson()->GetName() + " --> ";
		np = np->GetNext();
		entries++;
		if (entries == 4)
		{
			output += "\n";
			entries = 0;
		}
	}
	output +=  np->GetPerson()->GetName();
	return output;
}

ListMgr::~ListMgr()
{
	cout << "\nThe list is now out of scope and will begin destructors: \n";
	if (Empty())
	{
		return;
	}
	PersonNode* np = first;
	while (np->GetNext() != nullptr)
	{
		if (count == 1)
		{
			delete first;
			count = 0;
			break;
		}
		else
		{
			np = np->GetNext();
			delete first;
			first = np;
			first->SetPrev(nullptr);
		}
		--count;
	}
	delete last;
	count = 0;
}
