#include <stdio.h>

void equation(int n) {
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for(int c = 0; c < 10; c++)
				if (a * 10 + b + c * 10 + a == n)
					printf("A = %i, B = %i, C = %i\n", a, b, c);
}
