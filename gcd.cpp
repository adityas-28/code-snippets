#include <bits/stdc++.h>
using namespace std;

int gcd_recursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int gcd_iterative(int a, int b)
{
    while (b > 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a = 13214214;
    int b = 641134;

    int stlGCD = gcd(a, b);
    int recGCD = gcd_recursive(a, b);
    int iterGCD = gcd_iterative(a, b);

    cout << stlGCD << " " << recGCD << " " << iterGCD << endl;
}