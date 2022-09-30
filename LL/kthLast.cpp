#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int kthLastElement(node *head, int k)
{
    int count = 0;
    node *fast = head;
    node *slow = head;
    while (count < k) //* isko itna isiliye krre kyunkin hum fast ko utna run kara lenge phle fir bas jab tak null nhi hota
    {
        fast = fast->next;
        count++;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
