#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
    ll n;
    std::scanf("%lld",&n);

	std::vector<std::string> vec(n);
	std::vector<ll> order(n);
	for (ll i = 0; i < n; ++i) {
		order[i] = i;
		std::cin >> vec[i];
	}

	std::sort(order.begin(),order.end(), [&vec](const ll& a, const ll& b){
		return vec[a] < vec[b];
	});

	for (auto& e : order)
		std::printf("%lld ", e+1);
	std::putchar('\n');

    return 0;
}
