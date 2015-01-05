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
	Aplicacao app;
	int op = app.run();
	cout << "OP: " << op << endl;

	return 0;
}

