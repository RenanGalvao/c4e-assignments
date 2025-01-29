#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode
{
    char *text;
    struct lnode *next;
};

struct pylist
{
    struct lnode *head;
    struct lnode *tail;
    int count;
};

/* constructor - lst = list() */
struct pylist *pylist_new()
{
    struct pylist *p = malloc(sizeof(struct pylist));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;

    return p;
}

/* destructor - del(lst) */
void pylist_del(struct pylist *self)
{
    struct lnode *cur, *next;
    cur = self->head;
    while(cur)
    {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

int pylist_len(const struct pylist *self)
{
    return self->count;
}

void pylist_append(struct pylist *self, char *str)
{
    struct lnode *new = malloc(sizeof(struct lnode));
    new->next = NULL;
    new->text = malloc(strlen(str));
    strcpy(new->text, str);

    if(self->head == NULL)
        self->head = new;

    if(self->tail != NULL)
        self->tail->next = new;

    self->tail = new;
    self->count++;
}

int pylist_index(const struct pylist *self, char *str)
{
    int index = 0;
    struct lnode *cur;
    cur = self->head;

    while(cur)
    {
        if(strcmp(cur->text, str) == 0)
            return index;
        cur = cur->next;
        index++;
    }

    return -1;
}

void pylist_print(const struct pylist *self)
{
    struct lnode *cur;
    cur = self->head;

    printf("[");
    while(cur)
    {
        printf("'%s'", cur->text);
        if(cur->next != NULL)
            printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0); /* internal */
    
    struct pylist *lst = pylist_new();
    pylist_append(lst, "Hello world");
    pylist_print(lst);

    pylist_append(lst, "Catch phrase");
    pylist_print(lst);

    pylist_append(lst, "Brian");
    pylist_print(lst);

    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? = %d\n", pylist_index(lst, "Brian"));
    printf("Bob? = %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
}
