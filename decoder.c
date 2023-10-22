#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

int decoder (char *file, int (*interpreter_callback)(Instruction *instruction, Machine *machine), Machine *machine) {
    FILE* file_ptr = fopen(file, "r");
    if(file_ptr == NULL) {
        printf("ERROR: unable to open file \n");
        return 1;
    } 

    Instruction *instruction = (Instruction*) malloc(sizeof(Instruction));
    while (!feof(file_ptr)) {
        fscanf(file_ptr, "%s %s %s %s", instruction->operation_code, instruction->slot_1, instruction->slot_2, instruction->slot_3);
        interpreter_callback(instruction, machine);
    }

    fclose(file_ptr);
    return 0;
}