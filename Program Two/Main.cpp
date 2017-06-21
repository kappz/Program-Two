#include "Header.h"
#include <iostream>;
#include <string>

using namespace std;

int main()
{
	DNA a("abcdefg");
	DNA b("hijklmn");
	DNA c("opqrstu");
	DNA d("cat");
	DNA e("favorite animal is dog and ca");
	int position;
//	cout << a << endl << b << endl << c << endl;
//	a + (b + c);
//	b = b.reverse();
//	a = b.substr(2, 4);
//	a = b + c;
//   cout << b;
//	cout << a;
//	cout << a << endl << b << endl << c << endl;
	position = e.find(d);
	cout << position << endl;
	system("pause");
	return 0;
}
