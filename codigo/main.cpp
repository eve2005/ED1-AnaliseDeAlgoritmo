#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "ordenacao.hpp"
#include "busca.hpp"
#include "gerador.hpp"
#include "metrica.hpp"

using namespace std;

vector<int> lerArquivoBinario(const string &nome)
{
     ifstream in(nome, ios::binary);
     if (!in)
     {
          cerr << "Erro ao abrir arquivo: " << nome << endl;
          return {};
     }

     int n = 0;
     in.read((char *)&n, sizeof(int));

     vector<int> v(n);
     in.read((char *)v.data(), n * sizeof(int));

     return v;
}

int main()
{
     // gerando os arquivos
     // gerarTodosOsDados(); // COMENTADO PARA OS ARQUIVOS ESTAREM COM MESMOS DADOS DO USADO NO RELATORIO
     vector<string> tamanhos = {"pequeno", "medio", "grande"};
     vector<string> cenarios = {"aleatorio", "crescente", "decrescente"};

     cout << "\n==== INICIANDO EXPERIMENTOS ====\n";

     for (auto &T : tamanhos)
     {
          for (auto &C : cenarios)
          {
               string nome = "../dados/" + T + "_" + C + ".bin"; // Monta o nome do arquivo para leitura
               cout << "\n\n----------------------------------------------------------------------------\n";
               cout << "Arquivo: " << nome << endl;

               vector<int> base = lerArquivoBinario(nome); // le o arquivo e recupera o vetor gerado
               if (base.empty())
               {
                    cout << "Erro ao ler arquivo!\n";
                    continue;
               }

               vector<int> v;
               Metrica m;

               // SELECTION SORT
               v = base;
               m = Metrica();

               auto start = chrono::high_resolution_clock::now(); // inicia  a contagem
               selectionSort(v, m);
               auto end = chrono::high_resolution_clock::now(); // termina a contagem

               m.tempo_ms = chrono::duration<double, milli>(end - start).count(); // "anota" o tempo

               cout << "--Selection Sort--"
                    << "\n\tcomparacoes: " << m.comparacoes
                    << "\n\ttrocas: " << m.trocas
                    << "\n\tTempo: " << m.tempo_ms << " ms\n";

               // INSERTION SORT
               v = base; // recupera o vetor inicial
               m = Metrica();

               start = chrono::high_resolution_clock::now(); // inicia  a contagem
               insertionSort(v, m);
               end = chrono::high_resolution_clock::now(); // termina a contagem

               m.tempo_ms = chrono::duration<double, milli>(end - start).count(); // "anota" o tempo

               cout << "--Insertion Sort-- "
                    << "\n\tcomparacoes: " << m.comparacoes
                    << "\n\ttrocas: " << m.trocas
                    << "\n\tTempo: " << m.tempo_ms << " ms\n";

               // BUBBLE SORT

               v = base;
               m = Metrica();

               start = chrono::high_resolution_clock::now();
               bubbleSort(v, m);
               end = chrono::high_resolution_clock::now();

               m.tempo_ms = chrono::duration<double, milli>(end - start).count();

               cout << "--Bubble Sort-- "
                    << "\n\tcomparacoes: " << m.comparacoes
                    << "\n\ttrocas: " << m.trocas
                    << "\n\tTempo: " << m.tempo_ms << " ms\n";

               // BUBBLE SORT OTIMIZADO

               v = base;
               m = Metrica();

               start = chrono::high_resolution_clock::now();
               bubbleSortOtimizado(v, m);
               end = chrono::high_resolution_clock::now();

               m.tempo_ms = chrono::duration<double, milli>(end - start).count();

               cout << "--Bubble Sort Otimizado-- "
                    << "\n\tcomparacoes: " << m.comparacoes
                    << "\n\ttrocas: " << m.trocas
                    << "\n\tTempo: " << m.tempo_ms << " ms\n";

               //////////////////////BUSCA
               if (T == "grande")
               {

                    cout << "\n-- Testes de Busca (vetor GRANDE, cenario: " << C << ") --\n";

                    vector<int> sorted = base;
                    sort(sorted.begin(), sorted.end());

                    int valorExistente = sorted[sorted.size() / 2];
                    int valorInexistente = -1;
                    bool encontrou;

                    // Busca Sequencial - vaolr existente
                    m = Metrica();
                    start = chrono::high_resolution_clock::now();
                    encontrou = buscaSequencial(base, valorExistente, m);
                    end = chrono::high_resolution_clock::now();
                    m.tempo_ms = chrono::duration<double, milli>(end - start).count();

                    cout << "Busca Sequencial (existente = " << valorExistente << "): "
                         << (encontrou ? "Encontrado" : "Nao encontrado")
                         << "\n\tcomparacoes: " << m.comparacoes
                         << "\n\tTempo: " << m.tempo_ms << " ms\n";

                    //  Busca Sequencial - valor inexistente
                    m = Metrica();
                    start = chrono::high_resolution_clock::now();
                    encontrou = buscaSequencial(base, valorInexistente, m);
                    end = chrono::high_resolution_clock::now();
                    m.tempo_ms = chrono::duration<double, milli>(end - start).count();

                    cout << "Busca Sequencial (inexistente = " << valorInexistente << "): "
                         << (encontrou ? "Encontrado" : "Nao encontrado")
                         << "\n\tcomparacoes: " << m.comparacoes
                         << "\n\tTempo: " << m.tempo_ms << " ms\n";

                    // Busca Binaria - chave existente
                    m = Metrica();
                    start = chrono::high_resolution_clock::now();
                    encontrou = buscaBinaria(sorted, valorExistente, m);
                    end = chrono::high_resolution_clock::now();
                    m.tempo_ms = chrono::duration<double, milli>(end - start).count();

                    cout << "Busca Binaria (existente = " << valorExistente << "): "
                         << (encontrou ? "Encontrado" : "Nao encontrado")
                         << "\n\tcomparacoes: " << m.comparacoes
                         << "\n\tTempo: " << m.tempo_ms << " ms\n";

                    //   Busca Binaria - chave inexistente
                    m = Metrica();
                    start = chrono::high_resolution_clock::now();
                    encontrou = buscaBinaria(sorted, valorInexistente, m);
                    end = chrono::high_resolution_clock::now();
                    m.tempo_ms = chrono::duration<double, milli>(end - start).count();

                    cout << "Busca Binaria (inexistente = " << valorInexistente << "): "
                         << (encontrou ? "Encontrado" : "Nao encontrado")
                         << "\n\tcomparacoes: " << m.comparacoes
                         << "\n\tTempo: " << m.tempo_ms << " ms\n";
               }
          }
     }

     cout << "\n==== FIM DOS EXPERIMENTOS ====\n";
     return 0;
}
