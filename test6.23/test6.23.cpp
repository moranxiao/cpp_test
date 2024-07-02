#include <iostream>

typedef struct node
{
    char data;
    struct node* lchild = nullptr,*rchild = nullptr;
} BTNode;


int Count(BTNode* root)
{
    if (root == nullptr) return 0;
    int count1 = Count(root->lchild);
    int count2 = Count(root->rchild);
    if (root->lchild != nullptr && root->rchild != nullptr)
        return count1 + count2 + 1;
    return count1 + count2;
}

int main()
{
    BTNode* root = new BTNode;
    root->lchild = new BTNode;
    root->rchild = new BTNode;
    root->lchild->lchild = new BTNode;
    root->lchild->rchild = new BTNode;
    root->rchild->rchild = new BTNode;
    root->lchild->rchild->rchild = new BTNode;
    root->lchild->rchild->rchild->rchild = new BTNode;
    root->lchild->lchild->lchild = new BTNode;
    root->lchild->lchild->rchild = new BTNode;

    std::cout << Count(root) << std::endl;
}
