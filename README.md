# README — Comparação de Algoritmos de Ordenação

## 📌 Descrição do Problema

O objetivo deste projeto é comparar o desempenho de três algoritmos clássicos de ordenação **(Bubble Sort, Selection Sort e Quick Sort)** sobre vetores de inteiros. A análise envolve:

* Contagem de **passos** (comparações e trocas)
* Medição do **tempo de execução (ms)**
* Execução sobre três tamanhos de vetores aleatórios:

  * **N = 100**
  * **N = 1.000**
  * **N = 10.000**

Além disso, também é realizada a ordenação de um vetor fixo (RGM) para verificação manual de funcionamento.

---

## 🧠 Métodos Implementados e Justificativa

Foram escolhidos três algoritmos representativos de diferentes classes de eficiência:

### 1. **Bubble Sort**

* Simples implementação
* Muito utilizado em contextos educacionais
* Péssima performance para N grande → bom para evidenciar crescimento quadrático (O(n²))

### 2. **Selection Sort**

* Também O(n²), porém com número fixo de trocas
* Facilita comparar trade-off entre comparações e trocas
* Serve como contraste ao Bubble Sort

### 3. **Quick Sort**

* Algoritmo eficiente dividir-para-conquistar
* Complexidade média O(n log n)
* Usado amplamente em bibliotecas reais
* Incluído para comparar métodos básicos × método eficiente

---

## 🛠️ Como Compilar e Executar

Certifique-se de ter o GCC instalado. Para compilar com otimização leve e padrão C11:

```bash
gcc -O1 -std=c11 main.c -o ordena
```

E para executar:

```bash
./ordena
```

---

## 📏 Política de Contagem de Passos

A contagem considera:

### **🔹 Comparações**

Cada vez que o algoritmo verifica uma relação (ex.: `arr[j] > arr[j+1]`).

### **🔹 Trocas**

Sempre que dois elementos trocam de posição.

### **🔹 Quick Sort**

* Cada comparação na partição incrementa `passos`
* Cada troca real também incrementa `passos`
* Chamadas recursivas não contam como passos

A soma total fornece uma medida aproximada do custo lógico do algoritmo.

---

## ⏱️ Método de Medição do Tempo

O programa utiliza:

```c
clock_t inicio = clock();
...
double ms = (double)(clock() - inicio) * 1000.0 / CLOCKS_PER_SEC;
```

Ou seja:

* Tempo de CPU (clock interno)
* Resultado em **milissegundos (ms)**
* Cada teste é repetido 5 vezes para obter médias confiáveis

---

## 📊 Resultados (Médias de 5 Execuções)

### **Tabela de Tempos (ms)**

| Algoritmo      | N=100      | N=1000      | N=10000    |
| -------------- | ---------  | ---------   | ---------- |
| Bubble Sort    | 0.032 ms   | 2.0608 ms   | 192,948 ms |
| Selection Sort | 0.021 ms   | 1.2764 ms   | 114,756 ms |
| Quick Sort     | 0.0082 ms  | 0.1062 ms   | 6,276 ms   |

### CSV

```csv
N,passosBubble,tempoBubble_ms,passosSelection,tempoSelection_ms,passosQuick,tempoQuick_ms
100,7487,0.022,5049,0.013,1128,0.006
1000,752277,1.574,500499,0.937,17480,0.076
10000,75225439,173.612,50004999,89.601,238339,0.965
```

---


## 🧩 Discussão Crítica

### ⚙️ **Computabilidade × Escalabilidade**

* Bubble Sort e Selection Sort apresentam **crescimento quadrático**, tornando-se inviáveis para N ≥ 10.000.
* Quick Sort escala muito melhor, mantendo tempo proporcional a **N log N**.

### 🔎 **Limites Observados**

* Para N=10.000, Bubble Sort pode ultrapassar **milhões de passos** e consumir centenas de milissegundos.
* Selection Sort faz menos trocas, mas número similar de comparações → também lento.
* Quick Sort supera ambos em várias ordens de magnitude.

### 🏆 **Conclusão: Melhor Método**

**Quick Sort** é claramente superior, tanto em tempo quanto em número de passos. Ele é também o algoritmo usado como base em diversas bibliotecas padrão modernas devido à sua eficiência e escalabilidade.

Para fins didáticos:

* Bubble Sort mostra comportamento quadrático extremo
* Selection Sort ilustra caso onde número de trocas é minimizado
* Quick Sort demonstra abordagem eficiente real aplicada em software moderno

---

## ✔️ Finalização

Este projeto oferece uma comparação clara entre algoritmos fundamentais de ordenação, evidenciando a diferença drástica entre métodos O(n²) e O(n log n). Ideal tanto para estudo quanto para análise prática.
