#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
	ll n;
	std::scanf("%lld",&n);

	std::vector<ll> vec(3);
	for (ll a; n--; ) {
		std::scanf("%lld",&a);
		vec[a%3]++;
	}

	ll ret = vec[1] * vec[2];
	ret += vec[0] * (vec[0]-1) / 2;

	std::printf("%lld\n",ret);

	return 0;
}
