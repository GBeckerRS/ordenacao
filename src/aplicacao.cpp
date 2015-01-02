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
	bool sair = false;
	int op = -1;
	std::string msgPrincipal = "0 - Sair\n1 - Bubblesort\n2 - InsertionSort\n3 - SelectionSort\n\
4 - ShellSort\n5 - QuickSort\nOpcao: ";
	std::string msgSecundaria = "1 - Crescente\n2 - Decrescente\nOpcao: ";

	do
	{
		std::vector<int> vecTemp(this->vec);
		switch(this->menu(msgPrincipal,0,5))
		{
			case 1:
				// Bubblesort
				std::cout << "Escolha o tipo de ordenacao: " << std::endl;
				op = this->menu(msgSecundaria,1,2);
				if(op == 1)
				{
					Ordenacao::bubbleSort(&vecTemp,true);
					std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
				}
				else
				{
					Ordenacao::bubbleSort(&this->vec,false);
				}
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
			case 0:
			default:
				sair = true;
				break;
		}
	} while(!sair);
	return 0;
}

int Aplicacao::menu(std::string& msg, int limiteInferior, int limiteSuperior)
{
	int opcao = -1;
	std::stringstream buf;
	buf.str(msg);

	std::cout << "Escolha uma opcao: " << std::endl << buf.str();
	do
	{
		std::cin >> opcao;
		if(opcao < limiteInferior || opcao > limiteSuperior)
		{
			std::cout << "Opcao invalida. Digite novamente!" << std::endl;
			std::cout << buf.str();
		}
	} while(opcao < limiteInferior || opcao > limiteSuperior);

	return opcao;
}

std::string Aplicacao::vectorToString(std::vector<int> vec)
{
	std::stringstream buf;

	for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		buf.str("1");
		if(it != vec.end())
		{
			buf.str(", ");
		}
	}

	return buf.str();
}

