#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct Node
{
    int value;
   // char operation;               
    struct Node* left;
    struct Node* right;
};

struct Node* createTree()
{
    struct Node* root = NULL;
    return root;
}

struct Node* createNode(int value)///
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left=node->right= NULL;
    return node;
}

struct Node* insert(struct Node* root, int value)
{
    if (root == NULL) {
        return createNode(value);
    }
    if (root->value > value){
        root->left=insert(root->left, value);
    } else if(root->value < value)
    {
        root->right = insert( root->right, value);
    }
    return root;
}
void print(struct Node* root){
    if (root == NULL){
        return;                                                               
    }
   // printf('1');
    print(root->left);
    printf("%d ", root->value);
    print(root->right);
}
struct Node* Remove(struct Node* root, int value)
{
    if (!root){
        return NULL;
    }
    if (root->value > value)
    {
        root->left = Remove(root->left, value);
    }
    if (root->value < value)
    {
        root->right = Remove(root->right, value);
    }
    if (root->value == value)
    {
        if (root->left == NULL)
        {
            struct Node* nd = root->right;
            free(root);
            return nd;
        } else if (root->right == NULL)
        {
            struct Node* nd = root->left;
            free(root);
            return nd;
        } 
        struct Node* nd = root->right;
        while (nd && nd->left != NULL)
        {
        nd = nd->left;
        }
        root->value=nd->value;
        root->right=Remove(root->right,nd->value); 
    }
    return root;
}

int Height(struct Node* root){      //
    unsigned int l, r;
    if(root != NULL){
        l = (root->left  != NULL) ? Height(root->left)  : 0;
        r = (root->right != NULL) ? Height(root->right) : 0;
        return ((l > r) ? l : r) + 1;
    }
}