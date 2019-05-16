int is_anagram(char *a, char *b) {
	int arr[127];
	for (int i = 0; i < 127; i++)
		arr[i] = 0;
	for (int i = 0; a[i] != '\0'; i++)
		arr[(int)a[i]]++;
	for (int i = 0; b[i] != '\0'; i++)
		arr[(int)b[i]]--;
	for (int i = 0; i < 127; i++)
		if (arr[i] != 0)
			return 0;
	return 1;
}
