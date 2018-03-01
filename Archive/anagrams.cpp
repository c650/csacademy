#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

int main(void) {

    ll n;
    std::scanf("%lld",&n);

    std::vector<std::vector<ll>> vec(n, std::vector<ll>(26));
    std::string str;
    for (ll i = 0; i < n; ++i) {
        std::cin >> str;
        for (const auto& c : str)
            vec[i][c-'a']++;
    }

    std::sort(vec.begin(),vec.end());

    ll max = 1;
    for (ll i = 0,tmp; i < n;) {
        tmp = 1;
        for (++i; i < n && vec[i] == vec[i-1]; ++i, ++tmp);
        max = std::max(max, tmp);
    }

    std::printf("%lld\n",max);


    return 0;
}
