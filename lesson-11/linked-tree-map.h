#ifndef LINKED_TREE_MAP_H
#define LINKED_TREE_MAP_H

struct TreeMapEntry {
    /* public */
    char *key;
    int value;

    /* private */
    struct TreeMapEntry *__next;
    struct TreeMapEntry *__left;
    struct TreeMapEntry *__right;
};

struct TreeMapIter {
    /* public */
    struct TreeMapEntry *(*next)(struct TreeMapIter *self);
    void (*del)(struct TreeMapIter *self);

    /* private */
    struct TreeMapEntry *__current;
};

struct TreeMap {
    /* public */
    void (*put)(struct TreeMap *self, char *key, int value);
    int (*get)(struct TreeMap *self, char *key, int def);
    int (*size)(struct TreeMap *self);
    void (*dump)(struct TreeMap *self);
    void (*del)(struct TreeMap*self);
    struct TreeMapIter *(*iter)(struct TreeMap *self);
    int debug;

    /* private */
    struct TreeMapEntry *__root;
    struct TreeMapEntry *__head;
    int __count;
};

/* TreeMapIter functions */
struct TreeMapEntry *__TreeMapIter_next(struct TreeMapIter *self);
void __TreeMapIter_del(struct TreeMapIter *self);

/* TreeMap functions */
struct TreeMapIter *__TreeMap_iter(struct TreeMap *self);
void __TreeMap_put(struct TreeMap *self, char *key, int value);
int __TreeMap_get(struct TreeMap *self, char *key, int def);
int __TreeMap_size(struct TreeMap *self);
void __TreeMap_dump(struct TreeMap *self);
void __TreeMap_dump_tree(struct TreeMapEntry *cur, int depth);
void __TreeMap_del(struct TreeMap *self);

/* Other functions */
void __TreeMap_check(struct TreeMap *self, struct TreeMapEntry *left, char *key, struct TreeMapEntry *right);
struct TreeMap *TreeMap_new();


#endif /* LINKED_TREE_MAP_H */
