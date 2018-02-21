#include <bits/stdc++.h>

typedef long long ll;

int main(void) {
	ll n;
	std::scanf("%lld", &n);

	std::vector<std::pair<ll,ll>> vec(100);
	ll s; char t;
	while(n--)
		std::scanf("%lld %c",&s,&t), t == 'L' ? vec[s-1].first++ : vec[s-1].second++;

	ll cnt = 0;
	for (auto& e : vec)
		cnt += std::min(e.first,e.second);

	std::printf("%lld\n",cnt);

	return 0;
}
