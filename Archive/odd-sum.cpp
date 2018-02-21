#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
	ll n;
	std::scanf("%lld",&n);

	ll oc = 0, ec = 0;
	for (ll a; n--; ) {
		std::scanf("%lld",&a);
		a % 2 ? oc++ : ec++;
	}

	std::printf("%lld\n",ec*oc);

	return 0;
}
