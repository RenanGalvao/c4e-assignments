#include <stdio.h>
#include <stdlib.h>

struct lnode {
  int value;
  struct lnode *next;
};

struct list {
  struct lnode *head;
  struct lnode *tail;
};

int main() {
  void list_add();
  void list_remove();
  void list_dump();
  struct lnode *list_find();

  struct list mylist;
  struct lnode *mynode;

  mylist.head = NULL;
  mylist.tail = NULL;

  list_add(&mylist, 10);
  list_add(&mylist, 20);
  list_add(&mylist, 30);
  list_dump(&mylist);

  list_remove(&mylist, 42);

  list_remove(&mylist, 10);
  list_dump(&mylist);

  list_remove(&mylist, 30);
  list_dump(&mylist);

  list_add(&mylist, 40);
  list_dump(&mylist);
}

void list_add(lst, value) struct list *lst;
int value;
{
  struct lnode *new = (struct lnode *)malloc(sizeof(struct lnode));
  new->value = value;
  new->next = NULL;

  /* first time */
  if (lst->head == NULL)
    lst->head = new;

  /* update old list last */
  if (lst->tail != NULL)
    lst->tail->next = new;

  lst->tail = new;
}

void list_remove(lst, value) struct list *lst;
int value;
{
  struct lnode *prev, *cur, *next;
  prev = NULL;
  next = lst->head->next;
  for (cur = lst->head; cur != NULL; cur = cur->next) {
    if (cur->value == value) {
      /* head */
      if (prev == NULL)
        lst->head = cur->next;
      /* tail */
      else if (next == NULL) {
        lst->tail = prev;
        lst->tail->next = NULL;
      }
      /* in the middle*/
      else
        prev->next = next;

      free(cur);
      break;
    }

    prev = cur;
    next = cur->next ? cur->next->next : NULL;
  }
}

struct lnode *list_find(lst, value)
struct list *lst;
int value;
{
  struct lnode *cur;
  for (cur = lst->head; cur != NULL; cur = cur->next)
    if (cur->value == value)
      return cur;
  return NULL;
}

void list_dump(lst) struct list *lst;
{
  struct lnode *cur;
  printf("\nDump:\n");
  for (cur = lst->head; cur != NULL; cur = cur->next)
    printf("  %d\n", cur->value);
}
