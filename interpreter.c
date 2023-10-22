#include "machine.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int interpreter (Instruction *instruction, Machine *machine) {
    if(strcmp(instruction->operation_code, "MOV") == 0) {
        if(strcmp(instruction->slot_2, "X") == 0) {
            if(strcmp(instruction->slot_1, "Y") == 0) {
                machine->x = machine->y;
            } else if(strcmp(instruction->slot_1, "Z") == 0) {
                machine->x = machine->z;
            } else {
                if(atoi(instruction->slot_1) != 0) {
                    machine->x = atoi(instruction->slot_1);
                } else {
                    printf("ERROR (17): unable to convert to int \n");
                }
            }
        }
        if(strcmp(instruction->slot_2, "Y") == 0) {
            if(strcmp(instruction->slot_1, "X") == 0) {
                machine->y = machine->x;
            } else if(strcmp(instruction->slot_1, "Z") == 0) {
                machine->y = machine->z;
            } else {
                if(atoi(instruction->slot_1) != 0) {
                    machine->y = atoi(instruction->slot_1);
                } else {
                    printf("ERROR (30): unable to convert to int \n");
                }
            }
        }
        if(strcmp(instruction->slot_2, "Z") == 0) {
            if(strcmp(instruction->slot_1, "X") == 0) {
                machine->z = machine->x;
            } else if(strcmp(instruction->slot_1, "Y") == 0) {
                machine->z = machine->y;
            } else {
                if(atoi(instruction->slot_1) != 0) {
                    machine->z = atoi(instruction->slot_1);
                } else {
                    printf("ERROR (43): unable to convert to int \n");
                }
            }
        }
    } 
    if(strcmp(instruction->operation_code, "ADD") == 0) {
        int num1;
        int num2;

        if(strcmp(instruction->slot_1, "X") == 0) {
            num1 = machine->x;
        } else if (strcmp(instruction->slot_1, "Y") == 0) {
            num1 = machine->y;
        } else if (strcmp(instruction->slot_1, "Z") == 0) {
            num1 = machine->z;
        } else {
            num1 = atoi(instruction->slot_1);
        }

        if(strcmp(instruction->slot_2, "X") == 0) {
            num2 = machine->x;
        } else if (strcmp(instruction->slot_2, "Y") == 0) {
            num2 = machine->y;
        } else if (strcmp(instruction->slot_2, "Z") == 0) {
            num2 = machine->z;
        } else {
            num2 = atoi(instruction->slot_2);
        }

        if(num1 == 0 || num2 == 0) {
            printf("ERROR (73): unable to convert to int \n");
        }

        const int result = num1 + num2;

        int *target_register;

        if(strcmp(instruction->slot_3, "X") == 0) {
            target_register = &machine->x;
        }
        if(strcmp(instruction->slot_3, "Y") == 0) {
            target_register = &machine->y;
        }
        if(strcmp(instruction->slot_3, "Z") == 0) {
            target_register = &machine->z;
        }

        *target_register = result;
    } 
    if(strcmp(instruction->operation_code, "SUB") == 0) {
        int num1;
        int num2;

        if(strcmp(instruction->slot_1, "X") == 0) {
            num1 = machine->x;
        } else if (strcmp(instruction->slot_1, "Y") == 0) {
            num1 = machine->y;
        } else if (strcmp(instruction->slot_1, "Z") == 0) {
            num1 = machine->z;
        } else {
            num1 = atoi(instruction->slot_1);
        }

        if(strcmp(instruction->slot_2, "X") == 0) {
            num2 = machine->x;
        } else if (strcmp(instruction->slot_2, "Y") == 0) {
            num2 = machine->y;
        } else if (strcmp(instruction->slot_2, "Z") == 0) {
            num2 = machine->z;
        } else {
            num2 = atoi(instruction->slot_2);
        }

        if(num1 == 0 || num2 == 0) {
            printf("ERROR (117): unable to convert to int \n");
        }

        const int result = num1 - num2;

        int *target_register;

        if(strcmp(instruction->slot_3, "X") == 0) {
            target_register = &machine->x;
        }
        if(strcmp(instruction->slot_3, "Y") == 0) {
            target_register = &machine->y;
        }
        if(strcmp(instruction->slot_3, "Z") == 0) {
            target_register = &machine->z;
        }

        *target_register = result;
    } 
    if(strcmp(instruction->operation_code, "PRINT") == 0) {
        if(strcmp(instruction->slot_1, "X") == 0) {
            printf("%d \n", machine->x);
        } else if(strcmp(instruction->slot_1, "Y") == 0) {
            printf("%d \n", machine->y);
        } else if(strcmp(instruction->slot_1, "Z") == 0) {
            printf("%d \n", machine->z);
        } else {
            printf("%s \n", instruction->slot_1);
        }
    } 


    return 0;
}