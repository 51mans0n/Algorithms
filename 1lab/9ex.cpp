#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main()
{
    int size;
    cin >> size;
    string input;
    cin >> input;
    queue<char> votes;
    int s_count = 0;
    int k_count = 0;
    for (int i = 0 ; i < size ; i++) 
    {
        votes.push(input[i]);
        if(input[i] == 'S')
        {
            s_count++;
        }
        else
        {
            k_count++;
        }
    }
    int k_Skip_count = 0;
    int s_Skip_count = 0;
    while (s_count > 0 && k_count > 0)
    {
        char temp = votes.front();
        if(temp == 'S')
        {
            if (s_Skip_count > 0)
            {
                s_Skip_count--;
                s_count--;
            }
            else
            {
                k_Skip_count++;
                votes.push(temp);
            }
        }
        else
        {
            if (k_Skip_count > 0)
            {
                k_Skip_count--;
                k_count--;
            }
            else
            {
                s_Skip_count++;
                votes.push(temp);
            }
        }
        votes.pop();
    }


    if (votes.front() == 'K')
    {
        cout << "KATSURAGI" << endl;
    }
    else
    {
        cout << "SAKAYANAGI" << endl;
    }
}