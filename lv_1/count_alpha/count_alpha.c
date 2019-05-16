#include <stdio.h>

void parse(char *s)
{
	int arr[127];
	int ct[127];
	for (int i = 0; i < 127; i++)
	{
		arr[i] = 0;
		ct[i] = 0;
	}
	for (int i = 0; s[i] != '\0'; i++)
	{
		char c = s[i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c >= 'a' && c <= 'z')
		{
			int i;
			for (i = 0; i < 127; i++)
			{
				if (arr[i] == 0 || arr[i] == (int)c)
					break;
			}
			arr[i] = (int)c;
			ct[i]++;
		}
	}
	for (int i = 0; i < 127; i++)
	{
		if (arr[i] == 0)
			break;
		else if (i > 0)
			printf(", %i%c", ct[i], (char)arr[i]);
		else
			printf("%i%c", ct[i], (char)arr[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		parse(argv[1]);
	printf("\n");
}
