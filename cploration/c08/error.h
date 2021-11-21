#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdarg.h>

enum exitcode { 
  EXIT_INCORRECT_ARGUMENTS = 1,
  EXIT_CANNOT_OPEN_FILE = 2,
  EXIT_TOO_MANY_INSTRUCTIONS = 3,
};

void exit_program(enum exitcode code, ...);


