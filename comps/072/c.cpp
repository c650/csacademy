#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;

matrix mat_n, mat_t;

static ll go_rows(const matrix& A, const bool& yass) {
	const matrix& mat = yass ? mat_n : mat_t;

	ll tot = 0;
	std::vector<ll> crt(A.size(), 0);
	for (ll i = 0; i < A.size(); ++i) {
		for (ll j = 0; j < A[i].size(); ++j)
			crt[i] += A[i][j] * mat[i][j];
		tot += crt[i];
	}

	std::vector<ll> opp_rt(A.size(), 0);
	for (ll i = 0; i < A.size(); ++i) {
		for (ll j = 0; j < A[i].size(); ++j) {
			opp_rt[i] += A[i][j] * mat[i == 0 || i + 1 == A.size() ? 1 : 0][j];
		}
	}


	ll max = tot;
	for (ll j = 1; j + 1 < A.size(); ++j) {
		max = std::max(max, tot + opp_rt[0] - crt[0] + opp_rt[j] - crt[j]);
		max = std::max(max, tot + opp_rt[A.size()-1] - crt[A.size()-1] + opp_rt[j] - crt[j]);
	}

	return max;
}

int main(void) {

    ll n,m;
    std::scanf("%lld %lld",&n,&m);

    matrix A(n, std::vector<ll>(m));
	matrix A_t(m, std::vector<ll>(n));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			std::scanf("%lld",&A[i][j]);
			A_t[j][i] = A[i][j];
		}
	}

	mat_n.assign(n, std::vector<ll>(m));
	for (ll i = 0; i + 1 < n; ++i) {
		for (ll j = 0; j + 1 < m; ++j) {
			mat_n[i][j]++;
			mat_n[i+1][j]++;
			mat_n[i][j+1]++;
			mat_n[i+1][j+1]++;
		}
	}


	mat_t.assign(m, std::vector<ll>(n));
	for (ll i = 0; i < m; ++i) {
		for (ll j = 0; j < n; ++j) {
			mat_t[i][j] = mat_n[j][i];
		}
	}

	std::printf("%lld\n",std::max(go_rows(A,true),go_rows(A_t,false)));

    return 0;
}
