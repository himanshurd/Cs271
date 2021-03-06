#include "parser.h"
#include "error.h"
#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void parse(FILE * file, instruction * instructions) {
  char line[MAX_LINE_LENGTH] = {0};
  instruction instr; 
  unsigned int line_num = 0;
  unsigned int instr_num = 0; 
  instruction instr;
  
  add_predefined_symbols();
  while (fgets(line, sizeof(line), file)) {

    line_num = line_num + 1;
    if (instr_num > MAX_INSTRUCTIONS) {
      exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
    }
    strip(line);
    if (!*line) {
      continue;
    }
    char inst_type = '\0';
    if (is_Atype(line)) {
      inst_type = 'A';
      if (!parse_A_instruction(line, &instr.a_instr)){
        exit_program(EXIT_INVALID_A_INSTR, line_num, line);
      }
      instr.instr_type = A_TYPE;
     }  else if (is_Ctype(line)) {
       inst_type = 'C';
     }  else if (is_label(line)) {
       if (isalpha(line[0])) {
         exit_program(EXIT_INVALID_LABEL, line_num, line);
       } else if (symtable_find(line) != NULL) {
          exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
       }
       symtable_insert(line, instr_num);
       continue;

       inst_type = 'L';
       char new_label[MAX_LABEL_LENGTH];
       extract_label(line, new_label);
       printf("%c  %s\n", inst_type, new_label);
       continue;
     }     
     printf("%c  %s\n", inst_type, line);
     instr_num = instr_num + 1;
   }
}

char *strip(char *s) {
  char s_new[strlen(s) + 1];
  int i = 0;
  for (char *s2 = s; *s2; s2++) {
    if ((*s2 == '/') && (*(s2 + 1) == '/')) {
      break;
    } else if (!isspace(*s2)) {
      s_new[i++] = *s2;
    }
    s_new[i] = '\0';
  }
  strcpy(s,s_new);
  return s;
}

bool is_Atype(const char *line) {
  return line[0] == '@';
}

bool is_label(const char *line) {
  int size = strlen(line);
  return (line[0] == '(') && (line[size - 1] == ')');
}

bool is_Ctype(const char *line) {
  return !(is_Atype(line) || is_label(line));
}

char *extract_label(const char *line, char* label) {
  strncpy(label, line + 1, strlen(line) - 2);
  return label;
}

void add_predefined_symbols() {
  for (int i = 0; i < NUM_PREDEFINED_SYMBOLS; i++) {
    predefined_symbol symbol = predefined_symbols[i];
    symtable_insert(symbol.name, symbol.address);
  }
}

bool parse_A_instruction(const char *line, a_instruction *instr) {
  char *s = (char*) malloc(strlen(line));
  strcpy(s, line + 1);
  char *s_end = NULL;
  long result = strtol(s, &s_end, 10);

  if (s == s_end) {
    instr->label = (char*) malloc(strlen(line));
    strcpy(instr->label, s);
    instr->is_addr = false;
  } else if (*s_end != 0) {
    return false;
  } else {
    instr->address = result;
    instr->is_addr = true;
  }
  return true;
}

void parse_C_instruction(char *line, c_instruction *instr) {

    char delimiter[3] = "=;";
    char * line_copy = malloc(sizeof(line) * strlen(line) + 1);
    
    strcpy(line_copy, line);
    
    int i = 0;
    char * results[3];
    char * tok = strtok(line, delimiter);
    int a = 0;

    while (tok != NULL) {
        results[i++] = tok;
        tok = strtok(NULL, delimiter);
    }

    if(strchr(line_copy, ';') != NULL && strchr(line_copy, '=') != NULL) {
        instr->dest = str_to_dest_id(results[0]);
        instr->comp = str_to_compid(results[1], &a);
        instr->a = a == 1 ? instr->a & 0x1: 0;

    }
    else if(strchr(line_copy, ';') != NULL) {
        instr->dest = 0;
        instr->comp = str_to_compid(results[0], &a);
        instr->jump = str_to_jumpid(results[1]);
        instr->a = a;
    }
    else if(strchr(line_copy, '=') != NULL) {
        instr->dest = str_to_dest_id(results[0]);
        instr->comp = str_to_compid(results[1], &a);
        instr->jump = 0;
        instr->a = a;
    }
    else {
        instr->dest = 0;
        instr->comp = str_to_compid(results[0], &a);
        instr->jump = 0;
        instr->a = a == 1 ? instr->a & 0x1: 0;
    }
    free(line_copy);
}