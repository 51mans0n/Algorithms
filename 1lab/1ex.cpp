#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<int> size_list;
    for (int i = 0 ; i != count ; i++)
    {
        int val;
        cin >> val;
        size_list.push_back(val);
    }
    for (int i = 0 ; i != count ; i++)
    {
        deque<int> cardlist;
        bool flag = true;
        int temp_size = size_list[i];

        while (cardlist.size() != size_list[i] + 1)
        {
            if (flag)
            {
                cardlist.push_front(temp_size);
                flag = false;
            }
            else
            {
                for (int j = 0 ; j != temp_size ; j++)
                {
                    int temp = cardlist[cardlist.size() - 1];
                    cardlist.pop_back();
                    cardlist.push_front(temp);
                }
                flag = true;
                temp_size--;
            }
        }
        cardlist.pop_front();
        for(int j = 0 ; j != cardlist.size() ; j++)
        {
            cout << cardlist[j] << " ";
        } 
        cout << endl; 
    }
}