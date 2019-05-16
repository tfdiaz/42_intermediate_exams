#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void) {
	struct s_queue *queue = (struct s_queue*)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

void enqueue(struct s_queue *queue, void *content) {
	if (queue == NULL)
		queue = init();
	struct s_node *new = (struct s_node*)malloc(sizeof(struct s_node));
	new->next = NULL;
	new->content = content;
	if (queue->first == NULL) {
		queue->first = new;
		queue->last = new;
	}
	else {
		queue->last->next = new;
		queue->last = new;
	}
}

void *dequeue(struct s_queue *queue) {
	if (queue == NULL)
		return NULL;
	if (queue->first == NULL)
		return NULL;
	struct s_node *node = queue->first;
	queue->first = queue->first->next;
	return node->content;
}

void *peek(struct s_queue *queue) {
	if (queue == NULL)
		return NULL;
	if (queue->first == NULL)
		return NULL;
	return queue->first->content;
}

int isEmpty(struct s_queue *queue) {
	if (queue == NULL)
		return 1;
	if (queue->first == NULL)
		return 1;
	return 0;
}
