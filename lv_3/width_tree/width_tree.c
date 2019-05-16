#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int uts(struct s_node *root, int *ret) {
	if (root == NULL)
		return 0;
	int left = uts(root->left, ret) + 1;
	int right = uts(root->right, ret) + 1;
	if (right + left - 1 > ret[0])
		ret[0] = right + left - 1;
	if (right > left)
		return right;
	else
		return left;
}

int width_tree(struct s_node *n) {
	int ret[1];
	ret[0] = 0;
	uts(n, ret);
	return ret[0];
}
