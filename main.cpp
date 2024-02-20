#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

ll ost(ll a1, ll a2) {
    ll b1 = a1 % mod, b2 = a2 % mod;
    return (b1 * b2) % mod;
}

int main() {
    int n;
    cin >> n;
    ll f = 1;
    vector<ll> st;
    while (f <= 1e18) {
        st.push_back(f);
        f *= 2;
    }
    for (int i = 0; i < n; i++) {
        ll a, ans = 0;
        cin >> a;
        for (int j = 0; j < st.size() && st[j] <= a; j++) {
            ll now = a - st[j] + 1, kv = now / st[j] / 2 * st[j] + min(st[j], now % (st[j] * 2));
            ll fi = ost(kv, kv);
            ll se = ost(fi, st[j]);
            ans += se;
        }
        cout << ans % mod << endl;
    }
    return 0;
}