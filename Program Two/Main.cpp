#include "Header.h"
#include <iostream>;
#include <string>

using namespace std;

int main()
{

	DNA a("zcgt");
	DNA b("cbgk");
	DNA c("CCCC");
	a = b + (a + c);
	cout << a;
	system("pause");
	return 0;
}
