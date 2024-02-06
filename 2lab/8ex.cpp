#include <iostream>
#include <cmath>

using namespace std;

struct Node 
{
    string value;
    Node* next;
    int counter;
    Node() {}
    Node (string value) 
    {
        this->value = value;
        this->next = NULL;
        counter = 1;
    }
};
class LinkedList
{
    int size;
    public:
    Node * head;
    LinkedList()
    {
        head = NULL;
    }
    void add_front (string book)
    {
        Node * current = head;
        Node * newNode = new Node(book);
        if (head == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cout << "ok" << endl;
    }
    void add_back (string book)
    {
        Node * current = head;
        Node * newNode = new Node(book);
        if (head == NULL)
        {
            head = newNode;
            cout << "ok" << endl;
        }
        else
        {
            while (current != NULL)
            {
                if (current->next == NULL)
                {
                    current->next = newNode;
                    cout << "ok" << endl;
                    return;
                }
                current = current->next;
            }
        }
    }
    void erase_front()
    {
        if (head == NULL)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << head->value << endl;
            head = head->next;
        }
    }
    void erase_back()
    {
        if (head == NULL)
        {
            cout << "error" << endl;
        }
        else if (head->next == NULL)
        {
            cout << head->value << endl;
            head = NULL;
        }
        else if (head != NULL && head->next != NULL)
        {
            Node * current = head;
            Node * prev = head;
            while (current != NULL)
            {
                if(current->next == NULL)
                {
                    cout << current->value << endl;
                    prev->next = NULL;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    }
    void front()
    {
        if(head == NULL){
            cout << "error" << endl;
        }
        else{
            cout << head->value << endl;
        }
    }
    void back()
    {
        if (head == NULL)
        {
            cout << "error" << endl;
        }
        else
        {
            Node * current = head;
            while (current != NULL)
            {
                if(current->next == NULL)
                {
                    cout << current->value << endl;
                }
                current = current->next;
            }
        }
    }
    void clear()
    {
        head = NULL;
        cout << "ok" << endl;
    }
};
int main() 
{
    LinkedList list;
    while(true)
    {
        string myStr; 
        cin >> myStr;
        if (myStr == "add_front")
        {
            string book; 
            cin >> book;
            list.add_front(book);
        }
        else if (myStr == "add_back")
        {
            string book; 
            cin >> book;
            list.add_back(book);
        }
        else if (myStr == "erase_front")
        {
            list.erase_front();
        }
        else if (myStr == "erase_back")
        {
            list.erase_back();
        }
        else if (myStr == "front")
        {
            list.front();
        }
        else if (myStr == "back")
        {
            list.back();
        }
        else if (myStr == "clear")
        {
            list.clear();
        }
        else if (myStr == "exit")
        {
            cout << "goodbye";
            break;
        }
    }
}