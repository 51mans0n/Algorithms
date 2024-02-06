#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string first_str, second_str; 
    cin >> first_str >> second_str;
    stack<char> stk_first, stk_second;
    for (int i = 0 ; i < first_str.size() ; i++)
    {
        if (first_str[i] != '#')
        {
            stk_first.push(first_str[i]);
        }
        else if (!stk_first.empty() && first_str[i] == '#')
        {
            stk_first.pop();
        }
        else if (stk_first.empty() && first_str[i] == '#')
        {
            stk_first.push(first_str[i]);
        }
    }
    
    for (int i = 0 ; i < second_str.size() ; i++)
    {
        if (second_str[i] != '#')
        {
            stk_second.push(second_str[i]);
        }
        else if (!stk_second.empty() && second_str[i] == '#')
        {
            stk_second.pop();
        }
        else if (stk_second.empty() && second_str[i] == '#')
        {
            stk_second.push(second_str[i]);
        }
    }
    
    if (stk_first.size() == stk_second.size())
    {
        cout << "Yes";
    }
    else 
    {
        cout << "No";
    }
}