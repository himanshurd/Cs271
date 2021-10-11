#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100
int main(void) 
{
	char hello[] = "Hello";
	char name[MAX_LIMIT];
	char welcome[MAX_LIMIT];
	char prof[8] = {'P', 'a', 't', 'r', 'i', 'c', 'k', '\0'};

	/** Exercise 1 **/
	strcpy(welcome, hello);
	strcat(welcome, " ");
	strcat(welcome, name);
	printf("What is your name? ");

	// /** Exercise 2 **/
	scanf(" %s", name);
	int len = strlen(name);
	printf("Hello %s!\n\n\n", name);
        printf("Hello %s!\n", name);
	printf("Your name is %d characters long\n", len);

	// /** Exercise 3 **/
	int f;
	f = strcmp(name, prof);
	if (f > 0) {
		printf("%s is before %s", name, prof);
	} else if (f < 0) {
		printf("%s is after %s", name, prof);
	} else if (f == 0) {
		printf("%s is %s", name, prof);
	}
	return 0;
}
