#include <bits/stdc++.h>

typedef long long ll;

std::vector<std::vector<char>> matrix;


int main(void) {

	ll n,m;
	std::scanf("%lld %lld",&n,&m);

	matrix.assign(n, std::vector<char>(m));
	for (auto& r : matrix)
		for (auto& e : r)
			std::scanf(" %c",&e), e -= '0';

	std::vector<std::vector<ll>> left(n, std::vector<ll>(m, 0));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			left[i][j] = matrix[i][j];
		}
	}

	for (ll i = 0; i < n; ++i) {
		for (ll j = 1; j < m; ++j) {
			if (matrix[i][j-1] && matrix[i][j])
				left[i][j] += left[i][j-1];
		}
	}

	std::vector<std::vector<ll>> down(n, std::vector<ll>(m, 0));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			down[i][j] = matrix[i][j];
		}
	}

	for (ll j = 0; j < m; ++j) {
		for (ll i = n-2; i >= 0; --i) {
			if (matrix[i+1][j] && matrix[i][j])
				down[i][j] += down[i+1][j];
		}
	}

	ll max = 0;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j + 1 < m; ++j) {
			if (matrix[i][j] && matrix[i][j+1]) {
				if (max < left[i][j] + down[i][j+1] && down[i][j+1] > 1) {
					max = left[i][j] + down[i][j+1];
					// std::printf("%lld %lld\n", i,j);
				}
			}
		}
	}

	std::printf("%lld\n",max);

	return 0;
}

