int ismax(int *arr, int dex, int size) {
	int max = arr[dex];
	for (int i = dex; i < size; i++)
		if (arr[i] > max)
			return 0;
	return 1;
}

int volume_histogram(int *histogram, int size) {
	int total = 0;
	int ct = 0;
	int left = 0;
	int i = 0;
	for (i = 0; i < size && histogram[i] == 0; i++)
		;
	left = histogram[i];
	for (i += 1; i < size; i++) {
		if (histogram[i] == 0)
			ct++;
		else if (histogram[i] >= left) {
			total += left * ct;
			left = histogram[i];
			ct = 0;
		}
		else if (histogram[i] < left) {
			if (ismax(histogram, i, size)) {
				total += histogram[i] * ct;
				left = histogram[i];
				ct = 0;
			}
			else {
				total -= histogram[i];
				ct++;
			}
		}
	}
	return total;
}
