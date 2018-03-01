#include <bits/stdc++.h>

typedef long long ll;

const ll INF = 1'000'000'000;

std::map<ll,ll> freq;

struct bg_data {
	ll num;

	bool operator<(const bg_data& o) const {
		return freq[num] < freq[o.num] || freq[num] == freq[o.num] && num < o.num;
	}
};

int main(void) {

	ll n;
	std::scanf("%lld",&n);

	std::set<bg_data> bg_info;
	std::set<ll, std::greater<ll>> stuff;

	for (ll i = 0,tmp; i < n; ++i) {
		std::scanf("%lld",&tmp);
		if (freq[tmp]++ == 0) {
			bg_info.insert({tmp});
			stuff.insert(tmp);
		}
	}

	ll ans = 0;

	for (auto& curr : stuff) {
		std::printf("%lld\n",curr);

		// auto it = bg_info.lower_bound({curr});

		// if (it != bg_info.end()) {
		// 	std::printf("lb for %lld is %lld\n", curr, it->num);
		// } else {
		// 	std::printf("%lld has no lb\n", curr);
		// }

		auto it = bg_info.upper_bound({curr});

		if (it != bg_info.end() && freq[it->num] > freq[curr] && it->num < curr) {
			std::printf("hb for %lld is %lld\n", curr, it->num);
			ll cpy = it->num;

			while (freq[cpy] > freq[curr] && freq[curr] > 0) {
				freq[cpy] += 2;
				freq[curr]--;
				++ans;
			}

			bg_info.erase(it);
			bg_info.insert({cpy});
		} else {
			std::printf("%lld has no hb\n", curr);
		}
	}

	std::printf("%lld\n",ans);


	return 0;
}

