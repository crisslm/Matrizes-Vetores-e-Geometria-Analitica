📐 Projeto de Matrizes, Vetores e Geometria Analítica em C

Este projeto foi desenvolvido com o objetivo de praticar e demonstrar conceitos fundamentais de álgebra linear e geometria analítica, utilizando a linguagem C para implementar operações com vetores, matrizes e elementos geométricos.

#OBS: o PROJETO AINDA ESTÁ EM DESENVOLVIMENTO, SENDO ASSIM, A APRESENTAÇÃO A SEGUIR DIZ RESPEITO ÀS FUTURAS FUNCIONALIDADES.

🚀 Funcionalidades

O projeto conta com módulos que permitem:

🔢 Operações com Vetores

Criação e leitura de vetores;

Soma e subtração de vetores;

Produto escalar;

Produto vetorial (em 3D);

Cálculo de norma;

Distância entre dois vetores;

Verificação de ortogonalidade.

🧮 Operações com Matrizes

Criação e leitura de matrizes;

Soma e subtração de matrizes;

Multiplicação matriz × matriz e matriz × vetor;

Cálculo da transposta;

Determinante (2×2 e 3×3);

Matriz inversa (quando aplicável).

📏 Geometria Analítica

Equação da reta (forma vetorial e paramétrica);

Distância ponto–reta e ponto–plano;

Verificação de paralelismo e perpendicularidade entre retas/planos;

Cálculo de ângulo entre vetores, retas e planos.

🗂 Estrutura do Projeto
/src
  ├── vetores.c
  ├── matrizes.c
  ├── geometria.c
  ├── utils.c
  ├── main.c
/include
  ├── vetores.h
  ├── matrizes.h
  ├── geometria.h
  ├── utils.h
README.md
Makefile

🛠 Tecnologias Utilizadas

Linguagem: C (C11)

Compilador: GCC / Clang

Ferramentas opcionais: Make

▶️ Como Compilar e Executar
Usando Make
make
./programa

Manualmente
gcc src/*.c -I include -o programa
./programa

📝 Exemplos de Uso
Criar e operar vetores
Vector a = criar_vetor(3, (double[]){1, 2, 3});
Vector b = criar_vetor(3, (double[]){4, 5, 6});

double escalar = produto_escalar(a, b);

Multiplicar matrizes
Matrix A = criar_matriz(2, 2, (double[]){1, 2, 3, 4});
Matrix B = criar_matriz(2, 2, (double[]){5, 6, 7, 8});

Matrix C = multiplicar_matrizes(A, B);

📌 Objetivos de Aprendizagem

Reforçar o uso de ponteiros e alocação dinâmica em C;

Consolidar operações de álgebra linear implementadas “na mão”;

Estruturar um projeto modular;

Resolver problemas clássicos de geometria analítica programaticamente.

🤝 Contribuição

Sinta-se à vontade para sugerir melhorias, abrir issues ou enviar pull requests!