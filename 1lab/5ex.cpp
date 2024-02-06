#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int card_list_size = 5;
    deque<int> Nursik_cards;
    deque<int> Boris_cards;
    for (int i = 0 ; i != card_list_size ; i++)
    {
        int temp;
        cin >> temp;
        Boris_cards.push_back(temp);
    }
    for (int i = 0 ; i != card_list_size ; i++)
    {
        int temp;
        cin >> temp;
        Nursik_cards.push_back(temp);
    }
    bool Boris_win = false;
    int counter = 0;
    while (true)
    {
        if (counter >= 1000000)
        {
            cout << "blin nichya";
            return 0;
        }
        else if (Nursik_cards.empty())
        {
            Boris_win = true;
            break;
        }
        else if (Boris_cards.empty())
        {
            break;
        }
        else if (Boris_cards[0] == 0 && Nursik_cards[0] == 9)
        {
            Boris_cards.push_back(Boris_cards[0]);
            Boris_cards.push_back(Nursik_cards[0]);
            Boris_cards.pop_front();
            Nursik_cards.pop_front();
        }
        else if (Boris_cards[0] == 9 && Nursik_cards[0] == 0)
        {
            Nursik_cards.push_back(Boris_cards[0]);
            Nursik_cards.push_back(Nursik_cards[0]);
            Boris_cards.pop_front();
            Nursik_cards.pop_front();
        }
        else
        {
            if (Boris_cards[0] > Nursik_cards[0])
            {
                Boris_cards.push_back(Boris_cards[0]);
                Boris_cards.push_back(Nursik_cards[0]);
                Boris_cards.pop_front();
                Nursik_cards.pop_front();
            }
            else if (Boris_cards[0] < Nursik_cards[0])
            {
                Nursik_cards.push_back(Boris_cards[0]);
                Nursik_cards.push_back(Nursik_cards[0]);
                Boris_cards.pop_front();
                Nursik_cards.pop_front();
            }
        }
        ++counter;
    }
    if (Boris_win)
    {
        cout << "Boris " << counter;
    }
    else 
    {
        cout << "Nursik " << counter;
    }
}