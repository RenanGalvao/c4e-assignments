#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Map *Map_new() {
    struct Map *p = malloc(sizeof(struct Map));

    p->__head = NULL;
    p->__tail = NULL;
    p->__count = 0;

    p->put = &__Map_put;
    p->get = &__Map_get;
    p->size = &__Map_size;
    p->dump = &__Map_dump;
    p->del = &__Map_del;

    p->iter = &__Map_iter;

    return p;
}

struct MapEntry * __Map_find(struct Map *self, char *key)
{
    if(self == NULL || key == NULL) return NULL;

    struct MapEntry *cur;

    for(cur = self->__head; cur != NULL; cur = cur->__next) {
        if(strcmp(key, cur->key) == 0)
            return cur;
    }

    return NULL;
}

void __Map_put(struct Map *self, char *key, int value) {
    if(self == NULL || key == NULL) return;

    struct MapEntry *old, *new;
    char *new_key;

    if (key == NULL) return;

    old = __Map_find(self, key);
    if( old != NULL) {
        old->value = value;
        return;
    }

    new = malloc(sizeof(struct MapEntry));
    new->key = malloc(strlen(key));
    strcpy(new->key, key);
    new->value = value;
    new->__next = NULL;

    if(self->__head == NULL)
        self->__head = new;

    if(self->__tail != NULL) {
        self->__tail->__next = new;
        new->__prev = self->__tail;
    }

    self->__tail = new;
    self->__count++;

}

int __Map_get(struct Map *self, char *key, int def) {
    if(self == NULL || key == NULL) return -1;

    struct MapEntry *mapEntry;

    mapEntry = __Map_find(self, key);
    if(mapEntry != NULL)
        return mapEntry->value;
    else
        return def;
}

int __Map_size(struct Map *self) {
    if (self == NULL) return -1;

    return self->__count;
}

void __Map_del(struct Map *self) {
    if (self == NULL) return;


    struct MapEntry *cur, *next;
    cur = self->__head;

    while(cur) {
        free(cur->key);
        next = cur->__next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

void __Map_dump(struct Map *self) {
    struct MapEntry *cur;
    printf("Object Map count=%d\n", self->__count);
    for(cur = self->__head; cur != NULL; cur = cur->__next)
        printf("  %s=%d\n", cur->key, cur->value);
}


struct MapIter *__Map_iter(struct Map *self) {
    struct MapIter *p = malloc(sizeof(struct MapIter));
    p->__current = self->__head;
    p->next = &__MapIter_next;
    p->del = &__MapIter_del;

    return p;
}

struct MapEntry *__MapIter_next(struct MapIter *self) {
    struct MapEntry *retval = self->__current;
    if(retval == NULL)
        return NULL;

    self->__current = retval->__next;

    return retval;
}

void __MapIter_del(struct MapIter *self) {
    free((void*)self);
}
