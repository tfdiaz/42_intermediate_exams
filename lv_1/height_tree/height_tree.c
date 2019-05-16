#include <stdlib.h>

struct s_node {
	int value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root) {
	int max = 0;
	int height = 0;
	if (root == NULL)
		return 0;
	if (root->nodes == NULL)
		return 0;
	for (int i = 0; root->nodes[i] != NULL; i++) {
		height = height_tree(root->nodes[i]) + 1;
		if (height > max)
			max = height;
	}
	return max;
}
