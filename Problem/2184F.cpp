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

int n;
vector<int> adj[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) adj[i].clear();
    FOR(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}


namespace sub1
{
    int dp[N][3], f[N][3];
    vector<int> vec;
    void dfs(int u, int p)
    {
        dp[u][1] = 1;
        vec.clear();
        for(int v : adj[u]) if(v != p) {
            dfs(v, u);
            vec.push_back(v);
        }
        f[0][0] = 1;
        for(int i = 0; i < vec.size() - 1; i++) {
            FOR(j, 0, 2) if(f[i][j]) {
                int v = vec[i + 1];
                FOR(k, 0, 2) if(dp[v][k]) {
                    f[i + 1][(j + k) % 3] = 1;
                }
            }
        }
        if(adj[u].size() > 1) {
            FOR(x, 0, 2) dp[u][x] |= f[vec.size() - 1][x];
        }
    }
    void slv()
    {
        memset(dp, 0, sizeof dp);
        memset(f, 0, sizeof f);
        dfs(1, 0);
        cout << (dp[1][0] ? "YES" : "NO") << el;
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

    bool qs = 1;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub1 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

