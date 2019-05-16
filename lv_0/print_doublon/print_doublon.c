#include <stdio.h>

void print_doublon(int *a, int na, int *b, int nb) {
	int flag = 0;
	for (int i = 0, j = 0; i < na && j < nb;) {
		if (a[i] == b[j]) {
			if (flag)
				printf(" %i", a[i]);
			else
				printf("%i", a[i]);
			i++;
			j++;
			flag = 1;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}
	printf("\n");
}
