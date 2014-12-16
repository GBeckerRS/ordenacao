#ifndef		ORDENACAO_H
#define		ORDENACAO_H

#include	<vector>

class Ordenacao
{
public:
	static void bubbleSort(std::vector<int>* entrada);
	static void bubbleSort(std::vector<int>* entrada, bool tipo);

	static void insertionSort(std::vector<int>* entrada);
	static void insertionSort(std::vector<int>* entrada, bool tipo);

	static void selectionSort(std::vector<int>* entrada);
	static void selectionSort(std::vector<int>* entrada, bool tipo);

	static void shellSort(std::vector<int>* entrada);
	static void shellSort(std::vector<int>* entrada, bool tipo);
private:
	static void trocaPosicoes(std::vector<int>* entrada, int destino, int fonte);
};

#endif		// ORDENACAO_H

