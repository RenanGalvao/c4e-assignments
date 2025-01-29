#include "linked-tree-map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TreeMapIter functions */
struct TreeMapEntry *__TreeMapIter_next(struct TreeMapIter *self) {
    struct TreeMapEntry *retval;

    retval = self->__current;
    if(self->__current != NULL)
        self->__current = self->__current->__next;

    return retval;
}

void __TreeMapIter_del(struct TreeMapIter *self) {
    free((void *)self);
}

/* TreeMap functions */
struct TreeMapIter *__TreeMap_iter(struct TreeMap *self) {
    struct TreeMapIter *p = malloc(sizeof(struct TreeMapIter));

    p->__current = self->__head;
    p->next = &__TreeMapIter_next;
    p->del = &__TreeMapIter_del;

    return p;
}

void __TreeMap_put(struct TreeMap *self, char *key, int value) {
    struct TreeMapEntry *cur, *left, *right;
    struct TreeMapEntry *old, *new;
    int cmp; 

    cur = self->__root;
    left = NULL;
    right = NULL;

    while (cur != NULL) {
        old = cur;

        if(strcmp(key, cur->key) == 0) {
            cur->value = value;
            return;
        } else if (strcmp(key, cur->key) < 0) {
            right = cur;
            cur = cur->__left;
        } else {
            left = cur;
            cur = cur->__right;
        }
    }

    new = malloc(sizeof(struct TreeMapEntry));
    new->key = malloc(strlen(key));
    strcpy(new->key, key);
    new->value = value;

    if(self->__head == NULL) {
        self->__head = new;
        self->__root = new;
        self->__count++;
        return;
    }

    __TreeMap_check(self, left, key, right);

    /* list insert */
    if(left == NULL) {
        new->__next = self->__head;
        self->__head = new;
    } else if (right == NULL) {
        left->__next = new;
    } else {
        left->__next = new;
        new->__next = right;
    }

    /* tree map insert */
    if(strcmp(key, old->key) < 0)
        old->__left = new;
    else
        old->__right = new;

    self->__count++;
}

int __TreeMap_get(struct TreeMap *self, char *key, int def) {
    struct TreeMapEntry *cur;
    int cmp;

    if(self == NULL || key == NULL || self->__root == NULL)
        return def;

    cur = self->__root;

    while (cur != NULL) {
        if(strcmp(key, cur->key) == 0) 
            return cur->value;
        else if (strcmp(key, cur->key) < 0) 
            cur = cur->__left;
        else 
            cur = cur->__right;
    }

    return def;
}

int __TreeMap_size(struct TreeMap *self) {
    return self->__count;
}

void __TreeMap_dump(struct TreeMap *self) {
    struct  TreeMapEntry *cur;

    printf("Object TreeMap count=%d\n", self->__count);
    for(cur = self->__head; cur != NULL; cur = cur->__next)
        printf("  %s=%d\n", cur->key, cur->value);

    printf("\n");
    __TreeMap_dump_tree(self->__root, 0);
}

void __TreeMap_dump_tree(struct TreeMapEntry *cur, int depth) {
    int i;
    if(cur == NULL)
        return;
    
    for(i = 0; i < depth; i++)
        printf("| ");

    printf("%s=%d\n", cur->key, cur->value);
    if(cur->__left != NULL)
        __TreeMap_dump_tree(cur->__left, depth + 1);
    if(cur->__right != NULL)
        __TreeMap_dump_tree(cur->__right, depth + 1);
}

void __TreeMap_del(struct TreeMap *self) {
    struct TreeMapEntry *cur, *next;
    
    cur = self->__head;
    while(cur) {
        free(cur->key);
        next = cur->__next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* Other functions */
void __TreeMap_check(struct TreeMap *self, struct TreeMapEntry *left, char *key, struct TreeMapEntry *right) {
    if(self->debug)
        printf("Check position %s < %s > %s\n", (left ? left->key : "0"), key, (right ? right->key : "0"));

    /* check our location in the linked list */
    if (left != NULL) {
        if (left->__next != right)
            printf("Fail left->__next != right\n");
    } else {
        if (self->__head != right)
            printf("Fail self->__head != right\n");
    }

    /* check our location in the tree */
    if (right != NULL && right->__left == NULL)
        /* OK */;
    else if (left != NULL && left->__right == NULL)
        /* OK */;
    else
        printf("Fail Neither right->__left nor left->__right are available\n");

}

struct TreeMap *TreeMap_new() {
    struct TreeMap *p = malloc(sizeof(struct TreeMap));

    p->__root = NULL;
    p->__head = NULL;
    p->__count = 0;
    p->debug = 1;

    p->put = &__TreeMap_put;
    p->get = &__TreeMap_get;
    p->size = &__TreeMap_size;
    p->dump = &__TreeMap_dump;
    p->del = &__TreeMap_del;
    p->iter = &__TreeMap_iter;

    return p;
}
