#define ll long long
const int MOD = 1e9 + 7;

ll fast_exp(ll base, ll power) {
    if (power < 0) return 0;
    ll ans = 1;

    while (power) {
        ll lastBit = power & 1;
        if (lastBit) {
            ans = ans * base;
        }
        base = base * base;
        power >>= 1;
    }

    return ans;
}

int fast_exp(int base, int power) {
    if (power < 0) return 0;
    int ans = 1;

    while (power) {
        int lastBit = power & 1;
        if (lastBit) {
            ans = (1LL * ans * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        power >>= 1;
    }

    return ans;
}
