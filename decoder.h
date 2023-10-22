#ifndef DECODER_FILE
#define DECODER_FILE

#include "machine.h"

int decoder (char *file, int (*interpreter_callback)(Instruction*, Machine*), Machine *machine);

#endif