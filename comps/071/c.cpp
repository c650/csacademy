#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

	ll n;
	std::scanf("%lld",&n);

	std::vector<ll> vec(n);
	for (ll i = 0, tmp; i < n; ++i) {
		std::scanf("%lld",&tmp);
		vec[i] = tmp == 0 ? 1 : -1;
	}

	ll max = std::numeric_limits<ll>::min();
	ll min = std::numeric_limits<ll>::max();

	max = 0;
	ll cm = 0;

	for (ll i = 0; i < n; ++i) {
	    cm = std::max(cm + vec[i], vec[i]);
	    max = std::max(max, cm);
	}

	min = 0;
	cm = 0;
	for (ll i = 0; i < n; ++i) {
	    cm = std::min(cm + vec[i], vec[i]);
	    min = std::min(min, cm);
	}


    ll cnt = max - min + 1;
	std::printf("%lld\n",cnt);

	return 0;
}

