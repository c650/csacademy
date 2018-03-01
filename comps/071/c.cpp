#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

int main(void) {

	ll n;
	std::scanf("%lld",&n);

	std::vector<char> nums(n);
	for (auto& e : nums) {
		int tmp;
		std::scanf("%d",&tmp);
		e = tmp == 0 ? 1 : -1;
	}

	std::bitset<300'003> bloom;
	bloom[0 + bloom.size()/2] = true;

	ll sum = 0;
	for (ll j = 0; j < n; ++j) {
		sum += nums[j];
		bloom[sum + bloom.size()/2] = true;
	}

	auto orig = bloom;
	for (ll i = 0; i+1 < n; ++i) {

		std::printf("%lld:: \n", i);
		for (ll i = 0; i < bloom.size(); ++i) {
			if (bloom[i]) {
				std::printf("can make: %lld\n", i - bloom.size()/2);
			}
		}

		if (nums[i] == 1) {
			orig >>= 1;
		} else {
			orig <<= 1;
		}
		bloom |= orig;
	}

	std::printf("%lu\n",bloom.count());

	return 0;
}

