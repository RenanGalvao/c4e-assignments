#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

int main(void)
{
    /* Make sure we see all output up to an error */
    setvbuf(stdout, NULL, _IONBF, 0);

    struct Map *map = Map_new();

    printf("Map test\n");
    map->put(map, "z", 8);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "c", 4);
    map->dump(map);

    printf("size=%d\n", map->size(map));

    printf("z=%d\n", map->get(map, "z", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    map->del(map);
}
