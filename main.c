#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node * head;
};

void print_list(struct LinkedList *list) {
  struct Node * tempRoot = list->head;
  while (tempRoot != NULL) {
    printf("Data: %d\n", tempRoot->data);
    tempRoot = tempRoot->next;
  }
}

struct LinkedList * create_list(int data) {
  struct LinkedList * list = malloc(sizeof(struct LinkedList));
  list->head = malloc(sizeof(struct Node));
  list->head->data = data;
  return list;
}

void add_node(struct LinkedList *list, int data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  // Traverse the list
  struct Node *tempRoot = list->head;
  while (tempRoot->next != NULL) {
    tempRoot = tempRoot->next;
  }
  tempRoot->next = node;
}

int main() {
  printf("Hello World!\n");

  struct LinkedList *list;

  char contents[10];
  FILE *file_pointer = fopen("nodes.txt", "r");

  while(fgets(contents, 10, file_pointer)) {
    if (list == NULL) {
      list = create_list(atoi(contents));
    } else {
      add_node(list, atoi(contents));
    }
    printf("Adding: %d to Linked List\n", atoi(contents));
  }
  
  print_list(list);
}