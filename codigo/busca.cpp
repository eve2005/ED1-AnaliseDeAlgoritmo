#include "busca.hpp"

using namespace std;

/* BUSCA Sequencial ele percorre o vetor do inicio ao fim procurando pelo valor. Se ele encontra ele para o laço e retorna true
    Se ele chegou ao fim do laço e não encontrou retorna true
 */
bool buscaSequencial(const vector<int> &v, int x, Metrica &m)
{
    for (int a : v)
    {
        m.comparacoes++;
        if (a == x)
            return true;
    }
    return false;
}
/* BUSCA BINARIA ela divide o vetor repetidamente ao meio para reduzir drasticamente o número de comparações
SO FUNCIONA EM VETOR ORDENADO*/
bool buscaBinaria(const vector<int> &v, int x, Metrica &m)
{
    int l = 0;
    int r = v.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2; // calcula o meio
        m.comparacoes++;

        if (v[mid] == x) // e o valor do meio for igual x achou interrompe o laço
            return true;
        else if (x < v[mid]) // se x for menor que metade vai para esquerda
            r = mid - 1;
        else // se x for maior que metade vai para direita
            l = mid + 1;
    }
    return false;
}
