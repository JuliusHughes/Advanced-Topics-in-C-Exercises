/*
    A binary tree consists of an integer key field and pointers to the left subtree, right subtree, and parent.
    Write the declarations required for building a tree and code to create an empty tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int data;
    struct Treenode *left, *right, *parent;
} TreeNode, *TreeNodePtr;

typedef struct
{
    TreeNodePtr root;
} BinaryTree;

TreeNodePtr buildTree(FILE * in);
void preOrder(TreeNodePtr node);
void inOrder(TreeNodePtr node);
void postOrder(TreeNodePtr node);
void visit(TreeNodePtr node);
void findParent(TreeNodePtr root, int x);

int main()
{
    FILE * in = fopen("btree.txt", "r");
    BinaryTree bt;

    bt.root = buildTree(in);

    printf("\nThe pre-order traversal is: ");
    preOrder(bt.root);
    printf("\nThe in-order traversal is: ");
    inOrder(bt.root);
    printf("\nThe post-order traversal is: ");
    postOrder(bt.root);

    printf("\nThe Parent for tree node 2 is: ");
    findParent(bt.root, 2);


    fclose(in);
    return 0;
}

static int count = 0;

TreeNodePtr buildTree(FILE * in)
{
    int num;
    fscanf(in, "%d", &num);

    if (num == 0)
        return NULL;

    TreeNodePtr p = malloc(sizeof(TreeNode));
    TreeNodePtr prev;


    if (count == 0)
        p->parent = NULL;
    else if (count == 1)
        p->parent = prev->left;
    else if (count == 2)
        p->parent = prev->right;

    p->data = num;

    count = 1;
    prev->left = p->left = buildTree(in);
    count = 2;
    prev->right = p->right = buildTree(in);
    return p;
}

void findParent(TreeNodePtr root, int x)
{
    if (root != NULL)
    {
        if (root->data == x)
        {
            TreeNodePtr parent = root->parent;
            printf("%d ", parent->data);
        }

        findParent(root->left, x);
        findParent(root->right, x);
    }
}

void visit(TreeNodePtr node)
{
    printf("%d ", node->data);
}

void preOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} //end preOrder

void inOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
} //end inOrder

void postOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
} //end postOrder
