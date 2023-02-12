#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void llist_insert_head(struct node **head, struct node *n)
{
    n->next = (*head);
    (*head) = n;
}

// struct node *llist_delete_head(struct node **head)
// {
//     return NULL;
// }

// void llist_insert_tail(struct node **head, struct node *n)
// {
//     return;
// }

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
        printf("%d -> ", node->value);
        node = node->next;
    }
}

// void llist_free(struct node **head)
// {
//     return;
// }

struct node *node_alloc(int value)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (NULL == n)
        perror("malloc");

    n->value = value;
    n->next = NULL;
    return n;
}

// void node_free(struct node *n)
// {
//     return;
// }

int main(int argc, char const *argv[])
{
    struct node *head = NULL;

    // parse command line
    for (const char **arg = argv + 1; *arg != argv[argc]; arg++)
    {
        if (strcmp(*arg, "ih") == 0)
        {
            // insert the next number on the command line at the head of the list
            int value = atoi(*(arg + 1));
            llist_insert_head(&head, node_alloc(value));
        }
        else if (strcmp(*arg, "it") == 0)
        {
            // insert the next number on the command line at the tail of the list
            printf("%s inserts %s to tail of the list (TODO)\n", *arg, *(arg + 1));
        }
        else if (strcmp(*arg, "dh") == 0)
        {
            // delete the node from the head of the list; does nothing if the list is empty
            if (head == NULL)
                continue;
            printf("%s deletes head node (TODO)\n", *arg);
        }
        else if (strcmp(*arg, "f") == 0)
        {
            // free the entire list
            printf("%s frees the list (TODO)\n", *arg);
            // node_free()
        }
        else if (strcmp(*arg, "p") == 0)
        {
            // print the list to standard output
            // printf("%s prints the list\n", *arg);
            llist_print(head);
        }
    }

    return 0;
}
