#include "Header.h"
#include <iostream>;
#include <string>

using namespace std;

int main()
{

	DNA a("acgt");
	DNA b("abgt");
	if (a == b)
	{
		cout << "Operator == function called" << endl;
	}
	a = b;
	
	system("pause");
	return 0;
}