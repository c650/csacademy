#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;

int main(void) {

    ll n;
    std::cin >> n;

    matrix A(n, std::vector<ll>(n));
    for (auto& r : A) for (auto& e : r) std::cin >> e;

    std::vector<ll> going(n);
    ll tot = 0;
    ll max = 0;
    for (ll i = 0; i < 2 * n; ++i) {
        going[i % n] = 0;

        tot = 0;
        for (ll j = 0; j < A[i % n].size(); ++j)
            going[j] += A[i % n][j], tot += going[j];

        max = std::max(tot, max);
    }

    std::cout << max << "\n";

    return 0;
}
