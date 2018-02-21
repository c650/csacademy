#include <bits/stdc++.h>

typedef long long ll;

static ll holes(const ll& a) {
	ll ret = 0;
	for (ll t = a, i; t; t /= 10) {
		i = t % 10;
		if (i == 8)
			ret+=2;
		if (i == 0 || i == 6 || i == 9)
			ret++;
	}
	return ret;
}

int main(void) {

	ll a,b;
	std::scanf("%lld %lld",&a,&b);

	ll best = a;
	ll best_c = holes(a);

	for (ll i = a+1; i <= b; ++i) {
		ll tmp = holes(i);
		if (tmp > best_c) {
			best = i;
			best_c = tmp;
		}
	}

	std::printf("%lld\n", best);

	return 0;
}

