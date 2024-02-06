#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<int> first_list;
    deque<string> final_list;
    bool flag = true;
    while (flag)
    {
        char key;
        cin >> key;
        if (key == '+')
        {
            int temp;
            cin >> temp;
            first_list.push_front(temp);
        }
        else if (key == '-')
        {
            int temp;
            cin >> temp;
            first_list.push_back(temp);
        }
        else if (key == '*')
        {
            if (first_list.size() == 0)
            {
                final_list.push_back("error");
            }
            else if (first_list.size() == 1)
            {
                int temp = first_list[0] * 2;
                string temp_str = to_string(temp);
                final_list.push_back(temp_str);
                first_list.pop_front();
            }
            else
            {
                int temp = first_list[0] + first_list[first_list.size() - 1];
                string temp_str = to_string(temp);
                final_list.push_back(temp_str);
                first_list.pop_back();
                first_list.pop_front();
            }
        }
        else if (key == '!')
        {
            for (int i = 0 ; i != final_list.size() ; i++)
            {
                cout << final_list[i] << endl;
            }
            flag = false;
        }
    }
}