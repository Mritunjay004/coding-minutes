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

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void PrintPre(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    PrintPre(root->left);
    PrintPre(root->right);
}

void PrintIn(Node *root)
{
    if (root == NULL)
        return;

    PrintIn(root->left);
    cout << root->data << " ";

    PrintIn(root->right);
}

void PrintPost(Node *root)
{
    if (root == NULL)
        return;

    PrintPost(root->left);

    PrintPost(root->right);
    cout << root->data << " ";
}

void lvlOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false)
    {
        Node *tmp = q.front();
        if (tmp == NULL)
        { //* one lvl completed
            cout << endl;
            q.pop();
            if (q.empty() == false) //* for corner cases and regular
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << tmp->data << " ";
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
        }
    }
}

int main()
{
    Node *res = buildTree();
    // PrintIn(res);
    // cout << endl;
    // PrintPost(res);
    // cout << endl;
    lvlOrder(res);
}
