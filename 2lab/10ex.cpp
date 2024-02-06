# include <iostream>
# include <algorithm>

using namespace std;

struct Node 
{
    int value;
    Node *next;
    Node() 
    {
        value = 0;
        next = NULL;
    }
};
int findMaxSum (int size, Node *head) 
{
    int summary = head -> value;
    int maximum = head->value;
    head = head -> next;
	while (head != NULL) 
    {
        summary = max(head->value, summary + head->value);
        maximum = max(maximum, summary);
        head = head->next;
    }
    return maximum;
}
int main() 
{
    int size;
    cin >> size;
    Node *head, *tail;
    for (int i = 1 ; i <= size ; ++i) 
    {
        int temp;
        cin >> temp;
        Node *current = new Node();
        current -> value = temp;
        if (i == 1) 
        {
            head = tail = current;
        } 
        else 
        {
            tail -> next = current;
            tail = current;
        }
    }
    cout << findMaxSum(size, head) << "\n";
    return 0;
}
