typedef long long ll;
typedef std::vector<std::vector<std::pair<ll,ll>>> adj_list;

static ll dist(const std::pair<ll,ll>& a, const std::pair<ll,ll>& b) {
    return std::abs(a.first-b.first) + std::abs(a.second-b.second);
}

int main(void) {

    ll n,m;
    std::scanf("%lld %lld",&n,&m);

    std::pair<ll,ll> A,B;
    std::scanf("%lld %lld %lld %lld", &A.first,&A.second,&B.first,&B.second);

    ll cnt = 0;
    std::pair<ll,ll> it = {1,1};
    for (; it.first <= n; it.first++)
        for (it.second = 1; it.second <= m; it.second++)
            cnt += dist(it, A) == dist(it, B);

    std::printf("%lld\n",cnt);

    return 0;
}
