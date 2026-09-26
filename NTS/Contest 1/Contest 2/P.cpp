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

const int N = 5e5 + 2;

int n, q;
struct Queries {
    char type;
    int x;
} qry[N];

vector<int> adj[N];
void inp()
{
    cin >> q;
    n = 1;
    FOR(i, 1, q) {
        char type; int x;
        cin >> type >> x;
        qry[i] = {type, x};
        if(type == 'A') adj[x].push_back(++n), qry[i].x = n;
    }
}

namespace sub1
{
    int sz[N], h[N], par[N];
    void dfs(int u, int p) 
    {
        sz[u] = 1;
        for(int v : adj[u]) if(v != p) {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

    struct SegmentTree {
        int st[4 * N], lz[4 * N];

        void down(int id, int l, int mid, int r) 
        {
            if(lz[id]) {
                int val = lz[id];
                st[id << 1] += (mid - l + 1) * val;
                st[id << 1 | 1] += (r - mid) * val;
                lz[id << 1] += val; lz[id << 1 | 1] += val;
                lz[id] = 0;
            }
        }
        void upd(int id, int l, int r, int u, int v, int val) 
        {
            if(r < u || v < l) return;
            if(u <= l && r <= v) {
                st[id] += (r - l + 1) * val;
                lz[id] += val;
                return;
            }
            int mid = (r + l) >> 1;
            down(id, l, mid, r);
            upd(id << 1, l, mid, u, v, val);
            upd(id << 1 | 1, mid + 1, r, u, v, val);
            st[id] = st[id << 1] + st[id << 1 | 1];
        }
        int get(int id, int l, int r, int pos) 
        {
            if(pos > r || pos < l) return 0;
            if(l == r) return st[id];
            int mid = (r + l) >> 1;
            down(id, l, mid, r);
            return get(id << 1, l, mid, pos) + get(id << 1 | 1, mid + 1, r, pos);
        }
        int walk(int id, int l, int r, int u, int v, int val) 
        {
            if(r < u || v < l || st[id] < val) return -1;
            if(l == r) return l;
            int mid = (r + l) >> 1;
            int res = walk(id << 1 | 1, mid + 1, r, u, v, val);
            if(res != -1) return res;
            return walk(id << 1, l, mid, u, v, val);
        }
    } itSum, itCut;

    int head[N], chainID[N], mtc = 1, pos[N], euler[N], time = 0, in[N], out[N];

    void hld(int u, int p) 
    {
        if(!head[mtc]) {
            head[mtc] = u;
        }
        chainID[u] = mtc;

        euler[++time] = u;
        pos[u] = time;
        in[u] = time;

        int ma = 0;

        for(int v : adj[u]) if(v != p) {
            if(!ma || sz[v] > sz[ma]) ma = v;
        }
        if(ma) hld(ma, u);
        for(int v : adj[u]) if(v != u && v != ma) {
            mtc++;
            hld(v, u);
        }
        out[u] = time;
    }

    void updAdd(int x) 
    {
        while(chainID[x] != chainID[1]) {
            int far = itCut.walk(1, 1, n, pos[head[chainID[x]]], pos[x], 1);
            itSum.upd(1, 1, n, far != -1 ? far : pos[head[chainID[x]]], pos[x], 1);
            if(far != -1) return;
            x = par[head[chainID[x]]];
        }
        int far = itCut.walk(1, 1, n, 1, pos[x], 1);
        itSum.upd(1, 1, n, far != -1 ? far : 1, pos[x], 1);
    }
    void updCut(int x) 
    {
        itCut.upd(1, 1, n, pos[x], pos[x], 1);

        int val = itSum.get(1, 1, n, pos[x]);
        x = par[x];
        while(chainID[x] != chainID[1]) {
            int far = itCut.walk(1, 1, n, pos[head[chainID[x]]], pos[x], 1);
            itSum.upd(1, 1, n, far != -1 ? far : pos[head[chainID[x]]], pos[x], -val);
            if(far != -1) return;
            x = par[head[chainID[x]]];
        }
        int far = itCut.walk(1, 1, n, 1, pos[x], 1);
        itSum.upd(1, 1, n, far != -1 ? far : 1, pos[x], -val);
    }
    int getAns(int x) 
    {
        return itSum.get(1, 1, n, pos[x]);
    }
    void slv()
    {
        dfs(1, 0); 
        hld(1, 0); 
        itSum.upd(1, 1, n, pos[1], pos[1], 1);
        FOR(t, 1, q) {
            char type = qry[t].type;
            int x = qry[t].x;
            // cout << t << " " << type << endl;
            if(type == 'A') {
                updAdd(x);
            }
            else if(type == 'C') {
                updCut(x);
            }
            else {
                cout << getAns(x) << el;
            }
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