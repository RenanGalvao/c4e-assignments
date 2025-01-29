#include "hash-map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0); /* internal */

    struct HashMap *map = HashMap_new();
    struct HashMapEntry *cur;
    struct HashMapIter *iter;

    printf("Testing HashMap\n");
    map->put(map, "z", 8);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "c", 4);
    map->dump(map);

    printf("size=%d\n", map->size(map));

    printf("z=%d\n", map->get(map, "z", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    printf("\nIterate\n");
    iter = map->iter(map);
    while(1) {
        cur = iter->next(iter);
        if(cur == NULL) break;
        printf("  %s=%d\n", cur->key, cur->value);
    }
    iter->del(iter);
    map->del(map);
}
