#ifndef HASH_MAP_H
#define HASH_MAP_H
#define HASH_MAP_SIZE 8

struct HashMapEntry {
    char *key; /* public */
    int value; /* public */
    struct HashMapEntry *__prev;
    struct HashMapEntry *__next;
};

struct HashMapIter {
    int __bucket;
    struct HashMap *__map;
    struct HashMapEntry *__current;

    struct HashMapEntry *(*next)(struct HashMapIter *self);
    void (*del)(struct HashMapIter *self);
};

struct HashMap {
    /* attributes */
    int __buckets;
    struct HashMapEntry *__heads[HASH_MAP_SIZE];
    struct HashMapEntry *__tails[HASH_MAP_SIZE];
    int __count;

    /* Methods */
    void (*put)(struct HashMap *self, char *key, int value);
    int (*get)(struct HashMap *self, char *key, int def);
    int (*size)(struct HashMap *self);
    void (*dump)(struct HashMap *self);
    void (*del)(struct HashMap *self);

    struct HashMapIter *(*iter)(struct HashMap *self);
};

struct HashMap *HashMap_new();
struct HashMapEntry *__HashMap_find(struct HashMap *self, char *key);

void __HashMap_put(struct HashMap *self, char *key, int value);
int __HashMap_get(struct HashMap *self, char *key, int def);
int __HashMap_size(struct HashMap *self);
void __HashMap_del(struct HashMap *self);
void __HashMap_dump(struct HashMap *self);
struct HashMapIter *__HashMap_iter(struct HashMap *self);

struct HashMapEntry *__HashMapIter_next(struct HashMapIter *self);
void __HashMapIter_del(struct HashMapIter *self);
int getBucket(char *str, int buckets);

#endif /* HASH_MAP_H */
