#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lg(x) __lg(x)
#define alla(a,n) a+1,a+n+1
#define ll long long

template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 2e5 + 2;
const long long INF = 1e9 + 2;

int n, q;
vector<int> adj[N];

void inp()
{
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

namespace sub1
{
    vector<vector<int>> qry[N];

    int h[N], in[N], out[N], time = 0, euler[N];
    int up[N][21];
    int ans[N];
    void dfs(int u, int p) 
    {
        up[u][0] = p;
        FOR(j, 1, n) up[u][j] = up[up[u][j - 1]][j - 1];
        in[u] = ++time;
        euler[time] = u;
        for(int v : adj[u]) if(v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
        out[u] = time;
    }

    ll st[4 * N], lz[4 * N];
    void down(int id) 
    {
        if(lz[id]) {
            ll val = lz[id]; 
            st[id << 1] += val; st[id << 1 | 1] += val;
            lz[id << 1] += val; lz[id << 1 | 1] += val;
            lz[id] = 0;
        }
    }
    void build(int id, int l, int r) 
    {
        if(l == r) {
            st[id] = h[euler[l]];
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    void upd(int id, int l, int r, int u, int v, ll val) 
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = (r + l) >> 1;
        down(id);
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    ll get(int id, int l, int r, int u, int v) 
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        down(id);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    bool isPar(int x, int y) 
    {
        return in[x] <= in[y] && out[y] <= out[x];
    }
    int getPar(int u, int depth) 
    {
        FORD(j, lg(n), 0) if(depth >> j & 1) u = up[u][j];
        return u;
    }
    void reroot(int u, int p) 
    {
        for(vector<int> vec : qry[u]) {
            int id = vec[0];
            for(int i = 1; i < vec.size(); i++) {
                int x = vec[i];
                if(!isPar(u, x)) {
                    upd(1, 1, n, in[x], out[x], -INF);
                }
                else {
                    int p = getPar(u, h[u] - h[x] - 1);
                    upd(1, 1, n, 1, in[p] - 1, -INF);
                    upd(1, 1, n, out[p] + 1, n, -INF);
                }
            }

            ans[id] = st[1];

            for(int i = 1; i < vec.size(); i++) {
                int x = vec[i];
                if(!isPar(u, x)) {
                    upd(1, 1, n, in[x], out[x], INF);
                }
                else {
                    int p = getPar(u, h[u] - h[x] - 1);
                    upd(1, 1, n, 1, in[p] - 1, INF);
                    upd(1, 1, n, out[p] + 1, n, INF);
                }
            }
        }

        for(int v : adj[u]) if(v != p) {
            upd(1, 1, n, 1, n, 1);
            upd(1, 1, n, in[v], out[v], -2);
            reroot(v, u);
            upd(1, 1, n, 1, n, -1);
            upd(1, 1, n, in[v], out[v], 2);
        }
    }
    void slv()
    {
        dfs(1, 0);
        build(1, 1, n);
        FOR(i, 1, q) {
            int x, k; cin >> x >> k;
            vector<int> vec; vec.push_back(i);
            FOR(j, 1, k) {
                int u; cin >> u;
                vec.push_back(u);
            }
            qry[x].push_back(vec);
        }
        reroot(1, -1);

        FOR(i, 1, q) cout << ans[i] << el;
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "qs"
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

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}