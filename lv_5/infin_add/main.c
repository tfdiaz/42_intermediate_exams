#include <stdlib.h>
#include <unistd.h>

int slen(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}

void sub(char *n1, char *n2, int l1, int l2, int sign)
{
	int *ret = (int *)malloc(sizeof(int) * (l1));
	for (int i = 0; i < l1; i++)
		ret[i] = 0;
	int carry = 0;
	int i;
	int k;
	for (i = l1 - 1, k = l2 - 1; k >= 0; i--, k--)
	{
		int val1 = (n1[i] - '0') - carry;
		int val2 = n2[k] - '0';
		if (val1 < val2)
		{
			carry = 1;
			val1 += 10;
		}
		else
			carry = 0;
		ret[i] = val1 - val2;
	}
	for (; i >= 0; i--)
	{
		int val1 = n1[i] - '0' - carry;
		if (val1 < 0)
		{
			carry = 1;
			val1 += 10;
		}
		else
			carry = 0;
		ret[i] = val1;
	}
	for (i = 0; i < l1 - 1; i++)
		if (ret[i] != 0)
			break;
	if (sign && ret[i] != 0)
		write(1, "-", 1);
	for (; i < l1; i++)
	{
		char c = ret[i] + '0';
		write(1, &c, 1);
	}
}

void add(char *n1, char *n2, int l1, int l2, int sign)
{
	int *ret = (int *)malloc(sizeof(int) * (l1 + 1));
	for (int i = 0; i < l1; i++)
		ret[i] = 0;
	int carry = 0;
	int i;
	int k;
	for (i = l1 - 1, k = l2 - 1; k >= 0; i--, k--)
	{
		int val1 = (n1[i] - '0') + carry;
		int val2 = n2[k] - '0';
		if (val1 + val2 > 9)
		{
			ret[i] = (val1 + val2) % 10;
			carry = 1;
		}
		else
		{
			carry = 0;
			ret[i] = val1 + val2;
		}
	}
	for (; i >= 0; i--)
	{
		int val1 = (n1[i] - '0') + carry;
		if(val1 > 9)
		{
			ret[i] = val1 % 10;
			carry = 1;
		}
		else
		{
			carry = 0;
			ret[i] = val1;
		}
	}
	for (i = 0; i < l1 - 1; i++)
		if (ret[i] != 0)
			break;
	if (sign && ret[i] != 0)
		write(1, "-", 1);
	for (; i < l1; i++)
	{
		char c = ret[i] + '0';
		write(1, &c, 1);
	}
}

int large(char *n1, char *n2, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (n1[i] > n2[i])
			return 1;
		else if (n1[1] < n2[i])
			return 0;
	}
	return 0;
}	

void parse(char *n1, char *n2)
{
	int len1 = slen(n1);
	int len2 = slen(n2);
	int sign1 = 0;
	int sign2 = 0;
	if (n1[0] == '-')
	{
		sign1 = 1;
		len1--;
		n1++;
	}
	if (n2[0] == '-')
	{
		sign2 = 1;
		len2--;
		n2++;
	}
	if (sign1 && !sign2)
	{
		if (len1 > len2)
			sub(n1, n2, len1, len2, 1);
		else if(len1 == len2)
		{
			if (large(n1, n2, len1))
				sub(n1, n2, len1, len2, 1);
			else
				sub(n1, n2, len1, len2, 0);
		}
		else
			sub(n2, n1, len2, len1, 0);
	}
	else if (sign2 && !sign1)
	{
		if (len2 > len1)
			sub(n2, n1, len2, len1, 1);
		else if(len1 == len2)
		{
			if (large(n2, n1, len1))
				sub(n2, n1, len2, len1, 1);
			else
				sub(n1, n2, len1, len2, 0);
		}
		else
			sub(n1, n2, len1, len2, 0);
	}
	else if (sign1 && sign2)
	{
		if (len1 > len2)
			add(n1, n2, len1, len2, 1);
		else
			add(n2, n1, len2, len1, 1);
	}
	else
	{
		if (len1 > len2)
			add(n1, n2, len1, len2, 0);
		else
			add(n2, n1, len2, len1, 0);
	}
}
	

int main(int argc, char **argv)
{
	if (argc == 3)
		parse(argv[1], argv[2]);
	write(1, "\n", 1);
}
