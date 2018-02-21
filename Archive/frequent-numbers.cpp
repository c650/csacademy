#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
	ll n,k;
	std::scanf("%lld %lld",&n,&k);

	std::vector<ll> vec(1000);
	for (ll a; n--; ) {
		std::scanf("%lld",&a);
		vec[a-1]++;
	}

	ll ret = 0;
	for (auto& e : vec)
		ret += e >= k;

	std::printf("%lld\n",ret);

	return 0;
}
