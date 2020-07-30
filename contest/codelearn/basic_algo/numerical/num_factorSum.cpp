#include <bits/stdc++.h>

using namespace std;

int factorSum(int n)
{
    int s = 0, o;
    while (true)
    {
        s = 0; o = n;
        bool f = false;
        while (true)
        {
            if (n % 2 == 0)
            {
                s += 2;
                n = n / 2;
            }
            else
                break;
        }
        for (int i = 3; i <= n;)
        {
            // if (n % i != 0 && n > i && n < (i+2))
            // {
            //     f = true;
            //     break;
            // }
            if (n % i == 0)
            {
                s += i;
                n = n / i;
            }
            else
            {
                i += 2;
            }
        }
        if(o == s) {
            n = s; break;
        }
        // if (f)
        //     break;

        n = s;
    }
    return n;
}

int main()
{
    cout << factorSum(35);  // out 7
}
