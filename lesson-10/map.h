#ifndef MAP_H
#define MAP_H

struct MapEntry {
    char *key; /* public */
    int value; /* public */
    struct MapEntry *__prev;
    struct MapEntry *__next;
};

struct MapIter {
    struct MapEntry *__current;

    struct MapEntry *(*next)(struct MapIter *self);
    void (*del)(struct MapIter *self);
};

struct Map {
    struct MapEntry *__head;
    struct MapEntry *__tail;
    int __count;

    /* Methods */
    void (*put)(struct Map *self, char *key, int value);
    int (*get)(struct Map *self, char *key, int def);
    int (*size)(struct Map *self);
    void (*dump)(struct Map *self);
    void (*del)(struct Map *self);

    struct MapIter *(*iter)(struct Map *self);
};

struct Map *Map_new();
struct MapEntry *__Map_find(struct Map *self, char *key);

void __Map_put(struct Map *self, char *key, int value);
int __Map_get(struct Map *self, char *key, int def);
int __Map_size(struct Map *self);
void __Map_del(struct Map *self);
void __Map_dump(struct Map *self);
struct MapIter *__Map_iter(struct Map *self);

struct MapEntry *__MapIter_next(struct MapIter *self);
void __MapIter_del(struct MapIter *self);

#endif /* MAP_H */
