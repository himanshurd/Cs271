#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 200

/** Exercise 1 **/
int main(int argc, const char *argv[]) {
	/** Exersice 2 **/
	if (argc != 2) {
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/** Exercise 3 **/
	FILE *fin;
	fin = fopen(argv[1], "r");
	if (fin == NULL) {
		perror("Unable to open file!");
		exit(EXIT_FAILURE);
	}

	/** Exercise 4 **/
	char out_file[MAX_LINE_LENGTH];
	strcpy(out_file, argv[1]);
	strcat(out_file, ".echo");
	FILE *fout = fopen(out_file, "w+");

	/** Exercise 5 **/
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_num = 0;
	while (fgets(line, sizeof(line), fin)) {
		line_num++;
		printf("[%04d] %s", line_num, line);
		fprintf(fout,"%s", line);
	}

	/** Exercise 6 **/
	fclose(fin);
	fclose(fout);
	return 0;
}
