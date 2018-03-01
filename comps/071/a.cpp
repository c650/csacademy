#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

int main(void) {

    std::string s;
    std::cin >> s;

    ll loc = s.find("AA");
    while (loc != std::string::npos) {
        s.replace(loc, 2, "A");
        loc = s.find("AA");
    }

    std::printf("%s\n",s.data());

    return 0;
}
