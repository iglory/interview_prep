#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
  int value1;
  int value2;
  Node * next;
};

void printNode(Node * node){
  if (node == NULL)
    return;
  printf("%d %d", node->value1, node->value2);
}

void printLinkedList(Node * head){
  Node * node = head;
  printf("printing constructed linked list\n");
  while (node != NULL){
    printNode(node);
    node = node->next;
  }
}
int buildLinkedList(Node * head, int size){

  int i= 1 ;
  Node * ptr;
  if(size<=0){
    printf("input %d illegal, should be a positive size\n", size);
    return -1;
  }
  ptr = (Node *) malloc(sizeof(Node));
  if (ptr == NULL){
    printf("Not enough memory\n");
    return -1;
  }
  scanf("%d %d", &(ptr->value1), &(ptr->value2));
  head = ptr;
  while(i < size){
    scanf("%d %d", &(ptr->value1), &(ptr->value2));
    ptr->next = (Node *) malloc(sizeof(Node));
    ptr = ptr->next;
    if (ptr == NULL){
      printf("Not enough memory\n");
      return -1;
    } 
    i++;
  }
  ptr->next=NULL;
  return 0;
}

void   destroyLinkedList(Node * head){
  Node * tmp = head;
  Node * tmp_next;
  printf("destroying linked list\n");
  while(tmp != NULL){
    tmp_next = tmp->next;
    free(tmp);
    tmp = tmp_next;
  }
}

int main(){
  Node * head = NULL;
  int size;
  int input_good = 0;
  while(input_good == 0){
    printf("how many nodes do you want in your linked list?\n");
    scanf("%d", &size);
    if (size > 0)
      input_good = 1;
    else
      printf("invalide input. Please give a positive number.\n");
  }
  buildLinkedList(head,size);
  if (head == NULL)
    printf("head is NULL \n");
  printLinkedList(head);
  destroyLinkedList(head);
  return 1;
}
