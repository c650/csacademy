#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

const ll INF = 1000000000;

int main(void) {

    ll n;
    std::scanf("%lld",&n);

    ll tot = 0;
    std::vector<ll> vec(n+1);
    for (ll i = 0; i < n; ++i) {
        std::scanf("%lld",&vec[i+1]);
        tot += vec[i+1];
        vec[i+1] += vec[i];
    }

    ll best_node = 0;
    ll best_dist = INF;
    for (ll i = 0; i < n; ++i) {
        ll max_dist = 0;

        for (ll j = 0; j < n; ++j) {
            ll tmp = std::abs(vec[j] - vec[i]);
            max_dist = std::max(max_dist, std::min(tmp, tot - tmp));
        }

        if (max_dist < best_dist) {
            best_dist = max_dist;
            best_node = i;
        }
    }

    std::printf("%lld\n",best_node+1);

    return 0;
}
