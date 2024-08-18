#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int num;
    struct Node *next;
};

struct Stack
{
    struct Node *front;
};

struct Stack *create_stack()
{
    struct Stack *st = malloc(sizeof(struct Stack));
    st->front = NULL;
    return st;
}

struct Node *create_node(int a)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->num = a;
    return node;
}

int pop(struct Stack *st)
{
    if (st->front == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int temp = st->front->num;
    struct Node *curnode = st->front;
    st->front = curnode->next;
    free(curnode);
    return temp;
}

void push(struct Stack *st, int num)
{
    if (st->front == NULL)
    {
        st->front = create_node(num);
    }
    struct Node *curnode = st->front;
    st->front = create_node(num);
    st->front->next = curnode;
}

bool is_empty(struct Stack *st)
{
    return (st->front == NULL);
}

void destroy_node(struct Node *n)
{
    if (n)
    {
        destroy_node(n->next);
    }
    free(n);
}

void destroy(struct Stack *st)
{
    destroy_node(st->front);
    free(st);
}

int length(struct Stack *st)
{
    if (st->front == NULL)
    {
        return 0;
    }
    int len = 0;
    struct Node *node = st->front;
    while (node->next != NULL)
    {
        node = node->next;
        len = len + 1;
    }
    return len;
}

int main()
{
    struct Stack *st = create_stack();
    push(st, 1);
    push(st, 2);
    pop(st);
    printf("%d", length(st));
    destroy(st);
}