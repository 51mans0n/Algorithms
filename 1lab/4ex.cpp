#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str; 
    cin >> str;
    stack<char> mystk;
    for (int i = 0 ; i < str.length() ; i++)
    {
        if (!mystk.empty() && str[i] == mystk.top())
        {
            mystk.pop();
        }
        else
        {
            mystk.push(str[i]);
        }
    }
    if (mystk.empty()) 
    {
        cout << "YES";
    }
    else 
    {
        cout << "NO";
    }
}