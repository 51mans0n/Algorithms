#include <iostream>

using namespace std;

struct Node
{
    string value;
    Node *next;
    Node (string newValue)
    {
        this->value = newValue;
        this->next = NULL;
    }
};
Node* cyclicShift (Node* head, int pos) 
{
    Node *current = head;
    Node *tail;
    while (current -> next != NULL) {
        current = current->next;
        tail = current;
    }
    while (pos--) 
    {
        Node *tmp = head -> next;
        tail -> next = head;
        head -> next = NULL;
        head = tmp;
        tail = tail->next;
    }
    return head;
}

void print (Node* head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
}
int main()
{
    Node *head;
    Node *current;
    Node *temp;
    int size, pos;
    cin >> size >> pos;
    for (int i = 0 ; i < size ; i++)
    {
        string value; 
        cin >> value;
        if (i == 0)
        {
            head = new Node(value);
            current = head;
        }
        else 
        {
            temp = new Node(value);
            current->next = temp;
            current = current->next;
        }
    }
    head = cyclicShift(head, pos);
    print(head);
    return 0;
}