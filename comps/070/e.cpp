#include <bits/stdc++.h>

typedef long long ll;

const ll INF = 10'000'000'000'000;

std::vector<ll> vec;

const ll dim1 = 101;
const ll dim2 = 10'001;
ll memo[dim1][dim2];
char seen[dim1][dim2];

static ll go(const ll& i, const ll& k) {
	if (i >= vec.size()) {
	    return INF;
	}

	if (k == 1) {
		return (vec.back() - vec[i]) * (vec.back() - vec[i]);
	}

	if (seen[k][i])
		return memo[k][i];

	seen[k][i] = true;

	ll ret = INF;
	for (ll j = i; j + k <= vec.size(); ++j) {
		ret = std::min(ret, (vec[j]-vec[i]) * (vec[j]-vec[i]) + go(j+1, k-1));
	}

	return memo[k][i] = ret;
}

int main(void) {

	for (ll i = 0; i < dim1; ++i)
		std::fill(memo[i],memo[i]+dim2,-1);

	for (ll i = 0; i < dim1; ++i)
		std::fill(seen[i],seen[i]+dim2,0);

	ll n,k;
	std::scanf("%lld %lld",&n,&k);

	vec.resize(n);
	for (auto& e : vec)
		std::scanf("%lld",&e);

	std::printf("%lld\n",go(0,k));

	return 0;
}

