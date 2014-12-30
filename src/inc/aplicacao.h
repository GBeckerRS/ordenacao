#ifndef		SRC_INC_APLICACAO_H
#define		SRC_INC_APLICACAO_H

#include	<iostream>
#include	<vector>
#include	<sstream>

class Aplicacao
{
public:
	Aplicacao();
	virtual ~Aplicacao();

	int run();
private:
	int tamanho;
	std::vector<int> vec;

	int menu();
	void novoTamanho();
	int getTamanho();

	std::vector<int> bubbleSort();
	std::vector<int> insertionSort();
	std::vector<int> selectionSort();
	std::vector<int> shellSort();
	std::vector<int> quickSort();
};

#endif		// SRC_INC_APLICACAO_H

