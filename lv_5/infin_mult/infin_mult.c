#include <stdlib.h>
#include <unistd.h>

int slen(char *s)
{
	int i;
	for (i = 0; s[i] != '\0';i++)
		;
	return i;
}

void infin(char *s1, char *s2)
{
	int len1 = slen(s1);
	int len2 = slen(s2);
	int *arr = (int *)malloc(sizeof(int) * (len1 + len2));
	int neg = 1;
	int end1 = 0;
	int end2 = 0;
	if (s1[0] == '-')
	{
		neg *= -1;
		end1 = 1;
	}
	if (s2[0] == '-')
	{
		neg *= -1;
		end2 = 1;
	}
	int dex = len1 + len2 - 1;
	for (int i = 0; i < len1 + len2; i++)
		arr[i] = 0;
	int carry;
	for (int i = len1 - 1; i >= end1; i--)
	{
		int tmp_dex = dex;
		carry = 0;
		for (int j = len2 - 1; j >= end2; j--)
		{
			int result = (s1[i] - '0') * (s2[j] - '0') + carry;
			result += arr[tmp_dex];
			arr[tmp_dex] = result % 10;
			carry = result /10;
			tmp_dex--;
		}
		while (carry > 0)
		{
			carry += arr[tmp_dex];
			arr[tmp_dex] = carry % 10;
			carry /= 10;
			tmp_dex--;
		}
		dex--;
	}
	int i;
	for (i = 0; i < len1 + len2 -1; i++)
		if (arr[i] != 0)
			break;
	if (neg == -1 && arr[i] != 0)
		write(1, "-", 1);
	for (; i < len1 + len2; i++)
	{
		char c = arr[i] + '0';
		char *tmp = &c;
		write(1, tmp, 1);
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		infin(argv[1], argv[2]);
}
