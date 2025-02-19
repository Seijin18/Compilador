# Compilador
## Compilação do Projeto

Siga os passos abaixo para compilar e executar o projeto:

1. **Compilação do arquivo `bison.y`**
    - Utilize o comando abaixo para compilar o arquivo `bison.y`:
      ```sh
      bison -d bison.y
      ```

2. **Geração do executável**
    - Utilize o comando abaixo para compilar o arquivo `bison.tab.c` e `funcs.c`:
      ```sh
      gcc -o compilador bison.tab.c funcs.c
      ```

3. **Execução do programa**
    - Utilize o comando abaixo para executar o programa:
      ```sh
      ./compilador <filename> flag
      ```
    - Onde `<filename>` é o nome do arquivo a ser compilado e `flag` é a flag que indica a fase de compilação a ser executada. As flags disponíveis são:
      - `-l` ou `-L` para a fase de análise léxica
      - `-p` ou `-P` para a fase de análise sintática
      - `-s` ou `-S` para a fase de análise semântica