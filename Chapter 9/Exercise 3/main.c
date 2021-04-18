/*Write a function that, given the root of a binary search tree, deletes the smallest node and returns a pointer to the root
of the reconstructed tree.
*/

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
TreeNodePtr deleteSmallest(TreeNodePtr root);
void inOrder(TreeNodePtr root);
void preOrder(TreeNodePtr root);
void visit(TreeNodePtr node);
TreeNodePtr newTreeNode(int d);

int main()
{
    FILE * in = fopen("numbst.txt", "r");

    BinaryTree bst;
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

    TreeNodePtr node2 = deleteSmallest(bst.root);
    printf("\nThe in-order traversal is: ");
    inOrder(bst.root);
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


TreeNodePtr deleteSmallest(TreeNodePtr root)
{
    if (root == NULL)
        return root;

    //recursive case to find the smallest node
    if (root->left != NULL)
        root->left = deleteSmallest(root->left);
    else
    { //delete the smallest node
        if (root->left == NULL)
        {
            TreeNodePtr temp = malloc(sizeof(TreeNode));
            temp = root->right;
            free(root);
            return temp;
        }
    }

    return root;
}

