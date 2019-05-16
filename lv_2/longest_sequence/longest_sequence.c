#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void uts(struct s_node *node, int *ret)
{
	if (node == NULL)
		return;
	if (node->value == ret[0] + 1) {
		ret[1]++;
		if (ret[1] > ret[2])
			ret[2] = ret[1];
	}
	else
		ret[1] = 1;
	ret[0] = node->value;
	int prev = ret[0];
	int ct = ret[1];
	uts(node->right, ret);
	ret[0] = prev;
	ret[1] = ct;
	uts(node->left, ret);
}

int longest_sequence(struct s_node *node) {
	int arr[3];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;

	if (node) {
		arr[0] = node->value - 1;
	}
	uts(node, arr);
	return arr[2];
}
