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
  printf("%d %d\n", node->value1, node->value2);
}

void printLinkedList(Node * head){
  Node * node = head;
  printf("printing constructed linked list\n");
  while (node != NULL){
    printNode(node);
    node = node->next;
  }
}

//return the number of node/s removed, -1 when error occurs
int  removeNode(Node ** head, int value1_to_be_removed){
  if(*head == NULL){
    printf("Passed head node is NULL \n");
    return -1;
  }
  Node * node = *head;
  Node * previous_node=NULL;
  Node * temp_node;
  int node_removed=0;

  while(node != NULL){
    if(node->value1 == value1_to_be_removed){
      printf("removing node:\n");
      printNode(node);
      //this node needs to be removed
      if(previous_node == NULL){
	//this is the head
	temp_node = node;
	node = node->next;
	*head = node;
	free(temp_node);
      } else {
	previous_node->next = node->next;
	free(node);
	node = previous_node->next;
      }
      node_removed ++;
    }
    else{
      //move on to the next node
      previous_node = node;
      node = node->next;
    }
  }
  return node_removed;
}

int buildLinkedList(Node ** head, int size){

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
  *head = ptr;
  while(i < size){
    ptr->next = (Node *) malloc(sizeof(Node));
    ptr = ptr->next;
    scanf("%d %d", &(ptr->value1), &(ptr->value2));
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
  int value1_to_be_removed;
  while(input_good == 0){
    printf("how many nodes do you want in your linked list?\n");
    scanf("%d", &size);
    if (size > 0)
      input_good = 1;
    else
      printf("invalide input. Please give a positive number.\n");
  }
  buildLinkedList(&head,size);
  if (head == NULL)
    printf("head is NULL \n");
  printLinkedList(head);
  printf("Give me a node with value1 that you want to remove:\n ");
  scanf("%d", &value1_to_be_removed);
  removeNode(&head, value1_to_be_removed);
  printf("This is the linked list after removing node\n\n");
  printLinkedList(head);
  destroyLinkedList(head);
  return 0;
}
