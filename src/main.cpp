#include	<iostream>
using std::cout;
using std::cin;
using std::endl;
#include	<vector>
using std::vector;

#include	"ordenacao.h"

int main()
{
// Compativel com c++11
	vector<int> v1 = {7,4,8,1,3,10,2,6,5,9};

	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		cout << *it << " ";
	cout << endl;

	Ordenacao::quickSort(&v1);

	cout << "Vetor ordenado: ";
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}

