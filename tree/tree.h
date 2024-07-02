#pragma once

#include <stdio.h>  
#include <stdlib.h>  
  
// 定义二叉树节点结构体  
typedef struct TreeNode {  
    int value;                
    struct TreeNode *left;     
    struct TreeNode *right;  
} TreeNode;  
  
// 创建新节点  
TreeNode* createNode(int value) {  
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));  
    if (node == NULL) {  
        printf("malloc failed\n");  
        exit(1);  
    }  
    node->value = value;  
    node->left = NULL;  
    node->right = NULL;  
    return node;  
}  
  
// 插入节点  
void insertNode(TreeNode **root, int value) {  
    if (*root == NULL) {  
        *root = createNode(value);  
    } else {  
        printf("node exit\n");  
    }  
}  
  
// 前序遍历二叉树  
void preorderTraversal(TreeNode *root) {  
    if (root == NULL) {  
        return;  
    }  
    printf("%d ", root->value);  
    preorderTraversal(root->left);  
    preorderTraversal(root->right);  
}  
  
// 释放二叉树内存  
void freeTree(TreeNode *root) {  
    if (root == NULL) {  
        return;  
    }  
    freeTree(root->left);  
    freeTree(root->right);  
    free(root);  
}  
