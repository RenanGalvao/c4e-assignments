#include "linked-tree-map.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 100

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    struct TreeMap *map = TreeMap_new();
    struct TreeMapEntry *cur;
    struct TreeMapIter *iter;

    char *maxkey;
    char word[LINE_SIZE];
    int i, j;
    int count, maxvalue;

    map->debug = 0;

    while(scanf("%s", word) != EOF) {
        for(i = j = 0; word[i] != '\0'; i++) {
            if( !isalpha(word[i]))
               continue;
            word[j++] = tolower(word[i]);
        }
        word[j] = '\0';

        count = map->get(map, word, 0);
        map->put(map, word, count + 1);
    }

    maxkey = NULL;
    maxvalue = -1;
    iter = map->iter(map);
    while(1) {
        cur = iter->next(iter);
        if(cur == NULL)
            break;
        if(maxkey == NULL || cur->value > maxvalue) {
            maxkey = cur->key;
            maxvalue = cur->value;
        }
    }
    iter->del(iter);

    printf("\n%s %d\n", maxkey, maxvalue);
    map->del(map);
}
