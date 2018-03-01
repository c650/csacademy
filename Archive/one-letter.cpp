#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll n;
    std::scanf("%lld",&n);

    std::multiset<char> boop;
    for (std::string s; n--; ) {
        std::cin >> s;
        boop.insert(*std::min_element(s.begin(),s.end()));
    }
    for (const auto& e : boop)
        std::putchar(e);
    std::putchar('\n');

    return 0;
}
