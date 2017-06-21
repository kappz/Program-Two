#pragma once
#ifndef DNAMANIP
#define DNAMANIP
/*
Author: Peter O'Donohue
Creation Date: 06/12/17
Modification Date: 06/14/17
Description: This class contains several functions that allow the user to create, compare, and
manipulate DNA strands. In order to gain access to this class, the user must include "dnaManip.H"
in their main program header. The user will then create objects of type "DNA" that will act as 
their DNA strands. 
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
	int find(const DNA & rhs);
	// returns the first position of subStr in self if exists or -1
											//	int find(const DNA& subStr) const;
											// returns the first position subStr in self exists or -1
	DNA reverse() const; // returns a DNA strand reversed
	friend ostream & operator<< (ostream & out, DNA rhs); // prints the strand from begin to end
						// the first position is 0
						// output gattaca print ( 1 , 3 ) is att
	DNA substr(int begin, int width) const;
	//  returns the substr and from begin, returns the next width acids
	bool unitTestPlus();  // tests sum of two DNA strands of equal length
	bool unitTestPlusDiffLengths();  // tests sum of two DNA strands of unequal length
	bool unitTestSubstr();  // tests return a sustring of a strand
	bool unitTestFind();  // tests finding a substring and returning its position

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
	PRE: an object of type DNA has been initialized with
	a parameter containing a string word in the form of a DNA strand
	POST: link list created with new memory space, each node containing a 
	character of string dna, head of list assigned to obect's pointer strand
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
	POST: a deep copy of the original argument has been created and
	stored in memory
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
}


DNA::~DNA()
{
	/*
	PRE: DNA type variable left scope, 
	POST: an object has been deleted from memory
	*/
	Node *deletePtr = this->strand;
	while (deletePtr != nullptr)
	{
		this->strand = strand->next;
		delete deletePtr;
		deletePtr = this->strand;
	}
}


bool DNA::operator==(const DNA& rhs) const
{
	/*
	PRE: rhs and self declared without a default value
	POST: the two strands have been checked for equality
	the function returns with true if the two strands are equal
	and returns false if otherwise.
	*/
	Node *rhsWalker = rhs.strand;
	Node *lhsWalker = this->strand;
	if (length == rhs.length)
	{
		while (lhsWalker->next != nullptr)
		{
			if (lhsWalker->acid == rhsWalker->acid)
			{
				lhsWalker = lhsWalker->next;
				rhsWalker = rhsWalker->next;
			}
			else
				return false;
		}
	}
	return true;
}



DNA DNA::operator=(const DNA& rhs)

{
	/*
	PRE: rhs was declared without a default value
	self was declared with or without a default value
	POST: self contains a copy of the elements of rhs
	any data that self originally pointed to has been deleted
	*/
	Node *newWalker = nullptr;
	Node *rhsWalker = rhs.strand;
	Node *deleteWalker = this->strand;
	Node *deletePtr = deleteWalker;
	this->length = rhs.length;
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
	/*
	PRE: rhs and self objects were declared, at least one of them having length > 0
	POST: the two objects were searched and stored in
	a new object 'result' 
	result is returned to main function
	*/
	DNA result = *this;
	Node *rhsWalker = rhs.strand;
	Node *resultWalker = result.strand;
	if (length != 0 && rhs.length != 0)
	{
		while (resultWalker->next != nullptr)
			resultWalker = resultWalker->next;
		while (rhsWalker != nullptr)
		{
			resultWalker->next = new Node(rhsWalker->acid);
			resultWalker = resultWalker->next;
			rhsWalker = rhsWalker->next;
		}
	}
	return result;
}

ostream& operator<<(ostream & out, DNA rhs)
{
	/*
	PRE: rhs contains strand elements
	ofstream is included in main
	POST: rhs strand elements have been printed on screen
	*/
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
	/*
	PRE: object contains strand elements
	POST: new object created w/copy of strand elements in reverse
	new object returned to main
	*/
	DNA reverseDNA;
	Node *front = nullptr;
	Node *back = nullptr;
	Node *newWalker = this->strand;
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

DNA DNA::substr(int begin, int width) const
{
	/*
	PRE: begin and width fall withing objects length
	POST: object containing substring starting at position of begin
	and ending at position width is returned to main
	*/
	DNA substr;
	Node *walker = nullptr;
	Node *search = this->strand;
	if (begin + width <= length)
	{
		for (int i = 0; i < begin - 1; ++i)
		{
			search = search->next;
		}
		substr.strand = new Node(search->acid);
		search = search->next;
		walker = substr.strand;
		for (int i = 0; i < width - 1; ++i)
		{
			walker->next = new Node(search->acid);
			search = search->next;
			walker = walker->next;
		}
	}
	return substr;
}

int DNA::find(const DNA & rhs)
{
	/*
	PRE: rhs contains more than one strand element
	POST: if subStr is found, function returns position of first character
	returns -1 if Substr is not found
	*/
	int count = 1;
	int position = 0;
	Node *selfWalker = this->strand;
	Node *rhsWalker = rhs.strand;
	Node *tempWalker = nullptr;
	while (selfWalker != nullptr)
	{
		if (selfWalker->acid == rhsWalker->acid)
		{
			position = count;
			tempWalker = selfWalker;
			while (tempWalker->acid == rhsWalker->acid)
			{
				tempWalker = tempWalker->next;
				rhsWalker = rhsWalker->next;
				if (rhsWalker == nullptr)
				{
					return position;
				}
			}			
		}
		else
		{
			position = 0;
			++count;
			selfWalker = selfWalker->next;
			rhsWalker = rhs.strand;
		}
	}
	return -1;
}

bool DNA::unitTestPlus()
{
	DNA c;
	DNA a("ACGT");
	DNA b("CGTA");
	DNA d("ACGTCGTA");
	
	// sum two strings
	c = a + b;
	if (c == d)
	{
		return true;
	}
	else
		return false;
}

bool DNA::unitTestPlusDiffLengths()
{
	DNA a, b;
	DNA c("ACCTAG");
	DNA d("TCGA");
	DNA e("ACCTAGTCGA");
	DNA f("TCGAACCTAG");
	a = c + d;
	b = d + c;
	if (a == e && b == f)
		return true;
	else
		return false;

}

bool DNA::unitTestSubstr()
{
	DNA a = "ACGAAGTCAGGGT";
	DNA b = "GGGT";
	DNA c;
	if (b == a.substr(10, 4))
		return true;
	else
		return false;
	
}

bool DNA::unitTestFind()
{
	int position = 0;
	DNA a("ACGT");
	DNA b("ACTTGACTAGCAACGT");
	position = b.find(a);
	if (position != -1)
		return true;
	else
		return false;
}
#endif