#include "Header.h"
#include <iostream>;
#include <string>

using namespace std;

int main()
{

	DNA a("zcgt");
	DNA b("cbgk");
	DNA c("CCCC");
//	cout << a << endl << b << endl << c << endl;
	a = a + (b + c);
//	b = c;
	
	cout << a;
//	cout << a << endl << b << endl << c << endl;

	system("pause");
	return 0;
}
