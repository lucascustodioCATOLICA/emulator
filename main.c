#include <stdio.h>
#include <stdlib.h>

#include "machine.h"
#include "interpreter.h"
#include "decoder.h"

int main (int argc, char *argv[]) {
    if (argc == 1) {
        printf("ERROR: no file \n");
        return 1;
    }
    char *emu_path = argv[1];

    Machine *machine = (Machine*) malloc(sizeof(Machine));
    int (*interpreter_callback)(Instruction*, Machine*) = interpreter;

    decoder(emu_path, interpreter_callback, machine);

    return 0;
}