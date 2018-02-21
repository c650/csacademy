#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
	ll a,b;
	std::scanf("%lld %lld",&a,&b);

	ll cnt = 0;
	for (ll i = 1; i*i <= b; ++i) {
		cnt += (i*i) >= a;
	}

	std::printf("%lld\n",cnt);

	return 0;
}
