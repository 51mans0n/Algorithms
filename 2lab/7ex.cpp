#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(): value(0), next(nullptr) {}
    Node(int x): value(x), next(nullptr) {}
    Node(Node* next): value(0), next(next) {}
    Node(int x, Node* next): value(x), next(next) {}
};
Node* insert (Node* head, Node* node, int p)
{
    if (p == 0) 
    {
        node->next = head;
        head = node;
        return head;
    }
    Node* current = head;
    int counter = 0;
    while (current) 
    {
        if(counter + 1 == p) 
        {
            node->next = current->next;
            current->next = node;
            break;
        }
        current = current->next;
        counter++;
    }
    return head;
}
Node* remove (Node* head, int p)
{
    if (p == 0) 
    {
        head = head->next;
        return head;
    }
    Node* current = head;
    Node* prev = nullptr;
    int counter = 0;
    while(current) 
    {
        if (counter == p) 
        {
            prev->next = current->next;
            delete current;
            break;
        }
        prev = current;
        current = current->next;
        counter++;
    }
    return head;
}
Node* replace (Node* head, int p1, int p2)
{
    if(p1 == p2) 
    {
        return head;
    }
    Node* current = head;
    int counter = 0;
    Node* temp;
    while(current) 
    {
        if (p1 == 0) 
        {
            temp = head;
            head = head->next;
            temp->next = nullptr;
            break;
        }
        if (counter + 1 == p1) 
        {
            temp = current->next;
            current->next = current->next->next;
            break;
        }
        counter++;
        current = current->next;
    }
    head = insert(head, temp, p2);
    return head;
}
Node* reverse(Node* head)
{
    if (head == NULL or head->next == NULL) 
    {
        return head;
    }
    Node* prev = head;
    Node* current = head->next;
    while (current) 
    {
        prev->next = current->next;
        current->next = head;
        head = current;
        current = prev->next;
    }
    return head;
}
void print(Node* head)
{
    while(head) 
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}
Node* cyclic_left (Node* head, int x)
{
    int counter = 0;
    Node* prev = nullptr;
    Node* start = head;
    Node* end = head;
    while(end) 
    {
        if(counter < x) 
        {
            prev = start;
            start = start->next;
        }
        if(end->next == nullptr) 
        {
            break;
        }
        end = end->next;
        if(counter < x) 
        { 
            counter++;
        }
    }
    prev->next = nullptr;
    end->next = head;
    head = start;
    return head;
}
Node* cyclic_right (Node* head, int x)
{
    if(x == 0) 
    {
        return head;
    }
    int size = 0;
    Node* end = head;
    Node* current = head;
    Node* prev = nullptr;
    while(end) 
    {
        if(end->next == nullptr) 
        {
            break;
        }
        end = end->next;
        size++;
    }
    for (int i = 0 ; i < size + 1 - x ; i++) 
    {
        prev = current;
        current = current->next;
    }
    end->next = head;
    prev->next = nullptr;
    head = current;
    return head;
}
int main()
{
    Node* head = nullptr;
    while (true)
    {
        int command; 
        cin >> command;
        if (command == 0)
        {
            break;
        }
        else if(command == 1)
        {
            int x, p; 
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2)
        {
            int p; 
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3)
        {
            print(head);
        }
        else if (command == 4)
        {
            int p1, p2; 
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5)
        {
            head = reverse(head);
        }
        else if (command == 6)
        {
            int x; 
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7)
        {
            int x; 
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}