#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void llist_insert_head(struct node **head, struct node *n)
{
    return;
}

struct node *llist_delete_head(struct node **head)
{
    return NULL;
}

void llist_insert_tail(struct node **head, struct node *n)
{
    return;
}

void llist_print(struct node *head)
{
    printf("[empty]");
}

void llist_free(struct node **head)
{
    return;
}

struct node *node_alloc(int value)
{
    return NULL;
}

void node_free(struct node *n)
{
    return;
}

int main(int argc, char const *argv[])
{
    // command line parser
    for (char **arg = argv + 1; *arg != argv[argc]; arg++)
    {
        if (strcmp(*arg, "ih") == 0)
        {
            printf("%s inserts %s at the head of the list\n", *arg, *(arg + 1));
        }
        else if (strcmp(*arg, "it") == 0)
        {
            printf("%s inserts %s to tail of the list\n", *arg, *(arg + 1));
        }
        else if (strcmp(*arg, "dh") == 0)
        {
            printf("%s deletes head node\n", *arg);
        }
        else if (strcmp(*arg, "f") == 0)
        {
            printf("%s frees the list\n", *arg);
        }
        else if (strcmp(*arg, "p") == 0)
        {
            printf("%s prints the list\n", *arg);
        }
    }

    // node_alloc()
    // node_free()
    // llist_print()
    // llist_insert_head()
    // ...

    // struct node *head;

    return 0;
}
