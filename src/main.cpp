#include	<iostream>
using std::cout;
using std::cin;
using std::endl;
#include	<vector>
using std::vector;

#include	"aplicacao.h"
#include	"ordenacao.h"

int main()
{
// Compativel com c++11
	vector<int> v1 = {7,4,8,1,3,10,2,6,5,99,45,32,67,51,85,46,25,17,33};

	for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	Aplicacao app;
	int op = app.run();
	cout << "OP: " << op << endl;

	return 0;
}

