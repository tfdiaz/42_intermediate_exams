#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};


void	reverse_tree(struct s_node *root)
{
	struct s_node *tmp;
	if (root == NULL)
		return;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
