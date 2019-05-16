#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void convert(struct s_node *root, struct s_node **head)
{
	if (root == NULL)
		return;
	static struct s_node *prev = NULL;
	convert(root->left, head);
	if (prev == NULL)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convert(root->right, head);
}

void relink(struct s_node *root)
{
	struct s_node *head = root;
	while (root->right != NULL)
	{
		root = root->right;
	}
	head->left = root;
	root->right = head;
}

struct s_node *convert_bst(struct s_node *bst)
{
	if (bst == NULL)
		return NULL;
	struct s_node *head;
	convert(bst, &head);
	relink(head);
	return head;
}
