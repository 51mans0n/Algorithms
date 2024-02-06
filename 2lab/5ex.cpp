#include <iostream>
#include <map>

using namespace std;

struct Node 
{
    string value;
    Node *next;
    Node (string value) 
    {
        this->value = value;
        this->next = NULL;
    }
    Node(){}
};
void print(Node* head) 
{
    Node* current = head;
    while (current != NULL) 
    {
        cout << current->value << endl;
        current = current->next;
    }
}
void duplicate (Node* head) 
{
    Node *current = head;
    Node *prev = head;
    while (current != NULL) {
        if (current->value == prev->value) 
        {
            prev->next = current->next;
        } 
        else 
        {
            prev -> next = current;
            prev = prev->next;
        }
        current = current->next;
    }
}
int getCount (Node* head) 
{
    Node * current = head;
    int counter = 0;
    while (current != NULL) 
    {
        counter++;
        current = current->next;
    }
    return counter;
}
void push(Node** head_ref, string data)
{
    Node* temp = new Node(data);
    temp->next = (*head_ref);
    (*head_ref) = temp;
}
int main () 
{
    int size; 
    cin >> size;
    Node *head = NULL;
    string value;
    for (int i = 0 ; i != size ; i++) 
    {
        cin >> value;
        push(&head, value);
    }
    duplicate (head);
    cout << "All in all: " << getCount(head) << endl;
    cout << "Students:" << endl;
    print(head);
}
