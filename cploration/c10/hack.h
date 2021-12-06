#ifndef __HACK_H__
#define __HACK_H__

#define NUM_PREDEFINED_SYMBOLS 23
#include <stdint.h>
#include <string.h>


typedef enum symbol_id {
    SYM_RO = 0,
    SYM_R1, 
    SYM_R2,
    SYM_R3,
    SYM_R4,
    SYM_R5,
    SYM_R6,
    SYM_R7,
    SYM_R8,
    SYM_R9,
    SYM_R10,
    SYM_R11,
    SYM_R12,
    SYM_R13,
    SYM_R14,
    SYM_R15,
    SYM_SP = 0,
    SYM_LCL,
    SYM_ARG,
    SYM_THIS,
    SYM_THAT,
    SYM_SCREEN = 16384,
    SYM_KBD = 24576
} symbol_id;

typedef enum jump_id {
    JMP_INVALID = -1,
    JMP_NULL,
    JMP_JGT,
    JMP_JEQ,
    JMP_JGE,
    JMP_JLT,
    JMP_JNE,
    JMP_JLE,
    JMP_JMP
} jump_id;

typedef enum dest_id {
    DEST_INVALID = -1,
    DEST_NULL,
    DEST_M,
    DEST_D,
    DEST_DM,
    DEST_A,
    DEST_AM,
    DEST_AD,
    DEST_ADM
} dest_id;

typedef enum comp_id {
    COMP_INVALID = -1,
    COMP_0 = 42,
    COMP_1 = 63,
    COMP_NEG_1 = 58,
    COMP_D = 12,
    COMP_A = 48,
    COMP_M = 48,
    COMP_NOT_D = 13,
    COMP_NOT_A = 49,
    COMP_NOT_M = 49,
    COMP_NEG_D = 15,
    COMP_NEG_A = 51,
    COMP_NEG_M = 51,
    COMP_D_PLUS_1 = 31,
    COMP_A_PLUS_1 = 55,
    COMP_M_PLUS_1 = 55,
    COMP_D_MINUS_1 = 14,
    COMP_A_MINUS_1 = 50,
    COMP_M_MINUS_1 = 50,
    COMP_D_PLUS_A = 2,
    COMP_D_PLUS_M = 2,
    COMP_D_MINUS_A = 19,
    COMP_D_MINUS_M = 19,
    COMP_A_MINUS_D = 7,
    COMP_M_MINUS_D = 7,
    COMP_D_AND_A = 0,
    COMP_D_AND_M = 0,
    COMP_D_BIN_OR_A = 21,
    COMP_D_BIN_OR_M = 21
} comp_id;

