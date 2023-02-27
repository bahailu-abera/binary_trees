#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * struct list_s - list node
 *
 * @data: the value stored at the node
 * @next: a pointer to the next node in the list
 *
 */
typedef struct list_s {
	binary_tree_t *data;
	struct list_s *next;
} list_t;

/**
 * struct queue_s - a queue datastructure
 *
 * @front: a pointer to the front node of the queue
 * @rear: a pointer to the rear node of the queue
 *
 */
typedef struct queue_s {
	list_t *front;
	list_t *rear;
} queue_t;

queue_t *create_queue()
{
        queue_t *q = malloc(sizeof(queue_t));

	if (q == NULL) {
                fprintf(stderr, "Failed to allocate memory for queue.\n");
                exit(EXIT_FAILURE);
        }

        q->front = NULL;
        q->rear = NULL;

        return (q);
}

int is_empty(queue_t *q)
{
        return (q->front == NULL);
}

void enqueue(queue_t *q, binary_tree_t *node)
{
        list_t *new_list_node = malloc(sizeof(list_t));

        if (new_list_node == NULL) {
                fprintf(stderr, "Failed to allocate memory for list node.\n");
                exit(EXIT_FAILURE);
        }

        new_list_node->data = node;
        new_list_node->next = NULL;

        if (is_empty(q)) {
                q->front = new_list_node;
                q->rear = new_list_node;
        } else {
                q->rear->next = new_list_node;
                q->rear = new_list_node;
        }
}

binary_tree_t *dequeue(queue_t *q)
{
	list_t *list_node;
	binary_tree_t *node;

        if (is_empty(q)) {
                fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
                exit(EXIT_FAILURE);
        }

        list_node = q->front;
        node = list_node->data;

        if (q->front == q->rear) {
                q->front = NULL;
                q->rear = NULL;
        } else {
                q->front = q->front->next;
        }

        free(list_node);

        return node;
}

void delete(queue_t *q)
{
        while (!is_empty(q)) {
                dequeue(q);
        }

        free(q);
}
