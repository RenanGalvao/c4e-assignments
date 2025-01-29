#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
  char *key;
  char *value;
  struct dnode *next;
};

struct pydict {
  struct dnode *head;
  struct dnode *tail;
  int count;
};

/* constructor - dct = dict() */
struct pydict *pydict_new() {
  struct pydict *p = malloc(sizeof(struct pydict));
  p->head = NULL;
  p->tail = NULL;
  p->count = 0;

  return p;
}

/* destructor - del(dct) */
void pydict_del(struct pydict *self) {
  struct dnode *cur, *next;
  cur = self->head;
  while (cur) {
    free(cur->key);
    free(cur->value);
    next = cur->next;
    free(cur);
    cur = next;
  }
  free(self);
}

int pydict_len(const struct pydict *self) { return self->count; }

struct dnode *pydict_find(const struct pydict *self, char *key) {
  struct dnode *cur, *next;
  cur = self->head;
  while (cur) {
    if (strcmp(cur->key, key) == 0)
      return cur;
    cur = cur->next;
  }

  return NULL;
}

char *pydict_get(const struct pydict *self, char *key) {
  struct dnode *res = pydict_find(self, key);
  if (res != NULL)
    return res->value;
  return "(null)";
}

void pydict_put(struct pydict *self, char *key, char *value) {
  struct dnode *res = pydict_find(self, key);
  if (res != NULL) {
    res->value = realloc(res->value, strlen(value));
    strcpy(res->value, value);
  } else {
    struct dnode *new = malloc(sizeof(struct dnode));
    new->key = malloc(strlen(key));
    strcpy(new->key, key);
    new->value = malloc(strlen(value));
    strcpy(new->value, value);
    new->next = NULL;

    if (self->head == NULL)
      self->head = new;

    if (self->tail != NULL)
      self->tail->next = new;

    self->tail = new;
    self->count++;
  }
}

void pydict_print(const struct pydict *self) {
  struct dnode *cur;
  cur = self->head;

  printf("{");
  while (cur) {
    printf("'%s': '%s'", cur->key, cur->value);
    if (cur->next != NULL)
      printf(", ");
    cur = cur->next;
  }
  printf("}\n");
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  struct dnode *cur;
  struct pydict *dct = pydict_new();

  pydict_put(dct, "z", "Catch phrase");
  pydict_print(dct);

  pydict_put(dct, "z", "W");
  pydict_print(dct);

  pydict_put(dct, "y", "B");
  pydict_put(dct, "c", "C");
  pydict_put(dct, "a", "D");
  pydict_print(dct);
  printf("Length =%d\n", pydict_len(dct));

  printf("z=%s\n", pydict_get(dct, "z"));
  printf("x=%s\n", pydict_get(dct, "x"));

  printf("\nDump\n");
  for (cur = dct->head; cur != NULL; cur = cur->next)
    printf("%s=%s\n", cur->key, cur->value);

  pydict_del(dct);
}
