#include <iostream>

using namespace std;

bool isprime(int num)
{
    for (int i = 2 ; i * i <= num ; i++)
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
    int val, num = 4, counter_primes = 2;
    cin >> val;
    if (val == 1)
    {
        cout << "2";
    }
    else if (val == 2)
    {
        cout << "3";
    }
    else
    {
        while (true)
        {
            if (isprime(num))
            {
                ++counter_primes;
            }
            if (counter_primes == val)
            {
                cout << num;
                return 0;
            }
            ++num;
        }
    }
}
