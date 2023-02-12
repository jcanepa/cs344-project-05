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
    if (head->next == NULL)
    {
        printf("[empty]\n");
        return;
    }

    struct node *node = head->next;
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
    struct node *head = node_alloc(0);

    struct node *n = node_alloc(10);
    llist_insert_head(&head, n);

    struct node *f = node_alloc(30);
    llist_insert_head(&head, f);

    llist_print(head);

    // command line parser
    for (const char **arg = argv + 1; *arg != argv[argc]; arg++)
    {
        // if (strcmp(*arg, "ih") == 0)
        // {
        //     printf("%s inserts %s at the head of the list\n", *arg, *(arg + 1));
        //     // struct node *n = node_alloc(*(arg + 1));
        //     // llist_insert_head(&head, n);
        // }
        // else if (strcmp(*arg, "it") == 0)
        // {
        //     printf("%s inserts %s to tail of the list\n", *arg, *(arg + 1));
        // }
        // else if (strcmp(*arg, "dh") == 0)
        // {
        //     printf("%s deletes head node\n", *arg);
        // }
        // else if (strcmp(*arg, "f") == 0)
        // {
        //     printf("%s frees the list\n", *arg);
        //     // node_free()
        // }
        // else if (strcmp(*arg, "p") == 0)
        // {
        //     printf("%s prints the list\n", *arg);
        //     llist_print(head);
        // }
    }

    return 0;
}
