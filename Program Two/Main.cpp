#include "Header.h"
#include <iostream>;
#include <string>

using namespace std;

int main()
{

	DNA a("zcgt");
	DNA b("cbgt");
	DNA c("CCCC");
	cout << a + b;
	
	cout << c << endl;
	system("pause");
	return 0;
}
