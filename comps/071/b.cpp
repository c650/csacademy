#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll,ll> pairll;
typedef std::vector<std::vector<pairll>> adj_list;

int main(void) {

	ll n,m;
	std::scanf("%lld %lld",&n,&m);

	std::vector<std::vector<ll>> matrix(n, std::vector<ll>(m));
	for (auto& r : matrix)
		for (auto& e : r)
			std::scanf("%lld", &e);

	std::vector<std::vector<ll>> balls(n, std::vector<ll>(m,1));

	std::vector<adj_list> graph(n, adj_list(m));
	std::vector<std::vector<ll>> deg(n, std::vector<ll>(m));

	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {

			pairll low = {i,j};
			pairll orig = low;

			for (ll x = -1; x <= 1; ++x) {
				for (ll y = -1; y <= 1; ++y) {
					try {
						ll value = matrix.at(i+x).at(j+y);
						if (value < matrix[low.first][low.second]) {
							low = {i+x, j+y};
						}
					} catch (...) {}
				}
			}

			if (low != orig) {
				graph[i][j].push_back(low);
				// std::printf("edge between %lld %lld and %lld %lld\n", i,j, low.first,low.second);
				deg[low.first][low.second]++;
			}

		}
	}

	std::queue<pairll> order;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			if (deg[i][j] == 0) {
				order.push({i,j});
				// std::printf("pushing %lld %lld\n",i,j);
			}
		}
	}

	// for (const auto& r : balls) {
	// 	for (const auto& e : r) {
	// 		std::printf("%lld ", e);
	// 	}
	// 	std::putchar('\n');
	// }

	while (!order.empty()) {
		pairll best = order.front();
		order.pop();

		for (const auto& neigh : graph[best.first][best.second]) {
			// std::printf("Moving %lld balls from (%lld,%lld) to (%lld,%lld).\n", balls[best.first][best.second], best.first,best.second, neigh.first,neigh.second);
			balls[neigh.first][neigh.second] += balls[best.first][best.second];
			balls[best.first][best.second] = 0;
			if (--deg[neigh.first][neigh.second] == 0) {
				order.push(neigh);
			}
		}
	}

	for (const auto& r : balls) {
		for (const auto& e : r) {
			std::printf("%lld ", e);
		}
		std::putchar('\n');
	}

	return 0;
}

