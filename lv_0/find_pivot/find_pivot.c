int find_pivot(int *arr, int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
		max += arr[i];
	int sublen = 0;
	for (int i = 0; i < n; i++) {	
		max -= arr[i];
		if (sublen == max)
			return i;
		sublen += arr[i];
	}
	return -1;
}
