# Projeto de integração de bibliotecas em C
Integração de um intepretador Python dentro de C/C++. Para uso da biblioteca **Levenshtein** e criação da biblioteca para uso da função 
do calculo da **distância de Hamming**.

## Sobre o Projeto
Este projeto demonstra como integrar um interpretador Python em um programa em C/C++ utilizando o PocketPy, com foco na execução dinâmica de scripts Python diretamente a partir de um programa em C.

A aplicação principal envolve:

* O uso da biblioteca Levenshtein, implementada em Python, para calcular a distância de Levenshtein entre pares de strings.

* A implementação de uma função nativa em C/C++ para cálculo da distância de Hamming, exposta ao interpretador Python como uma função utilizável nos scripts.

Essa integração permite que o programa em C carregue e execute scripts Python que operam sobre dados vindos do próprio código em C, aproveitando tanto a performance nativa quanto a flexibilidade dos scripts.

>Este projeto foi desenvolvido como parte da disciplina **Programação para Interface de Hardware e Software**, com o objetivo de explorar técnicas de
>interoperabilidade entre linguagens e a extensão de linguagens de script com funções nativas.

## Execução

Utiliza-se os comandos do CMake para execução e compilação do projeto:

    ```
    Make
    Make run
    Make clean
    ```

Faz-se necessário um script python com o nome *script.py* para execução do código.


>⚠️ **Importante:**
>Use **aspas simples** (`'`) no script Python. O uso de aspas duplas (`"`) pode causar erros no interpretador PocketPy.

## Exemplos de scripts em Python:
```
print('A distancia entre ' + stringa + ' e ' + stringb + ' é: ' + str(distancia))
strings = ['banana macaco', 'lata vara', 'xica xico', 'leandros leonardo']
```

**Não utlize aspas duplas ("") em nenhum momento, isso causa erro dentro da analise de string do pocketpy**

# Licença

Este projeto está licenciado sob a licença MIT

O interpretador PocketPy (https://github.com/blueloveTH/pocketpy) também é licenciado sob a licença MIT.
