#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll n;
    std::scanf("%lld",&n);

    std::vector<ll> vec(n);
    for (auto& e : vec)
        std::scanf("%lld",&e);

    std::sort(vec.begin(), vec.end());

    ll max = 1;
    std::vector<ll> dp(n, 1);
    for (ll i = 1; i < n; ++i) {
        for (ll j = i-1; j >= 0; --j) {
            if (vec[i] % vec[j] == 0)
                dp[i] = std::max(dp[i], 1+dp[j]);
        }
        max = std::max(max, dp[i]);
    }

    std::printf("%lld\n",max);

    return 0;
}
