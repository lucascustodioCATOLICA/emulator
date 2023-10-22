# Archtecture

- registers

  - x
  - y
  - c

- intructions

  - MOV <address | number> register
    copia um valor ou endereco para o registrador
  - ADD <address | number> <address | number> <address>
    adiciona o primeiro numero no segundo e armazena no registrador especificado no terceiro argumento
  - SUB <address | number> <address | number> <address | number>
    subtrai o primeiro numero no segundo e armazena no registrador especificado no terceiro argumento
  - PRINT <address>
    printa o valor armazenado no endereco

# Exec

gcc main.c interpreter.c decoder.c -o emulator.exe
