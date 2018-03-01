#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

int main(void) {

	ll n;
	std::scanf("%lld",&n);

	std::vector<ll> sum(n+1);
	for (ll i = 1, tmp; i <= n; ++i) {
		std::scanf("%lld",&tmp);
		sum[i] = sum[i-1] + (tmp == 0 ? 1 : -1);
	}

	std::vector<char> bloom(300'003, false);
	bloom[0 + bloom.size()/2] = true;
	ll cnt = 1;

	for (ll i = 0; i <= n; ++i) {
		for (ll j = i+1; j <= n; ++j) {
			cnt += !bloom[sum[j] - sum[i] + bloom.size()/2];
			bloom[sum[j] - sum[i] + bloom.size()/2] = true;
		}
	}

	std::printf("%lld\n",cnt);

	return 0;
}

