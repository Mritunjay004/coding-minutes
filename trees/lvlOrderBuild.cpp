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

Node *lvlOrderBuild()
{
    int d;
    cin >> d;

    Node *root = new Node(d);

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *current = q.front();
        q.pop();

        int leftChild, rightChild;
        cin >> leftChild >> rightChild;

        if (leftChild != -1)
        {
            current->left = new Node(leftChild);
            q.push(current->left);
        }
        if (rightChild != -1)
        {
            current->right = new Node(rightChild);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    Node *res = lvlOrderBuild();
    lvlOrder(res);
}
