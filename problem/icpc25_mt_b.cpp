#include <bits/stdc++.h>
using namespace std;

#define     el "\n"
#define     FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     pb push_back
#define     fi first
#define     se second
#define     all(x) x.begin(),x.end()
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     ll long long


template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 1e5 + 2;

int n;
vector<pair<int, int>> adj[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n - 1) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}


namespace sub1
{
    int sz[N];
    bool isCentroid[N];
    void dfs_sz(int u, int p)
    {
        sz[u] = 1;
        for(pair<int, int> x : adj[u]) {
            int v = x.first, w = x.second;
            if(v == p || isCentroid[v]) continue;
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
    }
    int centroid(int u, int p, int n)
    {
        for(pair<int, int> x : adj[u]) {
            int v = x.first;
            if(v == p || isCentroid[v]) continue;
            if(sz[v] > n / 2) return centroid(v, u, n);
        }
        return u;
    }

    ll ans = 0;
    int cnt[30][2];
    void dfs(int u, int p, long long val, int type, bool isDel)
    {
        if(!isDel) {
            if(type) {
                ans += val;
                FOR(i, 0, 26) ans += 1LL * (1LL << i) * cnt[i][(val >> i & 1) ^ 1];
            }
            else {
                FOR(i, 0, 26) cnt[i][val >> i & 1]++;
            }
        }
        else {
            FOR(i, 0, 26) cnt[i][val >> i & 1]--;
        }

        for(auto [v, w] : adj[u]) if(v != p && !isCentroid[v]) {
            dfs(v, u, val ^ w, type, isDel);
        }
    }
    void solve(int u)
    {
        dfs_sz(u, -1);
        int cen = centroid(u, -1, sz[u]);
        isCentroid[cen] = 1;

        for(auto [v, w] : adj[cen]) if(!isCentroid[v]) {
            dfs(v, cen, w, 1, 0);
            dfs(v, cen, w, 0, 0);
        }
        for(auto [v, w] : adj[cen]) if(!isCentroid[v]) {
            dfs(v, cen, w, 1, 1);
        }
        for(auto [v, w] : adj[cen]) if(!isCentroid[v]) {
            solve(v);
        }
    }
    void slv()
    {
        solve(1);
        cout << ans;
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "icpc25_mt_b"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }

    bool qs = 0;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub1 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

