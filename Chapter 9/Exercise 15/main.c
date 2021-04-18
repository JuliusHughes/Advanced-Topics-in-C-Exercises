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

TreeNodePtr findOrInsert(BinaryTree bt, int d);
void inOrder(TreeNodePtr root);
void preOrder(TreeNodePtr root);
void visit(TreeNodePtr node);
TreeNodePtr newTreeNode(int d);
int SmallestGreaterKey(TreeNodePtr root, int key);

int main()
{
    FILE * in = fopen("numbst.txt", "r");

    BinaryTree bst;
    bst.root = NULL;
    int smallest = 0; //smallest number in the tree that is greater than the key

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

    smallest = SmallestGreaterKey(bst.root, 6);

    if (smallest != -1)
        printf("\nThe smallest number in the tree that is greater than 8 is %d\n", smallest);
    else
        printf("\nThere is no number that is greater than the key.\n");

    return 0;
}



int SmallestGreaterKey(TreeNodePtr root, int key)
{
    static int smallestGreater = -1;

    if (root == NULL)
        return smallestGreater;

    if (root != NULL)
    {
        if (root->data < key && root->right != NULL)
            return SmallestGreaterKey(root->right, key);
        else if (root->data > key)
        {
            smallestGreater = root->data;
            if (root->left != NULL)
                smallestGreater = SmallestGreaterKey(root->left, key);
            return smallestGreater;
        }

    } //end recursive case
    return smallestGreater;
    //return smallestGreater;
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

