#include <bits/stdc++.h>

#define FI first
#define SE second

typedef long long ll;
typedef std::pair<ll,ll> pairll;

std::vector<ll> degree;
std::vector<ll> next;
std::vector<char> visited;
// std::vector<ll> memo;

// static ll go(const ll& curr) {
// 	if (memo[curr] != -1) {
// 		return memo[curr];
// 	}

// 	if (visited[curr]) {
// 		return 0;
// 	}

// 	visited[curr] = true;
// 	ll ret = 1 + go(next[curr]);
// 	visited[curr] = false;

// 	return memo[curr] = ret;
// }

int main(void) {

	ll n;
    std::scanf("%lld",&n);

    degree.assign(n,0);
	next.assign(n,0);
	visited.assign(n,false);
	// memo.assign(n,-1);

    for (ll i = 0, tmp; i < n; ++i) {
        std::scanf("%lld",&tmp);
        next[i] = --tmp;
        degree[tmp]++;
    }

	std::queue<ll> order;
	ll mdi = 0;
	for (ll i = 0; i < n; ++i) {
		if (degree[i] == 0) {
			order.push(i);
		}
		if (degree[mdi] > degree[i])
			mdi = i;
	}

	if (degree[mdi] != 0)
		order.push(mdi);

	std::vector<pairll> path;
	while (!order.empty()) {
		ll curr = order.front();
		order.pop();

		if (!visited[next[curr]]) {
			visited[next[curr]] = true;
			path.push_back({curr, next[curr]});
			if (--degree[next[curr]] == 0 || order.empty()) {
				order.push(next[curr]);
			}
		}
	}

	visited.assign(n, false);

	for (ll i = path.size()-1; i >= 0; --i) {
		if (visited[path[i].FI]) continue;
		visited[path[i].SE] = true;
		std::printf("%lld %lld\n",path[i].FI+1, path[i].SE+1);
	}

	// ll best_node, best_len;
	// bool unset = true;
	// for (ll i = 0; i < n; ++i) {
	// 	ll tmp = go(i);
	// 	if (unset || best_len < tmp) {
	// 		best_len = tmp;
	// 		best_node = i;
	// 		unset = false;
	// 	}
	// }

	// visited.assign(n, false);
	// std::vector<pairll> path;
	// for (ll curr = best_node; !visited[next[curr]]; curr = next[curr]) {
	// 	visited[curr] = true;
	// 	path.push_back({curr, next[curr]});
	// }

	return 0;
}
