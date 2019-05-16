#include <stdlib.h>
#include <unistd.h>

int ctwords(char *s)
{
	int ct = 0;
	int flag = 1;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\t')
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			ct++;
		}
	}
	return ct;
}

void attach(char **arr, char *s)
{
	int flag = 1;
	int k = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			s[i] = '\0';
			flag = 1;
		}
		else if (flag == 1)
		{
			arr[k] = s + i;
			flag = 0;
			k++;
		}
	}
}

int slen(char *s)
{
	int i = 0;
	for (; s[i] != '\0'; i++)
		;
	return i;
}

void sortlen(char **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int k = i;
		for (; k < len; k++)
		{
			if (slen(arr[i]) > slen(arr[k]))
			{
				char *tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
		}
	}
}

int swap(char *f, char *s)
{
	for (int i = 0; f[i] != '\0'; i++)
	{
		char a = f[i];
		char b = s[i];
		if (a >= 'A' && a <= 'Z')
			a += 32;
		if (b >= 'A' && b <= 'Z')
			b += 32;
		if (a > b)
			return 1;
		else if (a < b)
			return 0;
	}
	return 0;
}

void sortalp(char **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int k = i + 1;
		for (; k < len; k++)
		{
			if (slen(arr[i]) == slen(arr[k]))
			{
				if(swap(arr[i], arr[k]))
				{
					char *tmp = arr[i];
					arr[i] = arr[k];
					arr[k] = tmp;
				}
			}
		}
	}
}

void print(char **arr, int len)
{
	int cur = 0;
	for (int i = 0; i < len; i++)
	{
		if (cur == slen(arr[i]))
		{
			write(1, " ", 1);
			write(1, arr[i], slen(arr[i]));
		}
		else if (i > 0)
		{
			write(1, "\n", 1);
			cur = slen(arr[i]);
			write(1, arr[i], slen(arr[i]));
		}
		else
		{	
			cur = slen(arr[i]);
			write(1, arr[i], slen(arr[i]));
		}
	}
}
		

void parse(char *s)
{
	int words = ctwords(s);
	char **arr = (char **)malloc(sizeof(char *) * words);
	attach(arr, s);
	sortlen(arr, words);
	sortalp(arr, words);
	print(arr, words);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		parse(argv[1]);
	write(1, "\n", 1);
}
