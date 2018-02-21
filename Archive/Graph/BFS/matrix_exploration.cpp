#include <bits/stdc++.h>

typedef long long ll;

const ll INF = std::numeric_limits<ll>::max();

int main() {
    ll n,m,k;
    std::scanf("%lld %lld %lld",&n,&m, &k);

	std::vector<std::vector<char>> grid(n+2, std::vector<char>(m+2, '#'));
	for (ll i = 1; i <= n; ++i)
		for (ll j = 1; j <= m; ++j)
			std::scanf(" %c", &grid[i][j]);

	std::vector<std::pair<ll,ll>> special(k);
	for (auto& e : special)
		std::scanf("%lld %lld",&e.first,&e.second);


	std::vector<std::vector<ll>> best_dist(n, std::vector<ll>(m, INF)), dist(n);

	ll sum = 0;

	for (const auto& sp : special) {
		std::for_each(dist.begin(),dist.end(), [&m](std::vector<ll>& a){
			a.assign(m, INF);
		});

		dist[sp.first-1][sp.second-1] = 0;

		std::queue<std::pair<ll,ll>> order;
		order.push(sp);

		while (!order.empty()) {
			auto best = order.front(); order.pop();

			if (best_dist[best.first-1][best.second-1] > dist[best.first-1][best.second-1]) {
				if (best_dist[best.first-1][best.second-1] != INF)
					sum -= best_dist[best.first-1][best.second-1];
				sum += best_dist[best.first-1][best.second-1] = dist[best.first-1][best.second-1];
			} else if (best_dist[best.first-1][best.second-1] < dist[best.first-1][best.second-1]) {
				break;
			}

			// std::printf("dist to best = %lld\n",dist[best.first-1][best.second-1]);

			ll i,j;

			for (ll i = -1, j = 0; i <= 1; i += 2) {
				if (grid[best.first+i][best.second+j] == '#')
					continue;
				if (dist[best.first+i-1][best.second+j-1] > dist[best.first-1][best.second-1] + 1) {
					dist[best.first+i-1][best.second+j-1] = dist[best.first-1][best.second-1] + 1;
					order.push({best.first+i, best.second+j});
				}
			}

			for (ll j = -1, i = 0; j <= 1; j += 2) {
				if (grid[best.first+i][best.second+j] == '#')
					continue;
				if (dist[best.first+i-1][best.second+j-1] > dist[best.first-1][best.second-1] + 1) {
					dist[best.first+i-1][best.second+j-1] = dist[best.first-1][best.second-1] + 1;
					order.push({best.first+i, best.second+j});
				}
			}
		}
	}

	std::printf("%lld\n",sum);

    return 0;
}
