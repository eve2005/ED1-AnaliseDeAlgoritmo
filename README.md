# 📊 Trabalho Prático: Análise Experimental de Algoritmos de Ordenação e Busca

Este projeto implementa, analisa e compara diferentes algoritmos de **ordenação** e **busca**, registrando métricas como:

- Número de **comparações**
- Número de **trocas**
- **Tempo de execução** (em milissegundos)

Os experimentos são realizados sobre conjuntos de dados em três tamanhos diferentes (**pequeno**, **médio**, **grande**) e três cenários distintos (**aleatório**, **crescente**, **decrescente**).

O conjunto de dados é gerado dentro do projeto.  
➡️ **A geração automática do conjunto está comentada para garantir que todos os arquivos tenham exatamente os mesmos dados usados na análise do relatório.**  
Caso deseje gerar um novo conjunto de dados, basta **descomentar** a linha 35 do arquivo `codigo/main.cpp`:

```cpp
// gerarTodosOsDados(); // COMENTADO PARA OS ARQUIVOS ESTEJAM COM MESMOS DADOS DO USADO NO RELATORIO
```
---

## 📂 Estrutura do Projeto
```bash
├── codigo/
│ ├── busca.cpp  /*implementação de busca*/
│ ├── busca.hpp /*cabeçalho de busca*/
| ├── gerador.cpp /*implementação do gerador dos conjuntos de dados*/
│ ├── gerador.hpp /*cabeçalho de gerador*/
| ├── main.cpp /* arquivo principal que aplica o experimento*/
│ ├── metrica.hpp /*cabeçalho que possui a struct de Metrica*/
| ├── ordenacao.cpp /* implementação de ordenação*/
│ └── ordenacao.hpp /*cabeçalho de ordencao*/
|
├── dados/ /* PASTA COM O CONJUNTO DE DADOS GERADO PELO GERADOR*/
│ ├── grande_aleatorio.bin
│ ├── grande_crescente.bin
│ ├── grande_decrescente.bin
│ ├── medio_aleatorio.bin
│ ├── medio_crescente.bin
│ ├── medio_decrescente.bin
│ ├── pequeno_aleatorio.bin
│ ├── pequeno_crescente.bin
│ └── pequeno_decrescente.bin
|
├── relatório.pdf
├── resultado.txt /*SAIDA de dados/resultados usado na nossa analise/relatorio*/
└── README.txt  
```


---

## 🔧 Algoritmos Implementados

### **Ordenação**
- Selection Sort  
- Insertion Sort  
- Bubble Sort  
- Bubble Sort Otimizado  

### **Busca**
- Busca Linear (Sequencial)  
- Busca Binária (em vetor previamente ordenado)  

---

## 🛠️ Execução do Projeto

Para rodar o projeto, siga os passos:

### 1️⃣ Clone este repositório
```bash
git clone https://github.com/eve2005/ED1-AnaliseDeAlgoritmo.git
```
### 2️⃣ Acesse a página codigos
```bash
cd codigo
```
### 3️⃣ Compile o projeto
```bash
g++ main.cpp gerador.cpp busca.cpp ordenacao.cpp -o experimento 
```
### 4️⃣ Execute o projeto
```bash
//NO WINDOWS
experimento.exe

//NO LINUX
./experimento

```


## Autores

- [Evellyn Cipriano ](https://www.github.com/eve2005)
- [Leonardo Furlan ](https://www.github.com/leo-furlan12)
