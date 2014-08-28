#include<stdio.h>

typedef struct node Node;

struct node{
  int data;
  Node * left;
  Node * right;
}Node;


//TODO: need to create binary tree for a given size
void create_binary_tree(&root, size){

}
void inorderprint(Node * root){
  
  while(root != NULL){
    inorderprint(root->left);
    printf("%d\n",root->data);
    inorderprint(root->right);
  }
  return ;
}
void destroy_binary_tree(Node * root){

  while(root != NULL){
    destroy_binary_tree(root->left);
    destroy_binary_tree(root->right);
    free(root);
  }
  return;
}
int main(){
  Node *root;
  int size;
  printf("Please type in how many nodes do you want in your BST:\n");
  scanf("%d", &size);
  create_binary_tree(&root, size);
  inorderprint(root);
  destroy_binary_tree(root);//it should be a post order travesal of the BST here
}
