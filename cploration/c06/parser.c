#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(FILE *file) {
	char line[MAX_LINE_LENGTH] = {0};

	while (fgets(line, sizeof(line), file)) {
		strip(line);
		if (!*line) {
			continue;
		}
		char inst_type = '\0';
		if (is_Atype(line)) {
			inst_type = 'A';
		} else if (is_Ctype(line)) {
			inst_type = 'C';
		} else if (is_label(line)) {
			inst_type = 'L';
			char *new_label[strlen(line) + 1];
			extract_label(line, new_label);
			strcpy(line, new_label)
		}
		printf("%c  %s\n", inst_type, line);
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
	strcpy(s, s_new);
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

char *extract_label(const char *line, char *label) {
	char *s = line;
	char *s_end = s + strlen(s) - 1;
	for (s = s + 1; s < s_end; s++) {
		// copy s to lable; increment label
		label[i++] = s
	}
	label[i] = '\0';
	// strcpy(label, line + 1, strlen(line) - 2);
	return label;
}
