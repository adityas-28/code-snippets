#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int fact[MAXN];

void preComputeFactorial()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
}

int binExpo(int a, int b)
{
    int ans = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int modInverse(int a)
{
    return binExpo(a, MOD - 2);
}

int nCr(int n, int r)
{
    if (r < 0 || r > n || n >= MAXN)
        return 0;

    int numerator = fact[n];
    int denominator = (1LL * fact[r] * fact[n - r]) % MOD;

    return (1LL * numerator * modInverse(denominator)) % MOD;
}

int main()
{
    preComputeFactorial();

    cout << nCr(5, 3);
    
    return 0;
}