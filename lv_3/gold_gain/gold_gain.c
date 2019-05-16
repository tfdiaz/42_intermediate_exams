#include <stdlib.h>

int gold_gain(int **mine, int n) {
	int *arr = (int *)malloc(sizeof(int) * n);
	int *tmp = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = mine[i][n - 1];
		tmp[i] = 0;
	}
	for (int x = n - 2; x >= 0; x--) {
		for (int y = 0; y < n; y++) {
			if (y == 0) {
				tmp[y] = arr[y];
				if (1 < n && arr[y + 1] > tmp[y])
					tmp[y] = arr[y + 1];
			}
			else if (y == n - 1) {
				tmp[y] = arr[y];
				if (y > 0 && arr[y - 1] > tmp[y])
					tmp[y] = arr[y - 1];
			}
			else {
				tmp[y] = arr[y];
				if (arr[y - 1] > tmp[y])
					tmp[y] = arr[y - 1];
				if (arr[y + 1] > tmp[y])
					tmp[y] = arr[y + 1];
			}
			tmp[y] += mine[y][x];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = tmp[i];
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

