#include <iostream>
#include <map>

using namespace std;

struct Node 
{
    char value;
    Node* next;
    Node() {}
    Node (char value) 
    {
        this->value = value;
        next = NULL;
    }
};
void push (Node* &end, Node* &head, int value) 
{
    if (end == NULL) 
    {
        head = new Node(value);
        end = head;
        return;
    }
    end->next = new Node(value);
    end = end->next;
}
int main() 
{
    int size;
    cin >> size;
    while (size--) 
    {
        int secondSize;
        cin >> secondSize;
        Node* head = nullptr;
        Node* end = head;
        map <char, int> myMap;
        while(secondSize--) 
        {
            char value;
            cin >> value;
            push(end, head, value);
            myMap[value]++;
            Node* current = head;
            bool first = false;
            while(current) 
            {
                if (myMap[current->value] == 1) 
                {
                    first = true;
                    break;
                }
                current = current->next;
            }
            if(first) 
            {
                cout << current->value << " ";
            }
            else 
            {
                cout << -1 << " ";
            }
        }
        myMap.clear();
        cout << endl;
    }
}