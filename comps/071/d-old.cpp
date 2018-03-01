#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

	ll n;
	std::scanf("%lld",&n);

	std::list<ll> stuff;
	for (ll i = 0,tmp; i < n; ++i) {
		std::scanf("%lld",&tmp);
		stuff.push_back(tmp);
	}

	stuff.sort();

	ll ans = 0;

	ll most = 0;
	auto it = stuff.begin();
	for (; it != stuff.end(); ++it) {
		ll cnt = 0;
		auto it2 = std::next(it);
		while(*it2 == *it) {
			++cnt;
			++it2;
		}

		if (cnt < most) {
			ll to_insert =
		}

		most = std::max(most,cnt);
	}

	return 0;
}

