#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int len(node *head)
{
    node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

node *bubble_sort_LinkedList_itr(node *head)
{
    int n = len(head) - 1;
    while (n--)
    {
        node *prev = NULL;
        node *curr = head;

        while (curr->next != NULL)
        {
            if (curr->data >= curr->next->data)
            {
                if (prev == NULL)
                {
                    // first node
                    node *nxt = curr->next;
                    curr->next = nxt->next;
                    nxt->next = curr;
                    prev = nxt;
                    head = nxt;
                }
                else
                {
                    node *nxt = curr->next;
                    prev->next = nxt;
                    curr->next = nxt->next;
                    nxt->next = curr;
                    prev = nxt;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}
