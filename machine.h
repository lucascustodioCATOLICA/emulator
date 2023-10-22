#ifndef MACHINE_FILE
#define MACHINE_FILE

typedef struct Instruction
{
    char operation_code[5];
    char slot_1[3];
    char slot_2[3];
    char slot_3[3];
} Instruction;

typedef struct Machine
{
    int x;
    int y;
    int z;
} Machine;

#endif