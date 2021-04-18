/*
    Write a function that, given the root of a binary tree, returns the width of the tree, that is,
    the maximum number of nodes at any level
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct
{
    TreeNodePtr root;
} BinaryTree;

int maxWidth(TreeNodePtr root);
int getHeight(TreeNodePtr root);
void widthPreOrder(TreeNodePtr root, int total[], int level);
TreeNodePtr findOrInsert(BinaryTree bt, int d);
void inOrder(TreeNodePtr root);
void preOrder(TreeNodePtr root);
TreeNodePtr newTreeNode(int d);
void visit(TreeNodePtr node);

int main()
{
    FILE * in = fopen("numbst.txt", "r");

    BinaryTree bst;
    bst.root = NULL;

    int num;
    int width = 0;

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

    width = maxWidth(bst.root);
    printf("\nThe maximum width of the binary tree is %d\n\n", width);

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
} //end preOrder

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

//finds the maximum width of a binary tree using pre-order traversal
void widthPreOrder(TreeNodePtr root, int total[], int level)
{
    if (root != NULL)
    {
        total[level]++;
        widthPreOrder(root->left, total, level + 1);
        widthPreOrder(root->right, total, level + 1);
    }
}

//gets the height of the binary tree
int getHeight(TreeNodePtr root)
{
    if (root == NULL)
        return 0;
    //compute the height of each subtree
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);

    //use the larger subtree
    return (lheight > rheight)? (lheight + 1): (rheight + 1);
}

int maxWidth(TreeNodePtr root)
{
    int max = 0;
    int h = getHeight(root); //height of the binary tree
    int *count = (int *) calloc(h, sizeof(int)); //array for widthPreOrder method
    int level = 0;


    if (root == NULL)
        return 0;

    widthPreOrder(root, count, level);

    //loop to find the max width of the binary tree
    for (int i = 0; i < h; i++)
    {
        if (count[i] > max)
            max = count[i];
    }


    return max;
}
