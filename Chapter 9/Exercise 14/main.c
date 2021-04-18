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
TreeNodePtr inOrderKey(TreeNodePtr root, int key); //searches for key using in order traversal
TreeNodePtr preOrderKey(TreeNodePtr root, int key); //searches for key using pre order traversal
TreeNodePtr postOrderKey(TreeNodePtr root, int key); //searches for key using post order traversal
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

    TreeNodePtr keyNode;
    int count = 0;
    keyNode = inOrderKey(bst.root, 9);
    if (keyNode != NULL)
        count = 1;
    else
        count = 0;

    if (count == 1)
        printf("\n\n%d exists in the binary tree. In order traversal was used.\n", 9);
    else
        printf("\n\n%d doesn't exist in the binary tree. In order traversal was used.\n", 9);

    TreeNodePtr keyNode2;
    count = 0;
    keyNode2 = preOrderKey(bst.root, 3);
    if (keyNode2 != NULL)
        count = 1;
    else
        count = 0;

    if (count == 1)
        printf("\n%d exists in the binary tree. Pre order traversal was used.\n", 3);
    else
        printf("\n%d doesn't exist in the binary tree. Pre order traversal was used.\n", 3);

    TreeNodePtr keyNode3;
    count = 0;
    keyNode3 = postOrderKey(bst.root, 18);

    if (keyNode3 != NULL)
        count = 1;
    else
        count = 0;

    if (count == 1)
        printf("\n%d exists in the binary tree. Post order traversal was used.\n", 18);
    else
        printf("\n%d doesn't exist in the binary tree. Post order traversal was used.\n", 18);


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

TreeNodePtr inOrderKey(TreeNodePtr root, int key)
{
    TreeNodePtr node = NULL;

    if (root != NULL)
    {
        node = inOrderKey(root->left, key);
        if(key == root->data)
        {
           return root;
        }
        if (!node)
            node = inOrderKey(root->right, key);
    }
    return node;
} //end inOrderKey

TreeNodePtr preOrderKey(TreeNodePtr root, int key)
{
    void visit(TreeNodePtr);
    TreeNodePtr node = NULL;
    if (root != NULL)
    {
        if(key == root->data)
        {
            return root;
        }
        node = preOrderKey(root->left, key);
        if (!node)
            node = preOrderKey(root->right, key);
    }
    return node;
} //end preOrderKey

TreeNodePtr postOrderKey(TreeNodePtr root, int key)
{
    TreeNodePtr node = NULL;

    if (root != NULL)
    {
        node = postOrderKey(root->left, key);
        if (!node)
            node = postOrderKey(root->right, key);
        if(key == root->data)
        {

            return root;
        }
    }
    return node;
} //end postOrderKey

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
