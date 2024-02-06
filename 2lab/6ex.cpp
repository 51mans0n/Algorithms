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
void answer (Node* head,int data,int pos)
{
    Node* current = head;
    int counter = 0;
    Node* temp = new Node(data);
    while (current != NULL)
    {
        if(counter == pos)
        {
            temp->next = current;
            current = temp;
        }
        cout << current->value << " ";
        current = current->next;
        counter++;
    }
}
int main () 
{
    int size; 
    cin >> size;
    Node *head;
    Node *current;
    Node *temp;
    for (int i = 0 ; i != size ; i++) 
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
    int data, pos;
    cin >> data >> pos;
    answer(head, data, pos);
}
