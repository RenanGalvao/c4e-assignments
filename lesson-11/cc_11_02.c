#include "linked-tree-map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    struct TreeMap *map = TreeMap_new();
    struct TreeMapEntry *cur;
    struct TreeMapIter *iter;

    /* map->debug = 1 == 1; */

    printf("Testing TreeMap\n");
    map->put(map, "h", 42);
    map->put(map, "d", 8);
    map->put(map, "f", 5);
    map->put(map, "b", 123);
    map->dump(map);
    map->put(map, "k", 9);
    map->put(map, "m", 67);
    map->put(map, "j", 12);
    map->put(map, "f", 6);
    map->dump(map);

    printf("r=%d\n", map->get(map, "r", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    printf("\nIterate\n");
    iter = map->iter(map);
    while(1) {
        cur = iter->next(iter);
        if ( cur == NULL ) break;
        printf(" %s=%d\n", cur->key, cur->value);
    }
    iter->del(iter);

    map->del(map);
}
