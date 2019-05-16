#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *next;
};

int is_looping(struct s_node *node) {
	while (node != NULL) {
		if (node->value == 11235813)
			return 1;
		node->value = 11235813;
		node = node->next;
	}
	return 0;
}
