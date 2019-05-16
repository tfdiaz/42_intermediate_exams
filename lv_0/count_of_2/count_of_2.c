#include <stdlib.h>

int count_of_2(int n)
{
	int ct = 0;
	while (n > 1)
	{
		int tmp = n;
		while (tmp > 0)
		{
			if (tmp % 10 == 2)
				ct++;
			tmp /= 10;
		}
		n--;
	}
	return ct;
}
