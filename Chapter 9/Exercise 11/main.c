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

int internalPathLengthRecursive(TreeNodePtr root); //sum of the levels of the original tree nodes
int internalPathLengthNonRecursive(TreeNodePtr root);
void widthPreOrder(TreeNodePtr root, int total[], int level);
int getHeight(TreeNodePtr root);
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
    int ipl = 0;
    int ipl2 = 0; //non recursive internal path length function result

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

    ipl = internalPathLengthRecursive(bst.root);
    printf("\nThe internal path length of the binary tree is %d \n", ipl);

    ipl2 = internalPathLengthNonRecursive(bst.root);
    printf("\nThe internal path length of the binary tree using the non recursive function is %d \n", ipl2);

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

int internalPathLengthRecursive(TreeNodePtr root)
{
    if(root == NULL)
        return 0;


    int height = getHeight(root);
    int *count = (int *) calloc(h, sizeof(int)); //array to count number of nodes at each level method
    int level = 0;

    count[level] = internalPathLengthRecursive(root->left);
    if (root->left != NULL)
    {
        ++level;
        ++count[level];
    }
    else if (root->left != NULL && root->right != NULL)
    {
        ++level;
        ++count[level];
    }

    rnodes = internalPathLengthRecursive(root->right);
    if (root->right != NULL && root->right == NULL)
    {
        ++level;
        ++count[level];
    }
    else if (root->left != NULL && root->right != NULL)
        ++count[level];

    int internalPathLength = 0;

    if (level >= 1)
    {

    }

    return internalPathLength;
}

//finds the number of nodes at each level of a binary tree using pre-order traversal
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


int internalPathLengthNonRecursive(TreeNodePtr root)
{
    if (root == NULL)
        return 0;

    int h = getHeight(root); //height of the binary tree
    int *count = (int *) calloc(h, sizeof(int)); //array for widthPreOrder method
    int level = 0;
    int sum = 0;

    widthPreOrder(root, count, level);

    //loop to find the number of edges at each level of the binary tree
    for (int i = 1; i < h; i++)
    {
        sum += count[i] * i;
    }

    return sum;
}
