#include <stdio.h>
#include <limits.h>

typedef struct TreeNode {  
    char value;                
    struct TreeNode *left;     
    struct TreeNode *right;  
} TreeNode;

char find(TreeNode* root) {  
    if (root == NULL) {  
        return CHAR_MAX;  
    }  
    char min = root->value;   
    if (root->left != NULL) {  
        char lmin = find(root->left);  
        if (lmin < min) {  
            min = lmin;  
        }  
    }  
    if (root->right != NULL) {  
        char rmin = find(root->right);  
        if (rmin < min) {  
            min = rmin;  
        }  
    }  
    return min;  
}  