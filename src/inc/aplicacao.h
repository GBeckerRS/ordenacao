#ifndef     SRC_INC_APLICACAO_H
#define     SRC_INC_APLICACAO_H

#include    <iostream>
#include    <vector>
#include    <sstream>
#include    <fstream>

#include    "ordenacao.h"

class Aplicacao
{
public:
    Aplicacao();
    virtual ~Aplicacao();

    int run();
private:
    int tamanho;
    std::vector<int>* vec;

    int menu(std::string& msg, int limiteInferior, int limiteSuperior);
    bool setTamanho(int novoTamanho);
    int getTamanho();
    std::string vectorToString(std::vector<int> vec);

    void carregaVetor();
    void salvaVetor();

    void novoVetorBase();

    void doBubbleSort(int opcao, std::vector<int>* v);
    void doInsertionSort(int opcao, std::vector<int>* v);
    void doSelectionSort(int opcao, std::vector<int>* v);
    void doShellSort(int opcao, std::vector<int>* v);
    void doQuickSort(int opcao, std::vector<int>* v);
};

#endif		// SRC_INC_APLICACAO_H

