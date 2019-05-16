#include <stdlib.h>
#include <string.h>

char	*new_string(int st, int len, char *s)
{
	char *ret = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++, st++) {
		ret[i] = s[st];
	}
	ret[len] = '\0';
	return ret;
}

char	*longest_subarray(char *arr) {
	int slen = strlen(arr);
	if (slen == 0)
		return "";
	int *odds = (int *)malloc(sizeof(int) * slen);
	odds[0] = 0;
	for (int i = 0; i < slen; i++) {
		if (i > 0)
			odds[i] = odds[i - 1];
		if ((arr[i] - '0') % 2 == 1)
			odds[i]++;
	}
	if (odds[slen - 1] * 2 == slen)
		return arr;
	for (int len = slen - 1; len > 1; len--)
	{
		int gap = slen - len;
		for (int i = 0; i <= gap; i++)
		{
			int ct = 0;
			if (i > 0)
				ct = odds[i + len - 1] - odds[i - 1];
			else
				ct = odds[i + len - 1];
			if (ct * 2 == len)
				return new_string(i, len, arr);
		}
	}
	return "";
}
