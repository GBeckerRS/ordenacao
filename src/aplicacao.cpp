#include	"aplicacao.h"

Aplicacao::Aplicacao()
{
	// Tamanho padrao
	this->tamanho = 10;
	this->vec = {7,4,8,1,3,10,2,6,5,9};
}

Aplicacao::~Aplicacao()
{
}

int Aplicacao::run()
{
	switch(this->menu())
	{
		case 0:
		default:
			// Sair
			return 0;
			break;
		case 1:
			// Bubblesort
			break;
		case 2:
			// Insertionsort
			break;
		case 3:
			// Selectionsort
			break;
		case 4:
			// Shellsort
			break;
		case 5:
			// Quicksort
			break;
	}
	return 0;
}

int Aplicacao::menu()
{
	int opcao = -1;
	std::stringstream buf;
	buf.str("0 - Sair\n1 - Bubblesort\n2 - InsertionSort\n3 - SelectionSort\n\
4 - ShellSort\n5 - QuickSort\nOpcao: ");

	std::cout << "Escolha uma opcao: " << std::endl << buf.str();
	do
	{
		std::cin >> opcao;
		if(opcao < 0 || opcao > 5)
		{
			std::cout << "Opcao invalida. Digite novamente!" << std::endl;
			std::cout << buf.str();
		}
	} while(opcao < 0 || opcao > 5);

	return opcao;
}

