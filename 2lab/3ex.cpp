#include <iostream>
#include <map>

using namespace std;

struct Node 
{
    int value;
    Node *next;
    Node (int value) 
    {
        this->value = value;
        this->next = NULL;
    }
};
void answer (Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        if (current->next == NULL)
        {
            return;
        }
        current = current->next->next;
    }
}
int main () 
{
    int size; 
    cin >> size;
    Node *head;
    Node *current;
    Node *temp;
    for (int i = 0 ; i < size ; i++) 
    {
        int value;
        cin >> value;
        if (i == 0) 
        {
            head = new Node(value);
            current = head;
        } 
        else 
        {
            temp = new Node(value);
            current -> next = temp;
            current = current -> next;
        }
    }
    answer(head);
}