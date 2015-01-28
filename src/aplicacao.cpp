#include    "aplicacao.h"

Aplicacao::Aplicacao()
{
    //int num[] = {7,4,8,1,3,10,2,6,5,9};
    //this->tamanho = sizeof(num) / sizeof(int);
    //this->vec = new std::vector<int>(num,num + this->tamanho);
    this->vec = new std::vector<int>();
    this->carregaVetor();
}

Aplicacao::~Aplicacao()
{
    delete this->vec;
    this->vec = NULL;
}

int Aplicacao::run()
{
    bool sair = false;
    int op = -1;
    std::string msgPrincipal = "0 - Sair\n1 - Definir novo vetor\n2 - Bubblesort\n3 - InsertionSort\n\
4 - SelectionSort\n5 - ShellSort\n6 - QuickSort\nOpcao: ";
    std::string msgSecundaria = "1 - Crescente\n2 - Decrescente\nOpcao: ";

    do
    {
        std::vector<int> vecTemp(*this->vec);
        switch(this->menu(msgPrincipal,0,6))
        {
            case 2:
                // Bubblesort
                std::cout << "Escolha o tipo de ordenacao: " << std::endl;
                op = this->menu(msgSecundaria,1,2);
                this->doBubbleSort(op,&vecTemp);
                std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
                break;
            case 3:
                // Insertionsort
                std::cout << "Escolha o tipo de ordenacao: " << std::endl;
                op = this->menu(msgSecundaria,1,2);
                this->doInsertionSort(op,&vecTemp);
                std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
                break;
            case 4:
                // Selectionsort
                std::cout << "Escolha o tipo de ordenacao: " << std::endl;
                op = this->menu(msgSecundaria,1,2);
                this->doSelectionSort(op,&vecTemp);
                std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
                break;
            case 5:
                // Shellsort
                std::cout << "Escolha o tipo de ordenacao: " << std::endl;
                op = this->menu(msgSecundaria,1,2);
                this->doShellSort(op,&vecTemp);
                std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
                break;
            case 6:
                // Quicksort
                std::cout << "Escolha o tipo de ordenacao: " << std::endl;
                op = this->menu(msgSecundaria,1,2);
                this->doQuickSort(op,&vecTemp);
                std::cout << "Vetor ordenado: " << this->vectorToString(vecTemp) << std::endl;
                break;
            case 1:
                // Definir no vetor de dados
                this->novoVetorBase();
                break;
            case 0:
            default:
                sair = true;
                this->salvaVetor();
                break;
        }
    } while(!sair);
    return 0;
}

/*
*   Métodos privados
*/

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

bool Aplicacao::setTamanho(int novoTamanho)
{
    if(novoTamanho <= 0)
    {
        return false;
    }
    this->tamanho = novoTamanho;
    return true;
}

int Aplicacao::getTamanho()
{
    return this->tamanho;
}

std::string Aplicacao::vectorToString(std::vector<int> vec)
{
    std::stringstream buf;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        buf << *it;
        if((it+1) != vec.end())
        {
            buf << " ";
        }
    }

    return buf.str();
}

void Aplicacao::carregaVetor()
{
    std::ifstream streamEntrada("vec.txt",std::ifstream::in);
    std::string* s = NULL;
    int pos = 0;
    int* valor = NULL;
    std::stringstream* buf;

    if(streamEntrada.is_open())
    {
        s = new std::string();
        // TODO: nao é feito nenhum tipo de validação do arquivo
        std::getline(streamEntrada,*s);
        streamEntrada.close();
        while(!s->empty())
        {
            pos = s->find(' ');
            if(pos < 0)
            {
                // Ultimo numero na linha
                pos = s->size();
            }
            buf = new std::stringstream();
            buf->str(s->substr(0,pos));
            s->erase(0,pos+1);
            valor = new int;
            *buf >> *valor;
            this->vec->push_back(*valor);
            delete buf;
            delete valor;
        }
    }
    else
    {
        std::cout << "Nao foi possivel abrir a base de dados!" << std::endl;
        int num[] = {7,4,8,1,3,10,2,6,5,9};
        this->vec->assign(num,num+10);
    }
}

void Aplicacao::salvaVetor()
{
    std::ofstream streamSaida("vec.txt", std::ofstream::out);

    if(streamSaida.is_open())
    {
        std::string v = this->vectorToString(*this->vec);
        std::cout << "Salvando a base de dados..." << std::endl;
        streamSaida << v.c_str();
        streamSaida.close();
    }
    else
    {
        std::cout << "Nao possivel o salvar a base de dados!" << std::endl;
    }
}

void Aplicacao::novoVetorBase()
{
    int novoTamanho = 0;
    bool ehValido = false;

    std::cout << "Digite o novo tamanho do vetor base: ";
    do
    {
        std::cin >> novoTamanho;
        ehValido = this->setTamanho(novoTamanho);
        if(!ehValido)
        {
            std::cout << "Tamanho invalido! Digite novamente: ";
        }
    } while(!ehValido);

    int* vetorTmp = new int[novoTamanho];
    for(int it = 0; it<novoTamanho;it++)
    {
        std::cout << "Digite o elemento " << it << " do novo Vetor: ";
        std::cin >> vetorTmp[it];
    }

    delete this->vec;
    this->tamanho = novoTamanho;
    this->vec = new std::vector<int>(vetorTmp,vetorTmp + this->tamanho);
    std::cout << "valores digitados: ";
    for(std::vector<int>::iterator i = this->vec->begin(); i<this->vec->end();i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void Aplicacao::doBubbleSort(int opcao, std::vector<int>* v)
{
    if(opcao == 1)
    {
        Ordenacao::bubbleSort(v,true);
    }
    else
    {
        Ordenacao::bubbleSort(v,false);
    }
}

void Aplicacao::doInsertionSort(int opcao, std::vector<int>* v)
{
    if(opcao == 1)
    {
        Ordenacao::insertionSort(v,true);
    }
    else
    {
        Ordenacao::insertionSort(v,false);
    }
}

void Aplicacao::doSelectionSort(int opcao, std::vector<int>* v)
{
    if(opcao == 1)
    {
        Ordenacao::selectionSort(v,true);
    }
    else
    {
        Ordenacao::selectionSort(v,false);
    }
}

void Aplicacao::doShellSort(int opcao, std::vector<int>* v)
{
    if(opcao == 1)
    {
        Ordenacao::shellSort(v,true);
    }
    else
    {
        Ordenacao::shellSort(v,false);
    }
}

void Aplicacao::doQuickSort(int opcao, std::vector<int>* v)
{
    if(opcao == 1)
    {
        Ordenacao::quickSort(v,true);
    }
    else
    {
        Ordenacao::quickSort(v,false);
    }
}

