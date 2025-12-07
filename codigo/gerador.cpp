#include "gerador.hpp"
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <iostream>

#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

void salvaArquivo(const vector<int> &v, const string &nome)
{
    ofstream out(nome, ios::binary);
    int n = v.size();

    out.write((char *)&n, sizeof(int));
    out.write((char *)v.data(), n * sizeof(int));
}

vector<int> gerarCrescente(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    return v;
}

vector<int> gerarDecrescente(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    return v;
}

vector<int> gerarAleatorio(int n)
{
    vector<int> v(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, n * 10);

    for (int i = 0; i < n; i++)
        v[i] = dist(gen);

    return v;
}

void gerarTodosOsDados()
{
    vector<int> tamanhos = {1000, 10000, 100000};
    vector<string> nomes = {"pequeno", "medio", "grande"};
    fs::create_directories("../dados");
    cout << "Gerando arquivos...\n";

    for (int i = 0; i < tamanhos.size(); i++)
    {
        int N = tamanhos[i];

        salvaArquivo(gerarAleatorio(N), "../dados/" + nomes[i] + "_aleatorio.bin");
        salvaArquivo(gerarCrescente(N), "../dados/" + nomes[i] + "_crescente.bin");
        salvaArquivo(gerarDecrescente(N), "../dados/" + nomes[i] + "_decrescente.bin");
    }
}
