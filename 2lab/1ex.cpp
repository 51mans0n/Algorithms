#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int value;
    Node *next;
    Node (int newValue) 
    {
        this->value = newValue;
        this->next = NULL;
    }

};
void print (Node* head) 
{
    Node* current = head;
    while (current != NULL) 
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
void nearestNumber (Node* head, int nearest) 
{
    Node* current = head;
    int answer = 0;
    int index = 0;
    int min = abs(nearest - current->value);
    while (current != NULL) 
    {

        if (min > abs(nearest - current->value)) 
        {
            min = abs(nearest - current->value);
            answer = index;
        }
        current = current->next;
        index++;
    }
    cout << answer << endl;
}
int main()
{
    Node *head;
    Node *current;
    Node *temp;
    int size;
    cin >> size;
    for (int i = 0 ; i < size ; i++)
    {
        int number;
        cin >> number;
        if (i == 0)
        {
            head = new Node(number);
            current = head;
        }
        else
        {
           temp = new Node(number);
           current->next = temp;
           current = current->next;
        }
    }
    int nearest; cin >> nearest;
    nearestNumber(head, nearest);
    return 0;
}