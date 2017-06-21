#include "dnaManip.h"
#include <iostream>;
#include <string>

using namespace std;
bool unitTest = true;

int main()
{
	int test = 0;
	DNA a("abcdefg");
	DNA b("abcdefg");
	DNA c("opqrstu");
	DNA d("abc");
	DNA e;
	if (unitTest)
	{
		if (d.unitTestPlus())
			cout << "Unit test Plus passed" << endl;
		else
			cout << "Unit test Plus Failed" << endl;
		if (d.unitTestPlusDiffLengths())
			cout << "Unit test plus diff lengths passed" << endl;
		else
			cout << "Unit test Plus diff lengths Failed" << endl;
		if (d.unitTestSubstr())
			cout << "Substr test passed." << endl;
		else
			cout << "Substr test failed." << endl;
		if (d.unitTestFind())
			cout << "Unit test find passed." << endl;
		else
			cout << "Unit test find failed." << endl;

	}
	
	if (a == b)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	system("pause");
	return 0;
}
