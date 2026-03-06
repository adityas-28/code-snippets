#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> primeFactorization(ll n) {
    vector<ll> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    while (n % 3 == 0) {
        factors.push_back(3);
        n /= 3;
    }

    for (ll i = 5; i * i <= n; i += 6) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
        while (n % (i + 2) == 0) {
            factors.push_back(i + 2);
            n /= (i + 2);
        }
    }

    if (n > 1)
        factors.push_back(n);

    return factors;
}