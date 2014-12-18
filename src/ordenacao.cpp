#include	"ordenacao.h"

void Ordenacao::bubbleSort(std::vector<int>* entrada)
{
	bubbleSort(entrada,true);
}

void Ordenacao::bubbleSort(std::vector<int>* entrada, bool tipo)
{
	int tamanho = (*(entrada)).size();
	for(int i = 1; i < tamanho; i++)
		for(int j = (tamanho-1); j >= i; j--)
			if(tipo)
			{
				// Ordenacao crescente
				if((*(entrada))[j] < (*(entrada))[j-1])
					trocaPosicoes(entrada,j,(j-1));
			}
			else
			{
				// Ordenacao decrescente
				if((*(entrada))[j] > (*(entrada))[j-1])
					trocaPosicoes(entrada,j,(j-1));
			}
}

void Ordenacao::insertionSort(std::vector<int>* entrada)
{
	insertionSort(entrada,true);
}

void Ordenacao::insertionSort(std::vector<int>* entrada, bool tipo)
{
	int tamanho = (*(entrada)).size();
	int j = 0, temp = 0;
	for(int i = 1; i < tamanho; i++)
	{
		j = i;
		temp = (*(entrada))[i];
		if(tipo)
		{
		// Ordem crescente
			while(j > 0 && (temp < (*(entrada))[j-1]))
			{
				(*(entrada))[j] = (*(entrada))[j-1];
				j--;
			}
		}
		else
		{
		// Ordem decrescente
			while(j > 0 && (temp > (*(entrada))[j-1]))
			{
				(*(entrada))[j] = (*(entrada))[j-1];
				j--;
			}
		}
		(*(entrada))[j] = temp;
	}
}

void Ordenacao::selectionSort(std::vector<int>* entrada)
{
	selectionSort(entrada,true);
}
void Ordenacao::selectionSort(std::vector<int>* entrada, bool tipo)
{
	int tamanho = (*(entrada)).size();
	for(int i = 0; i < tamanho; i++)
	{
		int j = i+1;
		while(j < tamanho)
		{
			if(tipo)
			{
				// Ordem crescente
				if((*(entrada))[i] > (*(entrada))[j])
					trocaPosicoes(entrada, i, j);
			}
			else
			{
				//Ordem decrescente
				if((*(entrada))[i] < (*(entrada))[j])
					trocaPosicoes(entrada, i, j);
			}
			j++;
		}
	}
}

void Ordenacao::shellSort(std::vector<int>* entrada)
{
	shellSort(entrada, true);
}

void Ordenacao::shellSort(std::vector<int>* entrada, bool tipo)
{
	int h = 1, tamanho = (*(entrada)).size(), temp = 0, j = 0;

	for(;h < tamanho;h = ((3*h)+1));
	
	while(h > 0)
	{
		h /= 3;
		for(int i = h; i < tamanho; i++)
		{
			temp = (*(entrada))[i];
			j = i;
			if(tipo)
			{
				while((j-h) >= 0 && (temp < (*(entrada))[j-h]))
				{
					// Ordem crescente
					(*(entrada))[j] = (*(entrada))[j-h];
					j -= h;
				}
			}
			else
			{
				while((j-h) >= 0 && (temp > (*(entrada))[j-h]))
				{
					// Ordem crescente
					(*(entrada))[j] = (*(entrada))[j-h];
					j -= h;
				}
			}
			(*(entrada))[j] = temp;
		}
	}
}

void Ordenacao::quickSort(std::vector<int>* entrada)
{
	quickSort(entrada, true);
}

void Ordenacao::quickSort(std::vector<int>* entrada, bool tipo)
{

}

void Ordenacao::bucketSort(std::vector<int>* entrada)
{

}

void Ordenacao::bucketSort(std::vector<int>* entrada, bool tipo)
{

}

/*
	METODOS PRIVADOS
*/

void Ordenacao::trocaPosicoes(std::vector<int>* entrada, int destino, int fonte)
{
	int temp = (*(entrada))[destino];
	(*(entrada))[destino] = (*(entrada))[fonte];
	(*(entrada))[fonte] = temp;
}

