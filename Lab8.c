#include <stdio.h>
#include <stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node *create(){
node *temp;
printf("Enter data: ");
temp=(node*)malloc(sizeof(node));
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
return temp;
}

void insert(node *root,node *temp){
if (temp->data<root->data)
    {
    if (root->left!=NULL)
        insert(root->left,temp);
    else
        root->left=temp;
    }
if (temp->data>root->data){
    if (root->right!=NULL)
        insert(root->right,temp);
    else
        root->right=temp;
}
}

void inorder(node *root){
if (root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
}

void preorder(node *root){
if (root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
}

void postorder(node *root){
if (root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
}

void main(){
char ch;
node *root=NULL,*temp;
while(1)
{
    int choice;
    printf("Menu\n");
    printf("1. Insert element\n");
    printf("2. Preorder\n");
    printf("3. Postorder\n");
    printf("4. Inorder\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch (choice) {
            case 1:
                temp = create();
                if (root == NULL) {
                    root = temp;
                } else {
                    insert(root, temp);
                }
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
}
}
}
