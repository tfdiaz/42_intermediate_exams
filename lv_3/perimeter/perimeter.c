#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void prt_left(struct s_node *root) {
	if (root && (root->right != NULL || root->left != NULL)) {
		printf(" %i", root->value);
		prt_left(root->left);
	}
}

void prt_leaves(struct s_node *root) {
	if (root) {
		prt_leaves(root->left);
		prt_leaves(root->right);
		if (root->left == NULL && root->right == NULL)
			printf(" %i", root->value);
	}
}

void prt_right(struct s_node *root) {
	if (root) {
		prt_right(root->right);
		if (root->left != NULL || root->right != NULL)
			printf(" %i", root->value);
	}
}

void perimeter(struct s_node *root) {
	if (root) {
		printf("%i", root->value);
		prt_left(root->left);
		prt_leaves(root->left);
		prt_leaves(root->right);
		prt_right(root->right);
		printf("\n");
	}
}
