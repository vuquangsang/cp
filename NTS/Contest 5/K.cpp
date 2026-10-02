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

const int N = 5e4 + 2;

int n, q, a[N];
vector<int> adj[N];

void inp()
{   
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

namespace sub1
{
    const int BLOCK = 215;

    int in[N], out[N], timer = 0, euler[N];
    int up[N][21], h[N];
    void dfs(int u, int p) 
    {
        in[u] = ++timer;
        euler[timer] = u;

        up[u][0] = p;
        FOR(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : adj[u]) if(v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
        out[u] = timer;
    }
    int LCA(int u, int v) 
    {
        if(h[u] < h[v]) swap(u, v);
        FORD(j, lg(n), 0) if(h[up[u][j]] >= h[v]) {
            u = up[u][j];
        }
        if(u == v) return u;
        FORD(j, lg(n), 0) if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
        return up[u][0];
    }
    int cnt[N];
    int ans, SZ;
    void add(int u) 
    {
        cnt[a[u]]++;
        if(cnt[a[u]] * 2 > SZ) ans = a[u];
    }

    vector<int> vec;

    int sum[N][BLOCK + 10];
    void dfsAdd(int u, int p, int id, int color) 
    {
        sum[u][id] = sum[p][id];
        if(a[u] == color) sum[u][id]++;
        for(int v : adj[u]) if(v != p) {
            dfsAdd(v, u, id, color);
        }
    }
    void del(int l, int r) 
    {
        FOR(i, l, r) cnt[a[euler[i]]]--;
    }
    int pre[N][BLOCK + 10];

    int dist(int x, int y) 
    {
        return h[x] + h[y] - 2 * h[LCA(x, y)];
    }
    void slv()
    {        
        FOR(i, 1, n) {
            cnt[a[i]]++;
            if(cnt[a[i]] == BLOCK) vec.push_back(a[i]);
        }
        FOR(i, 1, n) cnt[i] = 0;

        dfs(1, 0);

        FOR(i, 0, vec.size() - 1) {
            dfsAdd(1, 0, i, vec[i]);
        }
        FOR(i, 0, vec.size() - 1) {
            int color = vec[i];
            FOR(j, 1, n) {
                pre[j][i] = pre[j - 1][i] + (color == a[euler[j]]);
            }
        }

        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int u; cin >> u;

                ans = -1;
                SZ = out[u] - in[u] + 1;
                if(SZ < BLOCK * 2) {
                    FOR(i, in[u], out[u]) add(euler[i]); 
                    del(in[u], out[u]);
                }
                else {
                    for(int i = 0; i < vec.size(); i++) {
                        if((pre[out[u]][i] - pre[in[u] - 1][i]) * 2 > SZ) {
                            ans = vec[i];
                            break;
                        }
                    }
                }
                cout << ans << el;
            }
            else if(type == 2) {
                int u; cin >> u;

                ans = -1;
                int l = in[u], r = out[u];
                SZ = n - (r - l + 1);
                if(SZ < BLOCK * 2) {
                    FOR(i, 1, l - 1) add(euler[i]);
                    FOR(i, r + 1, n) add(euler[i]);
                    del(1, l - 1); del(r + 1, n);
                }
                else {
                    for(int i = 0; i < vec.size(); i++) {
                        int vals = pre[l - 1][i] + pre[n][i] - pre[r][i];
                        if(vals * 2 > SZ) {
                            ans = vec[i];
                            break;
                        }
                    } 
                }
                cout << ans << el;
            }
            else {
                int u, v; cin >> u >> v;
                ans = -1;
                SZ = dist(u, v) + 1;
                int p = LCA(u, v);

                if(SZ < BLOCK * 2) {
                    int x = u, y = v;
                    while(x != p) add(x), x = up[x][0];
                    while(y != p) add(y), y = up[y][0];
                    add(p);
                    x = u, y = v;
                    while(x != p) cnt[a[x]]--, x = up[x][0];
                    while(y != p) cnt[a[y]]--, y = up[y][0];
                    cnt[a[p]]--;
                }
                else {
                    for(int i = 0; i < vec.size(); i++) {
                        int vals = sum[u][i] + sum[v][i] - 2 * sum[p][i] + (vec[i] == a[p]);
                        if(vals * 2 > SZ) {
                            ans = vec[i];
                            break;
                        }
                    }
                }

                cout << ans << el;
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