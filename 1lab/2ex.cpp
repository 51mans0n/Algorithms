#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<int> list(count);
    auto iter = list.cbegin();
    for (int i = 0 ; i != list.size() ; i++)
    {
        int num;
        cin >> num;
        list[i] = num;
    }
    vector<int> final_list(count);
    for (int i = 0 ; i != list.size() ; i++)
    {
        if (i == 0)
        {
            final_list[i] = -1;
        }
        else
        {
            int temp = list[i]; 
            for (int j = i - 1 ; j >= 0 ; j--) 
            {
                if (temp == list[j])
                {
                    final_list[i] = list[j];
                    break;
                }
                else if (temp > list[j])
                {
                    final_list[i] = list[j];
                    break;
                }
                if (j == 0)
                {
                    final_list[i] = -1;
                    break;
                }
            }
        }
    }
    for (int i = 0 ; i != list.size() ; i++)
    {
        cout << final_list[i] << " ";
    }
}
