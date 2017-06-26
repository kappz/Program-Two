#include "dnaManip.h"
#include <iostream>;
#include <string>

using namespace std;
bool unitTest = true;

int main()
{
	int test = 0;
	DNA a("abcdefg");
	DNA b("abcdefgh");
	DNA c("opqrstu");
	DNA d("abc");
	DNA e;
	DNA q("efg");
	if (unitTest)
	{
		if (d.unitTestPlus())
			cout << "Unit test Plus passed" << endl;
		else
			cout << "Unit test Plus Failed" << endl;
		if (d.unitTestSubstr())
			cout << "Unit test Substr test passed." << endl;
		else
			cout << "Unit |Test substr test failed." << endl;
		if (d.unitTestFind())
			cout << "Unit test find passed." << endl;
		else
			cout << "Unit test find failed." << endl;
		if (d.unitTestReverse())
			cout << "Unit test reverse passed." << endl;
		else
			cout << "Unit test reverse failed." << endl;

	}
	
	system("pause");
	return 0;
}
