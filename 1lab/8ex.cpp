#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if(num == 0 || num == 1)
    {
        return false;
    }
    for (int i = 2 ; i * i <= num ; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num;
    cin >> num;
    if (isPrime(num))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}