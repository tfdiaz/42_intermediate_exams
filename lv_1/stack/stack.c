#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void) {
	struct s_stack *ret = (struct s_stack *)malloc(sizeof(struct s_stack));
	ret->top = NULL;
	return ret;
}

void *pop(struct s_stack *stack) {
	if (stack == NULL)
		return NULL;
	if (stack->top == NULL)
		return NULL;
	struct s_node *tmp = stack->top;
	stack->top = tmp->next;
	return tmp->content;
}

void push(struct s_stack *stack, void *content) {
	if (stack == NULL)
		stack = init();
	struct s_node *new = (struct s_node*)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (stack->top == NULL)
		stack->top = new;
	else {
		new->next = stack->top;
		stack->top = new;
	}
}

void *peek(struct s_stack *stack) {
	if (stack == NULL)
		return NULL;
	if (stack->top == NULL)
		return NULL;
	return stack->top->content;
}

int isEmpty(struct s_stack *stack) {
	if (stack == NULL)
		return 1;
	if (stack->top == NULL)
		return 1;
	return 0;
}
