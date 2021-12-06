#include "parser.h"
#include "error.h"

int main(int args, char *argv[]) {

    char test_string[8] = "A=D;JGE";
    char delimiter[3] = "=;";
    int i = 0;
    char * results[3];
    char * tok = strtok(test_string, delimiter);
    
    while (tok != NULL) {
        results[i++] = tok;
        tok = strtok(NULL, delimiter);
    }
    while (i > 0) {
        i--;
        printf("Index: %d, results: %s\n", i, results[i]);
    }
    return 0;
}