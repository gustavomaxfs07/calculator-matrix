# Calculator Matrix

Uma aplicação em linguagem C para realizar operações matemáticas com matrizes, incluindo soma, subtração, multiplicação e cálculo do determinante.

## Descrição

Este projeto permite que o usuário execute operações com matrizes diretamente pelo terminal. As operações disponíveis são:

* Soma de matrizes
* Subtração de matrizes
* Multiplicação de matrizes
* Cálculo do determinante de matrizes quadradas

O programa possui menus interativos e realiza validações para garantir que as dimensões das matrizes sejam compatíveis para cada operação.

## Funcionalidades

* Soma de matrizes
* Subtração de matrizes
* Multiplicação de matrizes
* Cálculo do determinante
* Validação de entradas
* Interface interativa via terminal

## Estrutura do Projeto

calculator-matrix/

├── calculator.c (código-fonte principal)

└── README.md (documentação)

## Como executar

### Pré-requisitos

* Compilador C instalado (GCC, Clang ou equivalente)
* Ou GBD Online

### Compilação (No repositório já possui o executavel basta executar se preferir)

No terminal, execute:

No Windows:

```
gcc calculator.c -o calculator.exe
```

No Linux ou macOS:

```
gcc calculator.c -o calculator
```

### Execução (Terminal ou Compilador Online => [GBD Online](https://www.onlinegdb.com/))

No Windows:

```
calculator.exe
```

No Linux ou macOS:

```
./calculator
```

Compilador online [GBD Online](https://www.onlinegdb.com/):

Acesse o código fonte compilado no GBD Online [aqui](https://www.onlinegdb.com/6QSc4U3Ts)

Acesse o [GBD Online](https://www.onlinegdb.com/) e selecione a linguagem C.

Acesse o código [aqui](https://github.com/gustavomaxfs07/calculator-matrix/blob/main/main.c) copie e cole no [GBD Online](https://www.onlinegdb.com/) e execute [GBD Online](https://www.onlinegdb.com/).
## Demonstração

Ao executar o programa, o menu principal será exibido:

```
======= MENU =======
1 - Calcular matrizes
2 - Calcular determinante
0 - Sair

Escolha uma opcao:
```

O submenu de operações com matrizes oferece:

```
======= MENU =======
1 - Soma de matrizes
2 - Subtração de matrizes
3 - Multiplicação de matrizes
0 - Sair
```

## Cálculo de Determinante

O cálculo do determinante suporta matrizes quadradas de qualquer ordem, utilizando o algoritmo de expansão de Laplace implementado de forma recursiva.

## Tecnologias

* Linguagem C
* GCC ou compilador equivalente
* Terminal (linha de comando)

## Contribuição

Contribuições são bem-vindas. Sinta-se livre para abrir issues, sugerir melhorias ou enviar pull requests.
