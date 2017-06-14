#pragma once
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
};

class DNA
{
public:
	DNA(string dna); // initalizes the strand to the string
	DNA(const DNA& rhs); // copy constructor
	~DNA(); // destructor
	bool operator==(const DNA& rhs) const;
	//returns true if rhs has the same acids in the same order to self
	DNA operator=(const DNA& rhs);
	// assigns rhs to self (with no memory leak)
	DNA operator+(const DNA& rhs) const; // returns self + rhs
	int find(const DNA& subStr) const;
	// returns the first position subStr in self exists or -1
	DNA reverse() const; // returns a DNA strand reversed
	friend ostream& operator<<(ostream & out, DNA rhs); // prints the strand from begin to end
														// the first position is 0
														// output gattaca.print(1,3) is att
	DNA substr(int begin, int width) const;
	// returns the substr and from begin, returns the next width acids
	int subSeq(const DNA rhs) const;
	// returns location of first acid if self has a subsequence matching rhs, -1 otherwise
	bool unitTestPlus();
	bool unitTestSubstr();
	bool unitTestFind();
private:
	Node *strand;
	Node *head;
	Node *copyHead;
	int length;
};

DNA::DNA(string dna)
{
	/*
	PRE: a string composed of the four DNA bases has been initialized and passed through
	the function
	POST: a link list has been created, with each node containing a single character of
	the string that was passed through.
	*/
	strand = new Node;
	head = strand;
	strand->acid = dna.at(0);
	strand->next = nullptr;
	++length;
	for (int i = 1; 1 < dna.size(); ++i)
	{
		strand->next = new Node;
		strand->acid = dna.at(i);
		strand->next = nullptr;
		++length;
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
	Node *oldWalker = head;
	Node *copyStrand = new Node;
	copyHead = copyStrand;
	copyStrand->acid = oldWalker->acid;
	copyStrand->next = nullptr;
	while (oldWalker->next != nullptr)
	{
		oldWalker = oldWalker->next;
		copyStrand->next = new Node;
		copyStrand->acid = oldWalker->acid;
		copyStrand->next = nullptr;
	}	
}

DNA::~DNA()
{
	/*
	PRE: an operation requiring a delete constructor has been performed
	POST: an object has been deleted from memory
	*/
}

bool DNA::operator==(const DNA& rhs) const
{
	
}