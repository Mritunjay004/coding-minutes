#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void PrintIn(Node *root)
{
    if (root == NULL)
        return;

    PrintIn(root->left);
    cout << root->data << " ";

    PrintIn(root->right);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

bool srch(Node *root, int key)
{
    Node *tmp = root;
    while (tmp != NULL)
    {
        if (key == tmp->data)
        {
            return true;
        }

        else if (key < tmp->data)
        {
            tmp = tmp->left;
        }
        else if (key > tmp->data)
        {
            tmp = tmp->right;
        }
    }
    return false;
}

Node *findMinInRightSubTree(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *remove(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (key < root->data)
        root->left = remove(root->left, key);
    else if (key > root->data)
        root->right = remove(root->right, key);
    //*up above is the same code for srch as well
    else
    {
        //*no children
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //*single child
        else if (root->left == NULL)
        {
            Node *tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root;
            root = root->left;
            delete tmp;
        }

        //* 2 childs
        else
        {
            Node *tmp = findMinInRightSubTree(root->right);
            root->data = tmp->data;
            root->right = remove(root->right, tmp->data); //* as we also have to delete after copying the value
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int x : arr)
        root = insert(root, x);

    PrintIn(root);
    cout << endl;

    root = remove(root, 14);
    PrintIn(root);

    return 0;
}
