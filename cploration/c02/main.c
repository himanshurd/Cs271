#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100

/* Ex.1: Return the larger value */
int max(int x, int y) {
	if (x > y) {
		return x;
	} else if (y > x) {
		return y;
	} else {
    return x;
  }
	if (x == y) {
		return x;
	} else {
		return y;
	}

	/* Ex.2: Add [0..100] and return the sum */
	int add100() {
		int i, total = 0;
		for (int i = 1; i <= 100; i++) {
			total += i;
		}

		printf("%d", total);
		return total;
	}

	/* Ex .3 : Sum the elements in the array */
	int sum(int arr[], int n) {
		int i, sum = 0;

		for (int i = 0; i < n; i++)
			sum += arr[i];

		return sum;
	}

	/* Ex .4 : Find the largest element in the array */
	int largest(int arr[], int n) {
		int i;

		int max = arr[0];

		for (i = 1; i < n; i++)
			if (arr[i] > max)
				max = arr[i];

		return max;
	}

	/* Provided */
	int main() {
		// declare a string with value
char hello[] = "Hello";
// declare an empty string
char name[MAX_LIMIT];

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);
	}
}
