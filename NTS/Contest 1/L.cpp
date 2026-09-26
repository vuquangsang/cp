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

const int N = 8e5 + 2;

struct Edge {
    int x, y;
} E[N];
struct Queries {
    int type, x;
} qry[N];

int n, m, q, a[N];
bool used[N];
void inp()
{
    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        int x, y; cin >> x >> y;
        E[i] = {x, y};
    }
    FOR(i, 1, q) {
        int type, u;
        cin >> type >> u;
        qry[i] = {type, u};
        if(type == 2) {
            used[u] = 1;
        }
    }
}

namespace sub1
{
    vector<int> adj[N];
    struct DSU {
        int par[N];
        void reset()
        {
            FOR(i, 1, n) par[i] = i;
        }
        int root(int x)
        {
            return par[x] == x ? x : par[x] = root(par[x]);
        }
        bool joint(int x, int y)
        {
            x = root(x); y = root(y);
            if(x == y) return 0;
            ++n;
            par[n] = n;
            par[x] = par[y] = n;
            adj[n].push_back(x);
            adj[n].push_back(y);
            return 1;
        }
    } dsu;

    int root[N];

    int in[N], out[N], time = 0;
    void dfs(int u, int p)
    {
        in[u] = ++time;
        for(int v : adj[u]) if(v != p) {
            dfs(v, u);
        }
        out[u] = time;
    }

    pair<int, int> st[4 * N];

    pair<int, int> Merge(pair<int, int> a, pair<int, int> b)
    {
        pair<int, int> res;
        res.second = a.first > b.first ? a.second : b.second;
        res.first = max(a.first, b.first);
        return res;
    }
    void upd(int id, int l, int r, int i, int pos, int val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st[id] = {val, pos};
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid, i, pos, val);
        upd(id << 1 | 1, mid + 1, r, i, pos, val);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }

    pair<int, int> get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return {0, 0};
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        return Merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    void slv()
    {
        int tempN = n;
        dsu.reset();
        FOR(i, 1, m) if(!used[i]) {
            dsu.joint(E[i].x, E[i].y);
        }
        FORD(i, q, 1) {
            if(qry[i].type == 1) {
                int x = qry[i].x;
                root[i] = dsu.root(x);
            }
            else {
                int id = qry[i].x;
                auto [x, y] = E[id];
                dsu.joint(x, y);
            }
        }
        FORD(i, n, 1) if(!in[i]) dfs(i, -1);

        FOR(i, 1, tempN) upd(1, 1, n, in[i], i, a[i]);

        FOR(i, 1, q) if(qry[i].type == 1){
            int p = root[i];
            pair<int, int> res = get(1, 1, n, in[p], out[p]);
            upd(1, 1, n, in[res.se], 0, 0);
            cout << res.fi << el;
        }
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