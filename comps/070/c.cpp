#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

const ll INF = 1'000'000'000;
const ll MAX_WEIGHT = 10'000'000;

std::vector<ll> heads;

static ll find(const ll& a) {
	ll i;
	for (i = a; heads[i] != i; i = heads[i]);
	return heads[a] = i;
}

static ll do_union(const ll& a, const ll& b) {
	if (a == b) return 0;
	ll aa = find(a);
	ll bb = find(b);
	if (aa == bb) return 0;

	heads[std::max(aa,bb)] = std::min(aa,bb);

	return 1;
}

int main(void) {

	ll n,m;
	std::scanf("%lld %lld",&n,&m);

	std::vector<std::vector<ll>> adj_mat(n, std::vector<ll>(n, INF));
	adj_list graph(n);
	bool good = true;

	for (ll i = 0,a,b,c; i < m; ++i) {
		std::scanf("%lld %lld %lld",&a,&b,&c);
		--a;--b;

		if (adj_mat[a][b] != INF) {
			good = good && c == adj_mat[a][b];
			continue;
		}

		adj_mat[a][b] = adj_mat[b][a] = c;
		graph[a].push_back({b,c});
	}

	for (ll k = 0; k < n; ++k) {
		for (ll i = 0; i < n; ++i) {
			for (ll j = 0; j < n; ++j) {
				if (adj_mat[i][k] == INF || adj_mat[k][j] == INF) continue;
				if (adj_mat[i][j] == INF) continue;
				// if some path exists that's better than the shortest distance, graph no work.
				good = good && (adj_mat[i][k] + adj_mat[k][j] >= adj_mat[i][j]);
			}
		}
	}

	if (!good) {
		std::printf("-1\n");
		return 0;
	}

	heads.resize(n);
	for (ll i = 0; i < n; ++i)
		heads[i] = i;

	for (ll i = 0; i < n; ++i) {
		for (const auto& neigh : graph[i]) {
			do_union(i, neigh.first);
		}
	}

	for (;;) {
		// compress the heads
		ll head_a = find(0);
		ll other;
		for (other = 0; other < n; ++other) {
			if (find(other) != head_a && adj_mat[0][other] == INF)
				break;
		}

		if (other >= n) break;

		do_union(0, other);
		graph[0].push_back({other, MAX_WEIGHT});
		adj_mat[0][other] = adj_mat[other][0] = MAX_WEIGHT;
	}

	ll edges = 0;
	for (ll i = 0; i < n; ++i) {
		edges += graph[i].size();
	}

	std::printf("%lld\n",edges);
	for (ll i = 0; i < n; ++i) {
		for (const auto& neigh : graph[i]) {
			std::printf("%lld %lld %lld\n", i+1, 1+neigh.first,neigh.second);
		}
	}

	return 0;
}

