#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

int main(void) {

    ll n;
    std::scanf("%lld",&n);

    std::string s = std::to_string(n);
    std::string rev(s.rbegin(),s.rend());

    std::printf("%lld\n",n < std::stoi(rev));

    return 0;
}
