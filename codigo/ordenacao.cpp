#include "ordenacao.hpp"
#include <algorithm>

using namespace std;

/* SELECTION SORT ele procura pelo menor valor e o coloca na primeira posição disponível.
   Ou seja, no primeiro laço, percorre as posições do vetor(ele é o responsavel por controla qual posição será preenchida com o menor valor encontrado)  - vamos de i < n-1, pois assuminos que o ultimo elemento que sobra já está ordenado
   No segundo laço, percorre a lista a partir de i+1 até o fim da lista procurando um valor menor que o menor atual, se encontrar, atualiza o índice do menor elemento encontrado e continua a busca até o fim da lista.
   Ao terminar o segundo laço, realizamos a troca do menor valor encontrado com o valor na posição i.
*/
void selectionSort(vector<int> &v, Metrica &m)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++) // Percorre a lista da pos 0 ate n-1, pois assumimos que o ultimo elemento que sobra já ta ordenado
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            m.comparacoes++; // soma a comparação para metrica
            if (v[j] < v[menor])
                menor = j; // se encontrar um menor que o menor, atualiza o menor
        }
        swap(v[i], v[menor]); // troca os valores da pos i com o da pos do menor encontrado
        m.trocas++;           // soma a troca para metrica
    }
}

/* INSERTION SORT cria uma espécie de subvetor ordenado. Conforme percorre o vetor,
   vai inserindo cada elemento na posição apropriada dentro desse subvetor já ordenado.

   O primeiro laço percorre o vetor inteiro, começando do segundo elemento.
   O segundo laço desloca (empurra) os elementos maiores para a direita,
   abrindo espaço para inserir o elemento atual na posição correta.
   Esse laço interno só para quando encontrar um elemento menor ou igual ao atual,
   ou quando chegar no início do vetor.
*/

void insertionSort(vector<int> &v, Metrica &m)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int k = v[i];  // k é valor atual da posição
        int j = i - 1; // j começa com a posição anterior a da atual para começar a comparação

        while (j >= 0) // roda até e a primeira posição
        {
            m.comparacoes++; // adiciona a comparação para metrica
            if (v[j] > k)    // verifica que o valor atual é menor que o da posição j
            {
                v[j + 1] = v[j]; // se for menor o valor da posição vai para frente, abrindo espaço
                m.trocas++;      // adiciona troca para metrica
                j--;
            }
            else // se o k for maior que o elemento, eu paro pois encontrei a posição de k
                break;
        }
        v[j + 1] = k; // adiciono k sua nova posição
    }
}
/* BUBBLESORT  compara elementos ao lados e troca-os se estiverem na ordem errada.
    Os maiores elementos vão para o final do vetor.

    O primeiro laço percorre da posição inicial até o penúltimo elemento,
   pois ao final de cada iteração assumimos que o último elemento está na posição correta.
   O segundo laço percorre de 0 até n - i - 1. O "-i" garante que o final do vetor(já ordenado), não seja mais tocada conforme vai chegando o fim do laço.
   Em cada comparação, ele verifica se o elemento atual (v[j]) é maior que o próximo (v[j+1]).
   Se for, troca os dois, empurrando o maior para o final do vetor.
*/
void bubbleSort(vector<int> &v, Metrica &m)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) // percorre até as posições ainda não ordenadas
        {
            m.comparacoes++;     // add comparação para metrica
            if (v[j] > v[j + 1]) // verifica se o da frente é menor
            {
                swap(v[j], v[j + 1]); // se for eles trocam de lugar, e o maior vai pra frente
                m.trocas++;           // adiciona troca para metrica
            }
        }
    }
}
/* BUBBLE SORT OTIMIZADO funciona como o Bubble normal, porém inclui uma verificação, que monitora se houve alguma troca durante a passada completa do laço interno.
   Se em uma iteração não ocorrer nenhuma troca, significa que o vetor já está ordenado. Então ele interrompe o laço e finaliza
*/
void bubbleSortOtimizado(vector<int> &v, Metrica &m)
{
    int n = v.size();
    bool trocou;
    for (int i = 0; i < n - 1; i++)
    {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            m.comparacoes++;
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                m.trocas++;
                trocou = true;
            }
        }
        if (!trocou) // verificação da troca
            break;
    }
}
