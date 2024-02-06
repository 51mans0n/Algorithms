#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> start_vec, final_vec;
    start_vec.push_back(9);
    for (int i = 0 ; i < 100001 ; i++)
    {
        if(isPrime(i))
        {
            start_vec.push_back(i);
        }
    }
    for (int i = 0; i < start_vec.size(); i++)
    {
        if (isPrime(i))
        {
            final_vec.push_back(start_vec[i]);
        }
    }
    int num; 
    cin >> num;
    cout << final_vec[num - 1];
}