#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void llist_insert_head(struct node **head, struct node *n)
{
    n->next = (*head);
    (*head) = n;
}

struct node *llist_delete_head(struct node **head)
{
    if (*head == NULL)
        return NULL;

    // remove head node and return its pointer
    struct node *n = (*head);
    (*head) = n->next;
    return n;
}

void llist_insert_tail(struct node **head, struct node *n)
{
    if (*head == NULL)
    {
        (*head) = n;
        return;
    }

    struct node *node = (*head);
    while (node->next != NULL)
        node = node->next;

    node->next = n;
    return;
}

void llist_print(struct node *head)
{
    if (head == NULL)
    {
        printf("[empty]\n");
        return;
    }

    struct node *node = head;
    while (node != NULL)
    {
        printf("%d", node->value);
        printf((node->next != NULL) ? " -> " : "\n");
        node = node->next;
    }
}

void llist_free(struct node **head)
{
    if (head == NULL)
        return;

    struct node *node = (*head);
    struct node *next;

    while (node != NULL)
    {
        next = node->next;
        node_free(node);
        node = next;
    }

    *head = NULL;
}

void node_free(struct node *n)
{
    free(n);
}

struct node *node_alloc(int value)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (NULL == n)
    {
        perror("malloc");
        return NULL;
    }

    n->value = value;
    n->next = NULL;
    return n;
}

int main(int argc, char const *argv[])
{
    struct node *head = NULL;

    // for each user provided argument, parse
    for (const char **arg = argv + 1; *arg != argv[argc]; arg++)
    {
        if (strcmp(*arg, "ih") == 0)
        {
            // insert following arg at head of list
            int value = atoi(*(arg + 1));
            llist_insert_head(
                &head, node_alloc(value));
        }
        else if (strcmp(*arg, "it") == 0)
        {
            // insert following arg at tail of list
            int value = atoi(*(arg + 1));
            llist_insert_tail(
                &head, node_alloc(value));
        }
        else if (strcmp(*arg, "dh") == 0)
        {
            // delete node from head of list; do nothing if list is empty
            if (head == NULL)
                continue;
            llist_delete_head(&head);
        }
        else if (strcmp(*arg, "f") == 0)
        {
            // free the entire list
            llist_free(&head);
        }
        else if (strcmp(*arg, "p") == 0)
        {
            // print list to standard output
            llist_print(head);
        }
    }
    return 0;
}
