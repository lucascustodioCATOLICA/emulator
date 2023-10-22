# Archtecture

- registers

  - x
  - y
  - c

- intructions

  - MOV <address | number> register
  - ADD <address | number> <address | number> <address>
  - SUB <address | number> <address | number> <address | number>
  - PRINT <address | number>

# Exec

gcc main.c interpreter.c decoder.c -o emulator.exe
