#ifndef		SRC_INC_APLICACAO_H
#define		SRC_INC_APLICACAO_H

#include	<iostream>
#include	<vector>
#include	<sstream>

#include	"ordenacao.h"

class Aplicacao
{
public:
	Aplicacao();
	virtual ~Aplicacao();

	int run();
private:
	int tamanho;
	std::vector<int> vec;

	int menu(std::string& msg, int limiteInferior, int limiteSuperior);
	void novoTamanho();
	int getTamanho();
	std::string vectorToString(std::vector<int> vec);

	std::vector<int> bubbleSort();
	std::vector<int> insertionSort();
	std::vector<int> selectionSort();
	std::vector<int> shellSort();
	std::vector<int> quickSort();
};

#endif		// SRC_INC_APLICACAO_H

