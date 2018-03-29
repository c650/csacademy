#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll a,l,h;
    std::cin >> a >> l >> h;

    for (ll c = 0; c <= a; ++c) {
        if (2 * c > l) break;
        for (ll r = 0; c + r <= a; ++r) {
            if (4 * r + 2 * c > l || 2 * r > h) break;
            ll u = a - c - r;
            if (4 * (u+r) + 2 * c == l && 2 * r + u == h) {
                std::cout << u << "\n";
                break;
            }
        }
    }

    return 0;
}
