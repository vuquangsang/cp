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

const int N = 2e5 + 2;

int n, m, k;
vector<int> adj[N];

void inp()
{
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}


namespace sub1
{
    int num[N], low[N], time = 0;
    int numComp = 0, comp[N], szComp[N];
    deque<int> dq;
    void tarjan(int u, int p)
    {
        num[u] = low[u] = ++time;
        dq.push_back(u);
        bool ok = 0;
        for(int v : adj[u]) {
            if(v == p && !ok) {
                ok = 1;
                continue;
            }
            if(num[v]) mini(low[u], num[v]);
            else {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
            }
        }
        if(num[u] == low[u]) {
            int nxt;
            numComp++;
            do {
                nxt = dq.back(); dq.pop_back();
                comp[nxt] = numComp;
                szComp[numComp]++;
            } while(nxt != u);
        }
    }

    vector<int> g[N];

    bool isCentroid[N];
    int sz[N];

    void dfs_sz(int u, int p)
    {
        sz[u] = 1;
        for(int v : g[u]) if(v != p && !isCentroid[v]) {
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
    }
    int centroid(int u, int p, int n)
    {
        for(int v : g[u]) if(v != p && !isCentroid[v]) {
            if(sz[v] > n / 2) return centroid(v, u, n);
        }
        return u;
    }
    int getId(int x)
    {
        return x + 1;
    }
    int bit[N];

    void upd(int x, int v)
    {
        for(; x >= 1; x -= x & -x) bit[x] += v;
    }
    int get(int x)
    {
        int ans = 0;
        for(; x <= n + 1; x += x & -x) ans += bit[x];
        return ans;
    }

    ll ans = 0;
    void dfs(int u, int p, int depth, int type, bool isDel)
    {
        if(!isDel) {
            if(type) {
                ans += 1LL * szComp[u] * get(getId(max(0, k - depth)));
            }
            else {
                upd(getId(depth), szComp[u]);
            }
        }
        else {
            upd(getId(depth), -szComp[u]);
        }

        for(int v : g[u]) if(v != p && !isCentroid[v]) {
            dfs(v, u, depth + 1, type, isDel);
        }
    }
    void solve(int u)
    {
        dfs_sz(u, -1);
        int cen = centroid(u, -1, sz[u]);
        isCentroid[cen] = 1;

        upd(getId(0), szComp[cen]);
        for(int v : g[cen]) if(!isCentroid[v]) {
            dfs(v, cen, 1, 1, 0);
            dfs(v, cen, 1, 0, 0);
        }
        upd(getId(0), -szComp[cen]);
        for(int v : g[cen]) if(!isCentroid[v]) {
            dfs(v, cen, 1, 1, 1);
        }

        for(int v : g[cen]) if(!isCentroid[v]) {
            solve(v);
        }

    }
    void slv()
    {
        tarjan(1, 0);

        FOR(u, 1, n) for(int v : adj[u]) if(comp[u] < comp[v]) {
            g[comp[u]].push_back(comp[v]);
            g[comp[v]].push_back(comp[u]);
        }
        solve(1);

        cout << ans;
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "bgtravel"
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

