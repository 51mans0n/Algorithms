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
int main () 
{
    int size; 
    cin >> size;
    Node *head;
    Node *current;
    Node *temp;
    map<int,int> myMap;
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
    Node *i;
    i = head;
    int iter = -1;
    while (i != NULL) 
        {
            int num = i->value;
            myMap[num]++;
            iter = max(iter, myMap[num]);
            i = i->next;
        }
    myMap[0] = 0;
    for(map<int,int>::iterator it = myMap.end() ; it != myMap.begin() ; --it)
    {
        if(it->second == iter)
        { 
            cout << it->first << " "; 
        }
    }
}