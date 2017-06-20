#pragma once
#define DNAMANIP
/*
Author: Peter O'Donohue
Creation Date: 06/12/17
Modification Date: 06/14/17
Description: DNA manipulation Libary
*/
#include <iostream>
#include <string>
#include <ostream>
using namespace std;
struct Node
{
	char acid;
	Node *next;
	Node(char character = ' ', Node *ptr = nullptr)
	{
		acid = character;
		next = ptr;
	}
};

class DNA
{
public:
	DNA(); // initializes the strand to default
	DNA(string dna); // initalizes the strand to the string
	DNA(const DNA& rhs); // copy constructor
	~DNA(); // destructor
	bool operator==(const DNA& rhs) const;
	//returns true if rhs has the same acids in the same order to self
	DNA operator=(const DNA& rhs);
//	// assigns rhs to self (with no memory leak)
	DNA operator+(const DNA& rhs) const; // returns self + rhs
//	int find(const DNA& subStr) const;
	// returns the first position subStr in self exists or -1
	DNA reverse() const; // returns a DNA strand reversed
	friend ostream& operator<<(ostream & out, DNA rhs); // prints the strand from begin to end
														// the first position is 0
														// output gattaca.print(1,3) is att
//	DNA substr(int begin, int width) const;
	// returns the substr and from begin, returns the next width acids
//	int subSeq(const DNA rhs) const;
	// returns location of first acid if self has a subsequence matching rhs, -1 otherwise
//	bool unitTestPlus();
//	bool unitTestSubstr();
//	bool unitTestFind();
private:
	Node *strand;
	int length;
};

DNA::DNA()
{
	strand = nullptr;
	length = 0;
}

DNA::DNA(string dna)
{
	/*
	PRE: a string composed of the four DNA bases has been initialized and passed through
	the function
	POST: a link list has been created, with each node containing a single character of
	the string that was passed through.
	*/
	Node *walker = nullptr;
	strand = nullptr;
	length = dna.length();
	for (int i = 0; i < length; ++i)
	{
		if (strand == nullptr)
		{
			strand = new Node(dna[i]);
			walker = strand;
		}
		else
		{
			walker->next = new Node(dna[i]);
			walker = walker->next;
		}
	}
}


DNA::DNA(const DNA& rhs)
{
	/*
	PRE: an operation requiring a copy constructor has been performed
	an object of type DNA is passed through by reference
	POST: a deep copy of the original argument has been created and 
	temporarly stored in memory
	*/
	
	
	Node *oldWalker = rhs.strand;
	Node *newWalker = nullptr;
	strand = nullptr;
	while (oldWalker != nullptr)
	{
		if (strand == nullptr)
		{
			strand = new Node(oldWalker->acid);
			newWalker = strand;
		}
		else
		{
			newWalker->next = new Node(oldWalker->acid);
			newWalker = newWalker->next;
		}
		oldWalker = oldWalker->next;
	}
	
	cout << "Copy constructor called." << endl;
}


DNA::~DNA()
{
	/*
	PRE: an operation requiring a delete constructor has been performed
	POST: an object has been deleted from memory
	*/
	
	Node *deletePtr = this->strand;
	while (deletePtr != nullptr)
	{
		this->strand = strand->next;
		delete deletePtr;
		deletePtr = this->strand;
	}
	
	cout << "Destructor called." << endl;
}


bool DNA::operator==(const DNA& rhs) const
{
	/*
	PRE: two objects of type DNA have been created and their
	strands initialized
	POST: the two strands have been checked for equality
	the function returns with true if the two strands are equal
	and returns false if otherwise.
	*/

	Node *rhsWalker = rhs.strand;
	Node *lhsWalker = this->strand;
	if (length != rhs.length)
	{
		cout << "Not equal, strand lengths differ." << endl;
		return false;
	}
	else
		while (lhsWalker->next != nullptr)
		{
			if ( lhsWalker->acid == rhsWalker->acid)
			{
				lhsWalker = lhsWalker->next;
				rhsWalker = rhsWalker->next;
			}
			else
				return false;
		}
	return true;
}



DNA DNA::operator=(const DNA& rhs)

{
	Node *newWalker = nullptr;
	Node *rhsWalker = rhs.strand;
	Node *deleteWalker = this->strand;
	Node *deletePtr = deleteWalker;
	this->strand = new Node(rhsWalker->acid);
	newWalker = this->strand;
	rhsWalker = rhsWalker->next;
	while (deleteWalker != nullptr)
	{
		deleteWalker = deleteWalker->next;
		delete deletePtr;
		deletePtr = deleteWalker;
	}
	while (rhsWalker != nullptr)
	{
		newWalker->next = new Node(rhsWalker->acid);
		newWalker = newWalker->next;
		rhsWalker = rhsWalker->next;
	}
	return *this;
}

DNA DNA::operator+(const DNA& rhs) const
{
	
	DNA result = *this;
	
	Node *rhsWalker = rhs.strand;
	Node *resultWalker = result.strand;
	while (resultWalker->next != nullptr)
		resultWalker = resultWalker->next;
	while (rhsWalker != nullptr)
	{
		resultWalker->next = new Node(rhsWalker->acid);
		resultWalker = resultWalker->next;
		rhsWalker = rhsWalker->next;
	}
	
	return result;
}

 ostream& operator<<(ostream & out, DNA rhs)
{
	Node *walker = rhs.strand;
	while (walker != nullptr)
	{
		out << walker->acid << " ";
		walker = walker->next;
	}
	return out;
}

 DNA DNA::reverse() const
 {
	 DNA reverseDNA = *this;
	 Node *front = nullptr;
	 Node *back = nullptr;
	 Node *newWalker = reverseDNA.strand;
	 Node *deleteWalker = reverseDNA.strand;
	 Node *deletePtr = deleteWalker;
	 reverseDNA.strand = new Node(newWalker->acid);
	 back = reverseDNA.strand;
	 newWalker = newWalker->next;
	 while (newWalker != nullptr)
	 {
		 front = new Node(newWalker->acid);
		 front->next = back;
		 back = front;
		 newWalker = newWalker->next;
	 }
	 reverseDNA.strand = back;
	 return reverseDNA;
 }