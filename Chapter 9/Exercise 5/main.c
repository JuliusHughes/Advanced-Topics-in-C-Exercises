#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct
{
    TreeNodePtr root;
} BinaryTree;

TreeNodePtr findOrInsert(BinaryTree bt, int d);
void inOrder(TreeNodePtr root);
void preOrder(TreeNodePtr root);
TreeNodePtr newTreeNode(int d);
void visit(TreeNodePtr node);
TreeNodePtr deleteRootSuccessor(TreeNodePtr root);
TreeNodePtr deleteRootPredecessor(TreeNodePtr root);

int main()
{
    FILE * in = fopen("numbst.txt", "r");

    BinaryTree bst, bst2;
    bst.root = NULL;

    int num;

    fscanf(in, "%d", &num);
    while (num != 0)
    {
        if (bst.root == NULL)
            bst.root = newTreeNode(num);
        else
        {
            TreeNodePtr node = findOrInsert(bst, num);
        }
        fscanf(in, "%d", &num);
    }

    printf("\nThe in-order traversal is: ");
    inOrder(bst.root);
    printf("\nThe pre-order traversal is: ");
    preOrder(bst.root);

    /*TreeNodePtr node2 = deleteRootSuccessor(bst.root);
    printf("\n\nThe in-order traversal is: ");
    inOrder(node2);
    printf("\nThe pre-order traversal is: ");
    preOrder(node2);*/

    TreeNodePtr node3 = deleteRootPredecessor(bst.root);
    printf("\n\nThe in-order traversal is: ");
    inOrder(node3);
    printf("\nThe pre-order traversal is: ");
    preOrder(node3);

    fclose(in);

    return 0;
}

void visit(TreeNodePtr node)
{
    printf("%d ", node->data);
}

void inOrder(TreeNodePtr root)
{
    void visit(TreeNodePtr);
    if (root != NULL)
    {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
} //end inOrder

void preOrder(TreeNodePtr root)
{
    void visit(TreeNodePtr);
    if (root != NULL)
    {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
} //end inOrder

TreeNodePtr newTreeNode(int d)
{
    TreeNodePtr p = malloc(sizeof(TreeNode));
    p->data = d;
    p->left = p->right = NULL;
    return p;
}

TreeNodePtr findOrInsert(BinaryTree bt, int d)
{
    //searches for d; if found, return pointer to node containing d
    //else insert a node containing d and return pointer to new node

    TreeNodePtr newTreeNode(int);
    if (bt.root == NULL)
        return newTreeNode(d);
    TreeNodePtr curr = bt.root;
    while (d != curr->data)
    {
        if (curr->data > d)
        { //try left
            if (curr->left == NULL)
                return curr->left = newTreeNode(d);
            curr = curr->left;
        }
        else
        { //try right
            if (curr->right == NULL)
                return curr->right = newTreeNode(d);
            curr = curr->right;
        }
    }
    //d is in the tree; return pointer to the node
    return curr;
} //end findOrInsert

TreeNodePtr deleteRootSuccessor(TreeNodePtr root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root->left;
    if (root->left == NULL)
        return root->right;

    TreeNodePtr curr = malloc(sizeof(TreeNode));
    curr = root->right; //new root of Binary Search Tree
    TreeNodePtr leftCurr = curr->left; //original left subtree of curr
    TreeNodePtr rightCurr = curr->right; //root's right subtree

    while (rightCurr->left != NULL)
    {
        rightCurr = rightCurr->left;
    }

    curr->left = root->left;
    rightCurr->left = leftCurr;

    return curr;
}

TreeNodePtr deleteRootPredecessor(TreeNodePtr root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root->right;


    TreeNodePtr leftTree = root->left;
    TreeNodePtr curr = malloc(sizeof(TreeNode));
    TreeNodePtr leftTree2 = leftTree->left;

    if (leftTree->right == NULL)
    {
        curr = leftTree; //new root of binary search tree
        curr->left = leftTree2;
    }
    else
    {
        while (leftTree->right != NULL)
        {
            leftTree = leftTree->right;
        }
        curr = leftTree; //new root of binary search tree
        curr->left = root->left;
    }
    curr->right = root->right;


    return curr;
}
