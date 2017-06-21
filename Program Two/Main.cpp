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
//	a + (b + c);
//	b = b.reverse();
	a = b.substr(2, 2);
//	a = b + c;
//   cout << b;
	cout << a;
//	cout << a << endl << b << endl << c << endl;
	system("pause");
	return 0;
}
