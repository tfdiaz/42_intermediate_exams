#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	while (lst1 != NULL)
	{
		struct s_node *tmp = lst2;
		while (tmp != NULL)
		{
			if (tmp == lst1)
				return tmp;
			tmp = tmp->next;
		}
		lst1 = lst1->next;
	}
	return NULL;
}
